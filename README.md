# Project: Tree Data Structure with Traversal and Visualization

This project implements a generic tree data structure in C++ with multiple traversal methods and visualization using the SFML library. It includes tests for validating tree operations using the `doctest` framework.

## Files Overview

- **node.hpp / node.cpp**: Defines the `Node` class, representing individual nodes in the tree.
- **tree.hpp / tree.cpp**: Defines the `Tree` class, which manages the tree structure and provides various traversal methods (e.g., BFS, DFS). Includes functionality to visualize the tree using SFML.
- **Demo.cpp**: A demo program that builds a tree and visualizes it using SFML.
- **test.cpp**: Contains test cases for the tree using the `doctest` framework to ensure the correctness of various operations and traversals.
- **complex.hpp**: A header file defining a `Complex` class used in the demo and tests.
- **Makefile**: A script to compile the project, including building the demo and test executables.

## Prerequisites

- **C++17**: This project uses C++17 features.
- **SFML**: The Simple and Fast Multimedia Library (SFML) is used for graphical visualization. Make sure SFML is installed on your system.
- **doctest**: The testing framework `doctest` is used for running unit tests.

## How to Build and Run

1. **Clone the Repository**:
    ```bash
    git clone <repository-url>
    cd <repository-directory>
    ```

2. **Compile the Project**:
    - Make sure SFML and `doctest.h` are installed and accessible in your include path.
    - Use the provided Makefile to build the project:
      ```bash
      make
      ```
    - This will generate two executables: `demo` and `tests`.

3. **Run the Demo**:
    - The `demo` executable runs a program that builds and visualizes a tree using SFML.
    ```bash
    ./demo
    ```

4. **Run the Tests**:
    - The `tests` executable runs unit tests to validate tree operations.
    ```bash
    ./tests
    ```

## Using the Project

- **Tree Visualization**: The `Tree` class supports visualization using SFML. Ensure that the font file `arial.ttf` is present in the same directory as the executable or specify the correct path to it.
- **Tree Traversals**: The `Tree` class supports various traversal methods:
  - BFS (Breadth-First Search)
  - DFS (Depth-First Search)
  - Heap Traversal
  - Pre-Order, Post-Order, and In-Order Traversals are only applicable for binary trees (`k = 2`). For non-binary trees, these default to DFS.

## Troubleshooting

- **Font Loading Issue**: Ensure `arial.ttf` is in the correct directory. The project looks for `arial.ttf` in the current working directory by default. If it's not loading, check the working directory from which the executable is run and ensure `arial.ttf` is present there.
- **SFML Installation**: Make sure SFML is installed and linked correctly. On some systems, you may need to install the development package (e.g., `libsfml-dev` on Ubuntu).

## Future Improvements

- Enhance error handling for file loading and invalid operations.
- Extend the tree visualization to support more complex graphics and animations.
- Implement additional tree operations such as deletion or balancing for binary trees.

## License

This project is open-source and available under the MIT License. Feel free to modify and use it as needed.

## Contact

For any issues or suggestions, feel free to open an issue in the repository or contact the author directly.
