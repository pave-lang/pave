# clang ./dist/src/*.c -o ./dist/pavec.exe -I"C:/Program Files/LLVM/include" -D_CRT_SECURE_NO_WARNINGS -L"C:/Program Files/LLVM/lib" -llibclang
# clang-20 ./dist/src/*.c -o ./dist/pavec -I"/lib/llvm-20/include" -L"/lib/llvm-20/lib" -lclang

ifeq ($(OS),Windows_NT)
	GEN_FLAGS := std=src/std analyzer=src/analyzer -- -I"C:/Program Files/LLVM/include"
	CFLAGS := -std=c99 -Wall -D_CRT_SECURE_NO_WARNINGS -I"C:/Program Files/LLVM/include"
	LDFLAGS := -L"C:/Program Files/LLVM/lib" -llibclang
	EXE := .exe
	DIST_COPY := build/2/pavec$(EXE) build/2/pavec.pdb
else
	GEN_FLAGS := std=src/std analyzer=src/analyzer -- -I"/lib/llvm-20/include"
	CFLAGS := -std=c99 -Wall -I"/lib/llvm-20/include" -fsanitize=address -fno-omit-frame-pointer
	LDFLAGS := -L"/lib/llvm-20/lib" -lclang -fsanitize=address -fno-omit-frame-pointer
	EXE :=
	DIST_COPY := build/2/pavec$(EXE)
endif

.PHONY: all ls ls-release examples clean

all:
	@echo "=== Stage 1: Building with dist/pavec ==="
	@$(MAKE) -f Makefile.build GENERATOR=dist/pavec$(EXE) BUILD_DIR=build/1 TARGET=build/1/pavec$(EXE) GEN_FLAGS='compiler=src/compiler $(GEN_FLAGS) -I./src/compiler' CFLAGS='-g -O0 $(CFLAGS) -I./src/compiler' LDFLAGS='-g $(LDFLAGS) ./src/compiler/fs.c' --no-print-directory
	@echo ""
	@echo "=== Stage 2: Building with build/1/pavec ==="
	@$(MAKE) -f Makefile.build GENERATOR=build/1/pavec$(EXE) BUILD_DIR=build/2 TARGET=build/2/pavec$(EXE) GEN_FLAGS='compiler=src/compiler $(GEN_FLAGS) -I./src/compiler' CFLAGS='-g -O0 $(CFLAGS) -I./src/compiler' LDFLAGS='-g $(LDFLAGS) ./src/compiler/fs.c' --no-print-directory
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
	@echo "=== Building and running tests ==="
	@$(MAKE) -f Makefile.build BUILD_DIR=build/2 CFLAGS='-g -O0 $(CFLAGS) -I./src/compiler' LDFLAGS='-g $(LDFLAGS) ./src/compiler/fs.c' tests --no-print-directory
	@echo ""
	@echo "=== Copying final build to dist ==="
	rm -rf dist/src
	cp -r $(DIST_COPY) build/2/src dist/
	@echo ""
	@echo "Bootstrap complete!"

ls:
	@$(MAKE) -f Makefile.build GENERATOR=dist/pavec$(EXE) BUILD_DIR=build/ls TARGET=../pave-vscode/out/pavels$(EXE) GEN_FLAGS='language_server=src/language_server $(GEN_FLAGS) -I./src/language_server -I./src/compiler' CFLAGS='-g -O0 $(CFLAGS) -I./src/language_server -I./src/compiler' LDFLAGS='-g $(LDFLAGS) ./src/compiler/fs.c' --no-print-directory

ls-release:
	@$(MAKE) -f Makefile.build GENERATOR=dist/pavec$(EXE) BUILD_DIR=build/lsr TARGET=../pave-vscode/out/pavels$(EXE) GEN_FLAGS='language_server=src/language_server $(GEN_FLAGS) -I./src/language_server -I./src/compiler' CFLAGS='-O2 $(CFLAGS) -I./src/language_server -I./src/compiler' LDFLAGS='$(LDFLAGS) ./src/compiler/fs.c' --no-print-directory

define build_example
	dist/pavec std=src/std $(1)=examples/$(1) -o examples --no-line-directives -- -I"C:/Program Files/LLVM/include" -Iexamples/$(1)
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
	$(call build_example,traits)
	$(call build_example,dynamic_fn)
	$(call build_example,cpp)
	mv examples/cpp/*.cpp examples/cpp/out/
	$(call build_example,ops)
	$(call build_example,tests)

clean:
	@echo "Cleaning build artifacts..."
	rm -rf build
	@echo "Clean complete"
