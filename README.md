# CppTest

## Contents

1. [Summary](#summary)
2. [Building](#building)
3. [Running](#running)

## Summary <a name="summary"></a>

Collection of small programs that are built and run to ensure the build system
is operating correctly, the build system is assumed to support c++20.

HelloWorld -> Build and run a simple hello world program
Format     -> Test if std::format is available
Modules    -> Test to see if c++20 modules are operating correctly

## Building <a name="building"></a>

To build CppTest you will need the following programs:

- CMake version 3.28+ (Module dependency scanning is required)
- Ninja version 1.11+ or Visual Studio Generator (For dependency scanning)

Invoke cmake on the command line to build the project, examples:

Typical ->
```bash
mkdir out/build/ -p
cmake -S . -B out/build -G Ninja
cmake --build out/build
```

Specify Compiler ->
```bash
mkdir out/clang/ -p
CXX=clang++ cmake -S . -B out/clang -G Ninja
cmake --build out/clang
```

On Windows ->
```bash
mkdir out
mkdir out/build
cmake -S . -B out/build
cmake --build out/build --config Debug
```

## Running <a name="running"></a>

To run CppTest you can invoke the Driver program which will run all the tests ->
```bash
./out/build/Driver
```
You can also invoke a test on its own ->
```bash
./out/build/HelloWorld/HelloWorld
```
