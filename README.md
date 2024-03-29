# SphereTracer
Tiny sphere pathtracer written in C++ and ISPC made to test and learn more about acceleration structures, vectorization and optimization.

## Building

SphereTracer uses [TBB](https://github.com/oneapi-src/oneTBB) to manager parallelism and [GLEW](http://glew.sourceforge.net/) to load OpenGL functions, and you need [ISPC Compiler](https://ispc.github.io/ispc.html) as I use ispc code to take advantage of vectorization in various places. Both can easily be built
using [Vcpkg](https://github.com/microsoft/vcpkg).
```bat
vcpkg install tbb:x64-windows
vcpkg install glew:x64-windows
```
You can build the project with [CMake](https://cmake.org/), you will need to have both [Vcpkg](https://github.com/microsoft/vcpkg) and Intel 
[ISPC Compiler](https://ispc.github.io/ispc.html) installed on your computer.

You'll need to specify the path to the vcpkg's CMake toolchain file and you can specify the path to ISPC Compiler if you have a custom install of it.

```bat
git clone https://github.com/romainaugier/SphereTracer.git
cd SphereTracer
cmake -S . -B build -DCMAKE_TOOLCHAIN_FILE=/path/to/vcpkg/toolchain/vcpkg.cmake -DISPC_EXECUTABLE=/path/to/ispc.exe
cmake --build ./build --config Release
./build/src/Release/SphereTracer.exe
```

It has been tested and runs fine on Windows 10 and Ubuntu 20.04.
