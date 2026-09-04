# C++ Modules

[![Build](https://github.com/C1STA/cpp-modules/actions/workflows/build.yml/badge.svg?branch=main)](https://github.com/C1STA/cpp-modules/actions/workflows/build.yml)

A progressive collection of 34 exercises covering C++ fundamentals, object-
oriented design, generic programming, and the Standard Template Library.

These modules are part of the 42 curriculum. They intentionally target C++98
and are compiled on a modern toolchain with `-Wall -Wextra -Werror`, making
language fundamentals and manual resource management explicit.

## Modules

| Module | Main concepts |
| ------ | ------------- |
| CPP00 | Namespaces, classes, member functions, streams, initialization lists |
| CPP01 | Memory allocation, pointers, references, file streams, switch statements |
| CPP02 | Orthodox Canonical Form, fixed-point numbers, operator overloading |
| CPP03 | Inheritance, constructor chains, method overriding |
| CPP04 | Subtype polymorphism, abstract classes, interfaces, deep copies |
| CPP05 | Exceptions, validation, abstract forms, factory pattern |
| CPP06 | Scalar conversions, serialization, runtime type identification |
| CPP07 | Function and class templates, generic iteration, bounds-safe arrays |
| CPP08 | STL containers, iterators, algorithms, iterable stack adapters |
| CPP09 | Bitcoin exchange, reverse Polish notation, merge-insertion sort |

## Engineering highlights

- Resource-owning classes implement copy construction and copy assignment
  explicitly, including deep-copy semantics where required.
- Polymorphic hierarchies use virtual destructors, abstract base classes, and
  interface-style contracts.
- Template exercises separate generic interfaces from their instantiation code.
- Container exercises use maps, stacks, vectors, deques, iterators, and standard
  algorithms according to their access and complexity characteristics.
- `CPP09/ex02` implements Ford–Johnson merge-insertion sort for both
  `std::vector` and `std::deque`, with timing reported independently.

## Build

Build every exercise from the repository root:

```bash
make
```

Each exercise can also be built and run independently:

```bash
make -C cpp-09/ex02
./cpp-09/ex02/PmergeMe 9 3 7 1 8 2 6 5 4
```

Other useful root commands:

```bash
make clean   # remove object and dependency files
make fclean  # also remove every executable
make re      # rebuild every exercise from scratch
make list    # list all exercise directories
```

## Examples

```bash
./cpp-00/ex00/megaphone "hello, C++"
./cpp-09/ex01/RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"
./cpp-09/ex02/PmergeMe 5 3 1 4 2
```

The GitHub Actions workflow builds all 34 exercises and runs smoke tests across
the introductory, template, STL, and algorithm modules.

Each module's curated submission snapshot is available through its corresponding
tag, from `cpp00-submission` to `cpp09-submission`.
