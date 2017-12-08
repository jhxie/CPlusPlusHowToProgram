## Overview
Source code written during the learning path of [C++ How to Program][HTP]
book.

## Dependencies
* C++ Compiler with ISO C++ 14 Support (Clang **3.5** / GCC **6.1** / Visual C++ **14.0**)
* [CMake](https://cmake.org/) Build System (**3.3.2**)

**Ubuntu** (>= 17.10)
```bash
sudo apt-get install build-essential cmake cmake-extras extra-cmake-modules
```

## Build Instructions
**Ubuntu** (>= 17.10)
Change working directory to where the source directory resides and then issue:
```bash
mkdir build && pushd !$
cmake .. && make -j$(nproc)
```

## Getting Started
**Ubuntu** (>= 17.10)
To run the compiled executables, issue commands similar to the following:
```bash
pushd src
2/CInAndCOut
```
All the executables should be easily accessible in this directory; once the
debugging or experimenting session has ended, issue the following to get back
to the original directory:
```bash
cd -2
```

## License
Copyright © 2017 - 2018 Jiahui Xie
Licensed under the [BSD 2-Clause License][BSD2].  
Distributed under the [BSD 2-Clause License][BSD2].  

[BSD2]: https://opensource.org/licenses/BSD-2-Clause
[HTP]: https://www.deitel.com/books/cpphtp10
