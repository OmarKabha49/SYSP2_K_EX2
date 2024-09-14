cmake_minimum_required(VERSION 3.10)
project(EX2_)

set(CMAKE_CXX_STANDARD 17)

# Find the SFML package
find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

# Add the executable
add_executable(EX2_
        #Demo.cpp
        #main.cpp
        tree.hpp
        node.hpp
        complex.hpp
        test.cpp
        tree.cpp
        node.cpp
)

# Link the SFML libraries
target_link_libraries(EX2_ sfml-graphics sfml-window sfml-system)
