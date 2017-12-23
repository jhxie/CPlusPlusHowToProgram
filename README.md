## Overview
Source code written during the learning path of [C++ How to Program][HTP]
book.

## Dependencies
* C++ Compiler with ISO C++ 14 Support (Clang **3.5** / GCC **6.1** / Visual C++ **14.0**)
* [CMake][CMK] Build System (**3.4.3**)
* [GraphViz][GVZ] Graph Visualization Software (2.38)

**Ubuntu** (17.10)  
```bash
sudo apt-get install build-essential cmake cmake-extras extra-cmake-modules graphviz
```

**Windows 10**  
Follow the [documentation][VS2017] listed to install *Visual Studio*, make sure
workloads *Windows desktop development with C++* and
*Linux development with C++* are installed; then proceed to install *GraphViz*
from the address shown
[here](https://graphviz.gitlab.io/_pages/Download/Download_windows.html).

After installing it, add all the command line layout engine executables to the
system **PATH** environment variable:
```
Copy the Installation Path Contains the 'dot' Executable ('bin' subdirectory)
Run Dialogue (Windows Key + R) → sysdm.cpl → OK
Advanced → Environment Variables → Select 'Path' in the List → Edit
New → Paste the Absolute Path that Contains the 'dot' Executable → OK
```

## Build Instructions
The included diagrams for documentation purposes would be rendered in *PNG*
format and reside in *doc* subdirectory of the *build* directory.

**Ubuntu** (17.10)  
Change working directory to where the source directory resides and then issue:
```bash
mkdir build
pushd !$
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
To run the compiled executables, issue commands similar to the following
(assume the current working directory is *build*):
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

## Credits
* The [DownloadProject][DOWNPRO] *CMake* module is used to download and
statically link [Google Test][GTEST] at project configure time.

## License
Copyright © 2017 - 2018 Jiahui Xie  
Licensed under the [BSD 2-Clause License][BSD2].  
Distributed under the [BSD 2-Clause License][BSD2].  

[BSD2]: https://opensource.org/licenses/BSD-2-Clause
[CMK]: https://cmake.org/
[CMAKEGENERATORS]: https://cmake.org/cmake/help/git-master/manual/cmake-generators.7.html
[DOWNPRO]: https://github.com/Crascit/DownloadProject
[HTP]: https://www.deitel.com/books/cpphtp10
[GTEST]: https://github.com/google/googletest
[GVZ]: https://graphviz.org/
[VS2017]: https://docs.microsoft.com/en-us/visualstudio/install/install-visual-studio
