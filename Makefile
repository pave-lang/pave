ASAN ?= 0

ifeq ($(ASAN),1)
	OPT := -g -O0
	SAN := -fsanitize=address -fno-omit-frame-pointer
else
	OPT := -g -O2
	SAN :=
endif

ifeq ($(OS),Windows_NT)
	CLANG_ARGS := -I"C:/Program Files/LLVM/include"
	GEN_FLAGS := std=src/std analyzer=src/analyzer -- $(CLANG_ARGS)
	CFLAGS := -std=c99 -Wall -D_CRT_SECURE_NO_WARNINGS -I"C:/Program Files/LLVM/include"
	LDFLAGS := -L"C:/Program Files/LLVM/lib" -llibclang
	EXE := .exe
	DIST_COPY := build/2/pavec$(EXE) build/2/pavec.pdb
else ifeq ($(shell uname -s),Darwin)
	LLVM_PREFIX := $(shell brew --prefix llvm 2>/dev/null || echo /opt/homebrew/opt/llvm)
	SDK_PATH := $(shell xcrun --show-sdk-path)
	CLANG_ARGS := -isysroot "$(SDK_PATH)" -I"$(LLVM_PREFIX)/include"
	GEN_FLAGS := std=src/std analyzer=src/analyzer -- $(CLANG_ARGS)
	CFLAGS := -std=c99 -Wall -I"$(LLVM_PREFIX)/include" $(SAN)
	LDFLAGS := -L"$(LLVM_PREFIX)/lib" -lclang -Wl,-rpath,"$(LLVM_PREFIX)/lib" $(SAN)
	EXE :=
	DIST_COPY := build/2/pavec$(EXE)
else
	CLANG_ARGS := -I"/lib/llvm-20/include"
	GEN_FLAGS := std=src/std analyzer=src/analyzer -- $(CLANG_ARGS)
	CFLAGS := -std=c99 -Wall -I"/lib/llvm-20/include" $(SAN)
	LDFLAGS := -L"/lib/llvm-20/lib" -lclang $(SAN)
	EXE :=
	DIST_COPY := build/2/pavec$(EXE)
endif

.PHONY: all bootstrap test test-build test-run ls ls-release examples clean dist-compiler
.DEFAULT_GOAL := all

# Build dist/pavec from the pre-generated C sources in dist/src, but only if
# the executable doesn't already exist (e.g. a fresh non-Windows checkout).
dist/pavec$(EXE):
	@$(MAKE) dist-compiler --no-print-directory

# Normal day-to-day build: regenerate and recompile dist/pavec using the
# existing dist/pavec (single stage, no self-hosting verification or tests),
# then build the language server. Use `bootstrap` for the full self-hosted
# rebuild with verification and tests.
all: dist/pavec$(EXE)
	@echo "=== Building dist/pavec ==="
	@$(MAKE) -f Makefile.build GENERATOR=dist/pavec$(EXE) BUILD_DIR=build/dist TARGET=dist/pavec$(EXE) GEN_FLAGS='compiler=src/compiler $(GEN_FLAGS) -I./src/compiler' CFLAGS='$(OPT) $(CFLAGS) -I./src/compiler' LDFLAGS='$(OPT) $(LDFLAGS) ./src/compiler/fs.c' --no-print-directory
	@echo ""
	@echo "=== Building language server ==="
	@$(MAKE) ls --no-print-directory

bootstrap: dist/pavec$(EXE)
	@echo "=== Stage 1: Building with dist/pavec ==="
	@$(MAKE) -f Makefile.build GENERATOR=dist/pavec$(EXE) BUILD_DIR=build/1 TARGET=build/1/pavec$(EXE) GEN_FLAGS='compiler=src/compiler $(GEN_FLAGS) -I./src/compiler' CFLAGS='$(OPT) $(CFLAGS) -I./src/compiler' LDFLAGS='$(OPT) $(LDFLAGS) ./src/compiler/fs.c' --no-print-directory
	@echo ""
	@echo "=== Stage 2: Building with build/1/pavec ==="
	@# From empty: files an earlier build generated would fail the stage 3 diff and be copied to dist.
	@rm -rf build/2/src
	@$(MAKE) -f Makefile.build GENERATOR=build/1/pavec$(EXE) BUILD_DIR=build/2 TARGET=build/2/pavec$(EXE) GEN_FLAGS='compiler=src/compiler $(GEN_FLAGS) -I./src/compiler' CFLAGS='$(OPT) $(CFLAGS) -I./src/compiler' LDFLAGS='$(OPT) $(LDFLAGS) ./src/compiler/fs.c' --no-print-directory
	@echo ""
	@echo "=== Stage 3: Generating sources with build/2/pavec (verification) ==="
	@rm -rf build/3/src
	@mkdir -p build/3/src
	build/2/pavec -o build/3/src compiler=src/compiler $(GEN_FLAGS) -I./src/compiler > /dev/null
	@echo ""
	@echo "=== Verifying Stage 2 and Stage 3 are identical ==="
	@if diff -r build/2/src build/3/src > /dev/null 2>&1; then \
		echo "Verification passed: Generated source files are identical"; \
	else \
		echo "Verification FAILED: Generated source files differ"; \
		exit 1; \
	fi
	@echo ""
	@echo "=== Building and running tests with build/2/pavec ==="
	@$(MAKE) test-run TEST_GENERATOR=build/2/pavec$(EXE) TEST_DIR=build/2-test --no-print-directory
	@echo ""
	@echo "=== Building language server ==="
	@$(MAKE) ls --no-print-directory
	@echo ""
	@echo "=== Copying final build to dist ==="
	rm -rf dist/src
	cp -r $(DIST_COPY) build/2/src dist/
	@echo ""
	@echo "Bootstrap complete!"

# Tests: the same sources built with --test make a program whose main runs
# every `test` block, each in its own process, and reports TAP. TEST_ARGS is
# passed to it: filters (a substring of "module: description"), --exact to
# match a whole name or test id, --list, --in-process (to debug a test).
#   make test TEST_ARGS="--exact test_str__eq___equal_strings"
# `make test-build` only builds build/tests/tests, for an editor to run.
TEST_GENERATOR ?= dist/pavec$(EXE)
TEST_DIR ?= build/tests
TEST_ARGS ?=

test: dist/pavec$(EXE)
	@$(MAKE) test-run --no-print-directory

test-build: dist/pavec$(EXE)
	@$(MAKE) -f Makefile.build GENERATOR=$(TEST_GENERATOR) BUILD_DIR=$(TEST_DIR) TARGET=$(TEST_DIR)/tests$(EXE) GEN_FLAGS='--test compiler=src/compiler $(GEN_FLAGS) -I./src/compiler' CFLAGS='$(OPT) $(CFLAGS) -I./src/compiler' LDFLAGS='$(OPT) $(LDFLAGS) ./src/compiler/fs.c' --no-print-directory

test-run: test-build
	$(TEST_DIR)/tests$(EXE) $(TEST_ARGS)

ls:
	@$(MAKE) -f Makefile.build GENERATOR=dist/pavec$(EXE) BUILD_DIR=build/ls TARGET=dist/pavels$(EXE) GEN_FLAGS='language_server=src/language_server $(GEN_FLAGS) -I./src/language_server -I./src/compiler' CFLAGS='$(OPT) $(CFLAGS) -I./src/language_server -I./src/compiler' LDFLAGS='$(OPT) $(LDFLAGS) ./src/compiler/fs.c' --no-print-directory

# Always unsanitized, regardless of ASAN.
ls-release:
	@$(MAKE) -f Makefile.build GENERATOR=dist/pavec$(EXE) BUILD_DIR=build/lsr TARGET=build/lsr/pavels$(EXE) GEN_FLAGS='language_server=src/language_server $(GEN_FLAGS) -I./src/language_server -I./src/compiler' CFLAGS='-O2 $(filter-out $(SAN),$(CFLAGS)) -I./src/language_server -I./src/compiler' LDFLAGS='$(filter-out $(SAN),$(LDFLAGS)) ./src/compiler/fs.c' --no-print-directory

# Rebuild the stage-0 compiler from the pre-generated C sources in dist/src.
# Needed once on a fresh non-Windows checkout, where dist only ships pavec.exe.
dist-compiler:
	@mkdir -p build/dist-bootstrap
	find dist/src -name '*.c' > build/dist-bootstrap/files.lst
	echo src/compiler/fs.c >> build/dist-bootstrap/files.lst
	clang -O1 $(filter-out -fsanitize=address -fno-omit-frame-pointer,$(CFLAGS)) -Idist/src -Isrc/compiler @build/dist-bootstrap/files.lst $(filter-out -fsanitize=address -fno-omit-frame-pointer,$(LDFLAGS)) -o dist/pavec$(EXE)
	@echo "Built dist/pavec"

define build_example
	dist/pavec$(EXE) std=src/std $(1)=examples/$(1) -o examples --no-line-directives $(2) -- $(CLANG_ARGS) -Iexamples/$(1)
	rm -rf examples/$(1)/out
	mkdir -p examples/$(1)/out
	mv examples/$(1)/*.c examples/$(1)/*.h examples/$(1)/out/
endef

examples:
	$(call build_example,coroutine)
	$(call build_example,slice)
	$(call build_example,enum)
	$(call build_example,iterators)
	$(call build_example,structs)
	$(call build_example,query)
	$(call build_example,query_refs)
	$(call build_example,traits)
	$(call build_example,dynamic_fn)
	$(call build_example,cpp)
	mv examples/cpp/*.cpp examples/cpp/out/
	$(call build_example,ops)
	$(call build_example,optional_access)
	$(call build_example,format)
	$(call build_example,tests,--test)
	mv examples/pave_test_main.c examples/tests/out/

clean:
	@echo "Cleaning build artifacts..."
	rm -rf build
	@echo "Clean complete"
