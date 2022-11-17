# LibOpenCM3 App

This is an Example of [LibOpenCM3 CMake](https://github.com/mikisama/libopencm3_cmake).

### Prerequisites

* [CMake](https://github.com/Kitware/CMake/releases)
* [GCC](https://github.com/xpack-dev-tools/arm-none-eabi-gcc-xpack/releases)
* [Ninja](https://github.com/ninja-build/ninja/releases)
* [Python](https://www.python.org/downloads)

### Quick Start

1. Clone this repo
    ```bash
    git clone --recursive https://github.com/mikisama/libopencm3_app.git
    ```
2. Setup CMake build directory
    ```bash
    cmake -GNinja -DCMAKE_TOOLCHAIN_FILE='cmake/gcc-arm-none-eabi.cmake' -DCMAKE_EXPORT_COMPILE_COMMANDS=ON -DCMAKE_BUILD_TYPE=Debug -Bbuild .
    ```
3. Build
    ```bash
    cmake --build build
    ```
