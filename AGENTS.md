# Pave Compiler

Pave is a self-hosted systems language that compiles to C99. The compiler is written in Pave itself and bootstrapped from `dist/pavec.exe`.

## Build

```sh
make all        # full bootstrap: dist/pavec → build/1 → build/2, verifies build/2 == build/3, runs tests
make clean      # if make all fails due to source build/2 !- build/3 then run make clean and make all
make examples   # compile all examples using dist/pavec.exe
```

On Windows from Codex/PowerShell, run `make all` through Git Bash so the Makefile uses Unix tools like `mkdir -p`, `rm`, `cp`, and `diff`:

```powershell
& 'C:\Program Files\Git\bin\bash.exe' -lc 'cd /c/Users/logan-gyxos/Repos/pave && make all'
```

The bootstrap stages:
1. `dist/pavec.exe` compiles `src/` → `build/1/pavec.exe`
2. `build/1/pavec.exe` compiles `src/` → `build/2/pavec.exe`
3. `build/2/pavec.exe` compiles `src/` → `build/3/src` and diffs against `build/2/src` to verify
4. Tests are built from `build/2/src/*.test.c` (linked with all `build/2` objects except `%/main.o`) and run; if any fail, the dist copy is skipped

Changes to `src/analyzer/` or `src/compiler/` require `make all` to take effect (they're compiler source, not library source). Changes to `src/std/` take effect immediately since `dist/pavec.exe` reads them at compile time.

When a change is complete, run `make all` and ensure it passes before calling the work done. If `make all` fails, fix the failure or clearly report the blocker and the exact failure.

To quickly check that modified `.pv` files parse and generate valid C without a full build:
```sh
mkdir -p build/test/src && dist/pavec.exe -o build/test/src compiler=src/compiler std=src/std analyzer=src/analyzer -- -I"C:/Program Files/LLVM/include" -I./src/compiler 2>&1
```

Ad-hoc test programs / scratch `.pv` files live under `build/<name>/` (e.g. `build/fn_instance_test/`), not in `examples/`. Each needs a `ns.pv` containing `mod <name>` plus the source file(s). Compile with:
```sh
dist/pavec.exe std=src/std <name>=build/<name> -o build/<name>/out --no-line-directives -- -I"C:/Program Files/LLVM/include"
```
Generated C lands in `build/<name>/out/<name>/`. `build/` is the scratch area — fine to delete or recreate freely; `examples/` is for canonical, committed examples.

## Project Structure

```
src/
├── analyzer/           # parsing and semantic analysis (compiler source)
│   ├── expression/
│   │   ├── BinaryExpression.pv   # parse_binary: precedence climbing; find_operator_trait_call
│   │   ├── CppExpression.pv      # C++ expression handling
│   │   ├── EnumVariantResult.pv  # EnumVariantResult enum (EnumVariant, EnumCValue, Function, Const)
│   │   ├── Expression.pv         # parse_primary, validate_type, null/0 pointer rules
│   │   ├── ExpressionData.pv     # ExpressionData enum variants (includes NullLiteral)
│   │   ├── ExpressionValidate.pv # validate_arguments, validate_enum_arguments
│   │   ├── GenericResolve.pv     # resolve_function_generics: infers generic types from call-site arguments
│   │   ├── InvokeArgument.pv     # function call argument representation
│   │   ├── MemberLookup.pv       # get_enum_variant, parse_enum, parse_struct, parse_class; member access
│   │   ├── ParseTypeExpression.pv # type-level expression parsing (struct/enum static members)
│   │   └── PostfixExpression.pv  # parse_postfix_chain: member access, indexing, slice ranges
│   ├── statement/
│   │   ├── AssignmentStatement.pv
│   │   ├── DeferStatement.pv     # defer <expr>; / defer { ... }
│   │   ├── ElseStatement.pv
│   │   ├── ForStatement.pv       # for / for * / for (a, b) / for (i, *v) in ... loops
│   │   ├── ForStatementType.pv
│   │   ├── ForVariable.pv
│   │   ├── IfStatement.pv
│   │   ├── LetStatement.pv       # let / let static bindings
│   │   ├── MatchCase.pv
│   │   ├── MatchPattern.pv
│   │   ├── MatchStatement.pv
│   │   ├── ReturnStatement.pv
│   │   ├── Statement.pv
│   │   ├── StatementData.pv
│   │   ├── WhileStatement.pv
│   │   └── YieldStatement.pv     # yield inside co functions
│   ├── types/
│   │   ├── Enum.pv               # Enum definition; variants support tuple payloads and named-field structs
│   │   ├── Function.pv           # Function, Parameter, FunctionParent enum
│   │   ├── GenericMap.pv         # Maps generic names to concrete types
│   │   ├── Generics.pv           # Generic bound tracking
│   │   ├── Global.pv             # global variable declarations
│   │   ├── Primitive.pv          # primitive type definitions (i8..u64, f32, f64, etc.)
│   │   ├── Struct.pv             # Struct definition; StructField has default_token_start for default values
│   │   ├── Trait.pv              # Trait definition; typedefs add generics to trait.generics
│   │   ├── Type.pv               # Type enum and equality/resolution methods
│   │   └── TypeImpl.pv           # impl block type representation
│   ├── c/                        # C/C++ interop type representations
│   │   ├── ClassCpp.pv
│   │   ├── EnumC.pv
│   │   ├── EnumCValue.pv
│   │   ├── FunctionC.pv
│   │   ├── Include.pv
│   │   ├── IncludeContext.pv
│   │   ├── IncludeEnumClass.pv
│   │   ├── IncludeObjectContext.pv
│   │   ├── NamespaceCpp.pv
│   │   ├── ParentCpp.pv
│   │   ├── StructC.pv
│   │   ├── StructCField.pv
│   │   ├── TypedefC.pv
│   │   └── UnknownC.pv
│   ├── Analysis.pv               # analysis entry point; Position, Range, Diagnostic, InlayHint
│   ├── Block.pv                  # block-level statement parsing
│   ├── Context.pv                # analysis context (allocator, scopes, modules)
│   ├── Impl.pv                   # impl block parsing; ImplConst (const decls), ImplNode enum; parse_typedefs augments trait_type's generic_map
│   ├── Module.pv                 # file parsing; prefill_types_impl sets FunctionParent with impl_index
│   ├── Namespace.pv              # namespace resolution
│   ├── NamespacePath.pv          # namespace path representation
│   ├── Naming.pv                 # type-to-identifier-string conversion
│   ├── Root.pv                   # root compilation unit
│   ├── Scope.pv                  # lexical scope management
│   ├── Token.pv                  # token types
│   └── Tokenizer.pv              # lexer/tokenizer
├── compiler/           # C code generation (compiler source)
│   ├── BlockWriter.pv            # statement/block C emission
│   ├── DefinitionWriter.pv       # header/source declarations; key methods:
│   │                             #   write_trait_function_with_body — decl + body, shared by impl and default trait fns
│   │                             #   write_dynamic_function_impl — emits __get_params, __set_arg, __execute/__init, vtable
│   ├── ExpressionWriter.pv       # write_invoke: emits function calls including trait dispatch
│   │                             #   write_sequence_cast: coerces fixed-array ref to slice (see below)
│   ├── FileGenerator.pv          # per-type file output; vtable initialization; generate_test_runner emits main.test.c
│   ├── FileWriter.pv             # low-level file write helpers
│   ├── FunctionContext.pv        # per-function compilation context
│   ├── FunctionCoroutine.pv      # coroutine function compilation
│   ├── FunctionScope.pv          # per-function scope tracking
│   ├── Generator.pv              # get_trait_function_name: canonical trait function name builder
│   ├── IncludeWriter.pv          # #include directive emission
│   ├── Usages.pv                 # tracks which types/functions are used (drives what gets emitted)
│   └── main.pv                   # compiler entry point
├── language_server/    # LSP server
│   ├── JsonNode.pv               # JSON AST node
│   ├── JsonParser.pv             # JSON parser
│   ├── LanguageServer.pv         # LSP protocol handler
│   ├── Processor.pv              # request processor
│   ├── Uri.pv                    # URI parsing/normalization
│   └── main.pv                   # LSP server entry point
└── std/                # standard library (read by dist/pavec.exe at compile time)
    ├── Allocator.pv              # Allocator trait (alloc, realloc, free)
    ├── ArenaAllocator.pv         # arena/bump allocator
    ├── Array.pv                  # Array<T> dynamic array; Iter<T>, IterEnumerate<T>
    ├── Co.pv                     # Co<T> trait (coroutine protocol: get_params, set_arg, init)
    ├── Deref.pv                  # Deref trait
    ├── Fn.pv                     # Fn trait (dynamic function: get_params, set_arg, execute)
    ├── GeneralPurposeAllocator.pv # malloc-backed allocator; default() returns a static instance
    ├── Hash.pv                   # Hash trait; Hashed(u64) tuple struct; Fnv1a hasher
    ├── HashMap.pv                # HashMap<K: Hash, V>; HashMapBucket, HashMapIter
    ├── HashSet.pv                # HashSet<T: Hash>
    ├── Iter.pv                   # Iter<T> (start/end/step iterator); IterEnumerate<T>
    ├── Iterator.pv               # Iterator trait
    ├── Ops.pv                    # Add, Sub, Mul, Div trait definitions (each with typedef Output)
    ├── Range.pv                  # Range<T> enum (All, Start, End, StartEnd); iter() method
    ├── Slice.pv                  # &[T] slice — iter() method
    ├── str.pv                    # str struct (ptr + length); eq, slice, trim, contains, etc.; Hash impl; tests
    ├── String.pv                 # String (growable char array backed by Array<char>)
    ├── Struct.pv                 # Struct reflection helpers
    └── TypeId.pv                 # TypeId for runtime type identification (used by Fn/Co dispatch)
```

## Key Architecture Concepts

### Three-Phase Compilation
1. `prefill_types` — quick scan, collect names and generic bounds
2. `fill_types` — full type resolution (fields, parameters, return types)
3. `parse_functions` — parse function bodies, type-check statements

### FunctionParent and impl_index
`FunctionParent::Struct(struct_info, impl_index, trait_info)` stores the index of the impl in `struct_info.impls`. This is used in naming to look up `struct_info.impls.data[impl_index].trait_type` and disambiguate function names when the same trait is implemented multiple times with different generic parameters (e.g., `Mul<f32>` and `Mul<Vec3>`).

### Trait Typedefs
`typedef Output;` inside a trait body adds a generic to both `trait.generics` and `trait.typedefs`. Impl blocks declare `typedef Output = Vec3;` — parsed in `Impl.parse_typedefs`, which augments the impl's `trait_type` generic_map to include the typedef bindings.

### Two Naming Paths (must stay consistent)
- **Call sites**: `Naming.get_type_name(&Type::Function(...))` — walks `FunctionParent` and appends `TraitName_GenericArgs__funcname`
- **Declarations**: `Generator.get_trait_function_name(struct_name, trait_info, impl_trait_type, func_info, generics)` — used by `DefinitionWriter` for header/source declarations

Both must produce the same string. The `impl_trait_type: &Type` parameter (the impl's `trait_type` field) provides the generic bindings (e.g., `T=f32`) needed for disambiguation. Pass `null` when the impl is unavailable; the function silently skips the suffix.

### Operator Trait Dispatch
`Expression.find_operator_trait_call` is called from `parse_binary` for `+`, `-`, `*`, `/`. It:
1. Walks the LHS struct's impls looking for `Add`/`Sub`/`Mul`/`Div` trait
2. Matches the RHS type against the impl's second parameter
3. Builds an `Invoke(Type(Function(...)), [lhs, rhs])` expression (`validate_arguments` auto-wraps `lhs` in `&` only if the first parameter is `&self`; for value `self` no wrapping happens at analysis time)

Falls through to a raw `BinaryExpression` if no matching impl is found, so primitive arithmetic is unaffected.

### Value `self` vs `&self` in Trait Functions
`&self` uses `void* __self` in the C ABI so the function can be stored in a vtable (all pointers are the same size). Value `self` cannot use `void*` — C prohibits `void` as a non-sole parameter. Two sites handle the split:

- **`DefinitionWriter.write_trait_function_decl`**: if `func_info.parameters.data[0].type.is_self()` (bare `Self`, not `&Self`), passes real `generics` to `write_function_definition` so the concrete type is emitted (e.g., `float self`). Otherwise passes `generics_void` (`self_type = void`) so the `&self` parameter becomes `void* __self`.
- **`DefinitionWriter.write_trait_function_with_body`**: skips `write_self_cast` for value `self` — the parameter IS the value already, no `SelfType* self = __self;` cast needed. Member access correctness (`self.x` vs `self->x`) is type-driven via `write_instance_member_accessor`, which delegates `Type::Self` to `generics.self_type`.

### Array Literal AST Shape
`[a, b, c]` parses to `ExpressionData::Invoke(target, elements)` where `target` is `ExpressionData::Type(Type::Sequence(FixedArray(N)))`. This is the same `Invoke` form used for struct construction — the target type determines how `write_expression` renders it (fixed arrays → `{a, b, c}`, slices → `(struct slice_T){ .data=..., .length=... }`).

An empty `[]` has no elements, so the element type is unknown at parse time — `Expression.pv` defaults it to `type_void` as a placeholder (the real element type is supplied by the target context during codegen).

### Test Functions and the Build
`test "description" { ... }` blocks in `.pv` files emit two output files per test:
- `<module>__<description_as_ident>.test.c` / `.test.h` — the test function body; e.g., `test "eq - equal strings"` in `str.pv` → `str__eq___equal_strings.test.c`, function `void test_str__eq___equal_strings()`
- `main.test.c` — the test runner with its own `main`; generated by `FileGenerator.generate_test_runner`

Both file types use `.test.c` / `.test.h` extensions. When building the compiler itself, `Makefile.build` must **exclude `*.test.c` files** from the object list — otherwise the test runner's `main` conflicts with the compiler's `main`. This is done with `$(filter-out %.test.c, ...)` in both the static `OBJS` and the dynamic `CURRENT_OBJS` definitions in `Makefile.build`.

The `[TEST]` output line format is `[TEST] <module_path>: <description>`, e.g. `[TEST] std/str: eq - equal strings`. The module path is built by `FileGenerator.collect_tests` via `Generator.make_rel_path(module, module_name, "")` — the same namespace-chain walk used for header paths, but with the module stem and no extension.

**Test runner link rule**: when linking the test binary, exclude `%/main.o` (pattern match, not literal path) — the compiler's `main` lives at `compiler/main.o`, not `main.o`, so a hardcoded `$(OBJ_DIR)/main.o` filter will silently miss it. Use `$(filter-out %/main.o, $(OBJS))` in `Makefile.build`.

If `make` fails with `main already defined in main.o`, the test file filter has been lost. If the bootstrap verification fails with spurious extra files in `build/2/src`, run `make clean && make` — old test artifacts in the build directory cause false diffs.

### Slice Coercion (`write_sequence_cast`)
`&expr` where `expr` is a fixed array coerces to a slice. `ExpressionWriter.write_sequence_cast` handles two cases:

- **`&[a, b]` (array literal)** — `unary_inner` is an `Invoke` with a `Sequence(FixedArray)` target, which `write_expression` renders as `{a, b}`. A compound literal prefix is required: `(ElemType[]){a, b}`. Detection: match `unary_inner.data` as `Invoke(target, _)` and check `target.return_type` is `Sequence(FixedArray(...))`.
- **`&variable`** — `unary_inner` is a `Variable` or other expression that decays naturally to a pointer; write it directly with no prefix.

## Conventions

- `&T` — non-null reference (but can be null in practice; check with `!= 0`)
- `*T` — raw pointer (nullable); must use `null` for the null value, never `0`
- `for *impl_info in struct.impls` — iterates `Array<&Impl>`, dereferencing each element
- `array.data[i]` — direct array indexing (e.g., `struct_info.impls.data[impl_index]`)
- `context.allocator.store(&val)` — copies `val` into the arena and returns a pointer to it
- Functions taking `generic_map: *GenericMap` accept `null` for no outer generic context

### Null Safety Rules
`null` and `0` are distinct in Pave's type system:
- `null` is the only valid null value for `*T` (raw pointer) types. Using `0` where a `*T` is expected is a compile error.
- `null` cannot be used with `&T` (reference) or `&dyn Trait` — those use `== 0` / `!= 0` for null checks since `&T` is non-null by convention but nullable in practice.
- These rules are enforced in `Expression.validate_type` via the `ExpressionData::NullLiteral` variant (used by the `null` keyword) vs `ExpressionData::Literal("0")` (used by the integer `0`).
- In comparisons (`==`, `!=`), both sides are checked: `ptr == null` is valid, `ptr == 0` errors, `ref == null` errors.

### Struct Default Field Values
`StructField` has a `default_token_start: usize` field. When parsing a struct, if a field has `= <expr>` after its type, the token position is stored. During struct construction (`Struct { field: val }`), if a field is omitted and `default_token_start != 0`, the default expression is re-parsed from that token position. This is handled in `ExpressionValidate.validate_arguments` for `Type::Struct`.

### Enum Struct Variants
Enum variants support named fields in addition to tuple payloads:
- Tuple: `Variant(f32, f32)` — accessed by position in match
- Struct: `Variant { x: f32, y: f32 }` — accessed by name in match

`EnumVariant` has a `names: Array<str>` field; non-empty `names` signals a struct variant. `EnumVariantParameter` has a `field_name: str` field for the bound name. Match pattern destructuring handles both forms in `MatchPattern.pv`.

### Impl Const Values
`impl` blocks can declare `const NAME: Type = expr;` items. These are represented as `ImplConst` structs stored in `impl_info.consts: HashMap<str, &ImplConst>`. At a call site, `TypeName::CONST_NAME` resolves via `EnumVariantResult::Const(&ImplConst)` in `MemberLookup.get_enum_variant` and emits as `TypeName_ConstName` in C (via `MemberStaticExpression`).

### Match Pattern Numeric Literals
`MatchPattern` supports numeric literal arms (including negatives):
- `match n { 1 => ..., -2 => ..., 3.14 => ... }` — `MatchPattern::StaticValue(expr)` where `expr` is a `Literal` or `UnaryExpression("-", Literal)`.
- Implemented in `MatchPattern.pv`; the match arm emits a C `if (self == <literal>)` comparison.

## Meta

At the end of a work session, offer to update this file only when the work revealed durable guidance that would help future agents avoid mistakes or understand the system faster. Good candidates are cross-cutting architecture rules, bootstrap/build gotchas, naming or ABI invariants, and non-obvious interactions between analyzer/compiler/std code. Skip one-off implementation details, ordinary local naming choices, facts already obvious from nearby code, and notes unlikely to matter after the current change.
