<p align="center">
    <img src="https://game.42sp.org.br/static/assets/achievements/cppm.png">
</p>

<p align="center">
    <img src="https://img.shields.io/badge/OS-Linux-blue" alt="OS">
    <img src="https://img.shields.io/badge/Language-C%2B%2B98-orange.svg" alt="Language">
    <img src="https://img.shields.io/badge/Grade-100%2F100-brightgreen.svg" alt="Grade">
    <img src="https://img.shields.io/badge/Status-Completed-brightgreen.svg" alt="Status">
</p>

# C++ Piscine
This repository contains my CPP Piscine at 42 School.
The project focuses on learning Object Oriented Programming while learning C++ with the 98 standard.

The project involves learning:

- C++ Streams
- Classes
- Inheritance
- Polimorphism
- Composition
- C++ Sandard Template Library (Containers/Algorithms)

## Requirements
> **Warning**
>
> This project is meant to be built with the packaged versions available at your 42 School.

- clang v12
- GNU Make
- libcxxClang

## Usage
Each `cpp-XX` module exercises possess a `Makefile`.
To compile `ex00` from `cpp-00`, for example:

```sh
$ make -C cpp-00/ex00 
make: Entering directory '/home/vini/Code/cpp/cpp-00/ex00'
c++ -Wall -Werror -Wextra -std=c++98 megaphone.cpp -c -o build/megaphone.o
c++ -Wall -Werror -Wextra -std=c++98 build/megaphone.o -o megaphone
make: Leaving directory '/home/vini/Code/cpp/cpp-00/ex00'

$ ./cpp-00/ex00/megaphone 'hey, what is this?'
HEY, WHAT IS THIS?
```
