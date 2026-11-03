# Build & run project
run:
    cmake --build build
    ./build/tlib_example

# Build project
build:
    cmake --build build

# "Hot-reloading" build
hot:
    find . -type f \( \
        -name '*.cpp' -o \
        -name '*.hpp' -o \
        -name '*.h' -o \
        -name '*.c' -o \
        -name 'CMakeLists.txt' -o \
        -name '*.cmake' \
    \) | entr -c just run 

# Build with address sanitizer
debug:
    cmake -S . -B build-asan -DTLIB_SANITIZE=ON
    cmake --build build-asan
    ./build-asan/tlib_example

# "hot-reloading" Address sanitizer build
hot-debug:
    find . -type f \( \
        -name '*.cpp' -o \
        -name '*.hpp' -o \
        -name '*.h' -o \
        -name '*.c' -o \
        -name 'CMakeLists.txt' -o \
        -name '*.cmake' \
    \) | entr -c just debug 
