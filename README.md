# Pave

## Pave Language

Pave is an _experimental_ systems language that compiles/transpiles to C99. The idea is to allow a more modern syntax and features, which help to improve ergonomics and safety while staying compatible with C99.

## Features

- Traits with implementations
- Enums with disciminated unions
- Coroutines
- Generics
- C and CPP can be used directly
- Iterators
- Dynamic functions, structs etc
- Defer

## Examples

More detailed examples and their outputs can be found in the [examples](https://github.com/pave-lang/pave/tree/main/examples) folder

```rust
struct Counter { value: u32 }

impl Counter {
    fn new() -> Self { return Self { value: 0 }; }
    fn increment(&self) { self.value += 1; }
}

fn run_counter() {
    let counter = Counter::new();
    counter.increment();
    counter.increment();
    counter.increment();
    printf("%u\n", counter.value);
}

enum Example {
    None,
    Single(i32),
    Dual(i32, i32),
}

impl Example {
    fn print(&self) {
        match self {
            Example::None => { printf("none\n"); },
            Example::Single(value) => { printf("single: %d\n", value); },
            Example::Dual(left, right) => { printf("dual: %d %d\n", left, right); },
        }
    }
}

fn iterators(argc: i32, argv: **const char) -> i32 {
    for i in 0..10 {
        printf("index: %d\n", i);
    }

    let array = Array<i32>::new(GeneralPurposeAllocator::default());
    array.append(3);
    array.append(4);
    array.append(1);
    for *a in array {
        printf("array: %d\n", a);
    }
}
```
