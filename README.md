## Overview
Source code written during the learning path of [C++ How to Program][HTP]
book.

## Dependencies
* C++ Compiler with ISO C++ 14 Support (Clang **3.5** / GCC **6.1** / Visual C++ **14.0**)
* [CMake](https://cmake.org/) Build System (**3.3.2**)

**Ubuntu** (17.10)  
```bash
sudo apt-get install build-essential cmake cmake-extras extra-cmake-modules
```

**Windows 10**  
Follow the [documentation][VS2017] listed to install *Visual Studio*, make sure
workloads *Windows desktop development with C++* and
*Linux development with C++* are installed.

## Build Instructions
**Ubuntu** (17.10)  
Change working directory to where the source directory resides and then issue:
```bash
mkdir build && pushd !$
cmake .. && make -j$(nproc)
```

**Windows 10**  
If Visual Studio 2017 is installed, the project can be directly imported into
the *IDE* without generating solution or project files by following the
following steps:
```
File → Open → CMake → Navigate to the Source Directory → CMakeLists.txt
CMake → Build All
```
It should use *Ninja* as a backend during the building process.

To import the project in previous versions of Visual Studio, first make sure
*CMake* is properly installed, then issue the following in *PowerShell* after
changing the working directory to where the source directory resides:
```
(mkdir build) -and (pushd build)
cmake ..
```
A Visual Studio solution file (*CPlusPlusHowToProgram.sln*) that matches the
correct installed version should be generated inside *build* sub-directory;
simply open this file and build it with the *IDE* as usual.

## Getting Started
**Ubuntu** (17.10)  
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

**Windows 10**  
If Visual Studio 2017 is being used, right click the translation unit that
needs to be executed in *Solution Explorer* and select *Debug*. Otherwise, follow
the usual debug instructions as it requires in the relevant version.

## License
Copyright © 2017 - 2018 Jiahui Xie  
Licensed under the [BSD 2-Clause License][BSD2].  
Distributed under the [BSD 2-Clause License][BSD2].  

[BSD2]: https://opensource.org/licenses/BSD-2-Clause
[HTP]: https://www.deitel.com/books/cpphtp10
[VS2017]: https://docs.microsoft.com/en-us/visualstudio/install/install-visual-studio
[CMAKEGENERATORS]: https://cmake.org/cmake/help/git-master/manual/cmake-generators.7.html
