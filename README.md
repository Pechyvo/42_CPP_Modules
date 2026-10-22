# C++ Modules

A collection of the ten C++ modules from the 42 curriculum. The exercises progress from basic class design and memory management to inheritance, polymorphism, templates, STL containers, and algorithms.

All exercises target the C++98 standard and are compiled with `-Wall -Wextra -Werror`.

## Modules

| Module | Topics | Exercises |
| --- | --- | --- |
| [CPP00](CPP00/) | Namespaces, classes, member functions, streams, initialization lists, `static`, and `const` | Megaphone, PhoneBook, Account |
| [CPP01](CPP01/) | Memory allocation, pointers, references, file streams, and pointers to members | Zombies, weapon references, text replacement, Harl |
| [CPP02](CPP02/) | Orthodox Canonical Form, fixed-point numbers, and operator overloading | Fixed-point class revisions |
| [CPP03](CPP03/) | Inheritance and class hierarchies | ClapTrap, ScavTrap, FragTrap |
| [CPP04](CPP04/) | Subtype polymorphism, deep copies, and abstract classes | Animals, Brain, abstract Animal |
| [CPP05](CPP05/) | Exceptions and abstract workflows | Bureaucrat, Form, concrete forms, Intern |
| [CPP06](CPP06/) | C++ casts, serialization, and runtime type identification | ScalarConverter, Serializer, type identification |
| [CPP07](CPP07/) | Function and class templates | `whatever`, `iter`, `Array` |
| [CPP08](CPP08/) | Templated containers, iterators, and algorithms | `easyfind`, Span, MutantStack |
| [CPP09](CPP09/) | STL containers and algorithmic problem-solving | BitcoinExchange, RPN, PmergeMe |

## Requirements

- A C++ compiler with C++98 support
- GNU Make
- A Unix-like environment

On Debian or Ubuntu:

```sh
sudo apt install build-essential
```

## Build

Each module has a convenience Makefile that builds all of its exercises. For example:

```sh
make -C CPP09
```

An individual exercise can also be built directly:

```sh
make -C CPP09/ex00
```

The resulting executables are placed in the corresponding module directory. Common targets include:

```sh
make -C CPP09 clean
make -C CPP09 fclean
make -C CPP09 re
```

Some module Makefiles also provide test and Valgrind targets. Run `make -C CPPXX -n <target>` to inspect a target before executing it.

## Repository structure

```text
.
├── CPP00/
│   ├── ex00/
│   ├── ex01/
│   ├── ex02/
│   └── subject/
├── ...
└── CPP09/
    ├── ex00/
    ├── ex01/
    ├── ex02/
    └── subject/
```

Each exercise is self-contained and includes its own Makefile. Shared formatting definitions used by an exercise live in the parent module directory.

## Subject PDFs

- [CPP00 subject](CPP00/subject/en.subject_cpp00.pdf)
- [CPP01 subject](CPP01/subject/en.subject_cpp01.pdf)
- [CPP02 subject](CPP02/subject/en.subject_cpp02.pdf)
- [CPP03 subject](CPP03/subject/en.subject_cpp03.pdf)
- [CPP04 subject](CPP04/subject/en.subject_cpp04.pdf)
- [CPP05 subject](CPP05/subject/en.subject_cpp05.pdf)
- [CPP06 subject](CPP06/subject/en.subject_cpp06.pdf)
- [CPP07 subject](CPP07/subject/en.subject_cpp07.pdf)
- [CPP08 subject](CPP08/subject/en.subject_cpp08.pdf)
- [CPP09 subject](CPP09/subject/en.subject_cpp09.pdf)
