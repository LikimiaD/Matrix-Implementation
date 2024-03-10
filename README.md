# Matrix-Implementation

![C++](https://img.shields.io/badge/c++-%2300599C.svg?style=for-the-badge&logo=c%2B%2B&logoColor=white)
![GitHub Actions](https://img.shields.io/badge/github%20actions-%232671E5.svg?style=for-the-badge&logo=githubactions&logoColor=white)

Matrix-Implementation is a C++ library that provides a comprehensive set of operations for manipulating matrices. This library allows for basic matrix operations such as addition, subtraction, multiplication, as well as more advanced operations like transposition, calculation of the determinant, algebraic complements, and finding the inverse matrix. Developed following modern C++ standards (C++17), it adheres to Google's C++ Style Guide for clean and readable code.

## Features

- Basic matrix operations: Add, Subtract, Multiply (by another matrix or a scalar).
- Advanced operations: Transpose, Determinant, Algebraic Complements, Inverse Matrix.
- Exception handling for operations involving matrices of incompatible sizes or other issues.
- Implementation of both the copy constructor and the assignment operator for deep copying of matrices.
- Accessor (getter) and mutator (setter) for matrix dimensions with smart resizing.
- Operator overloading for intuitive matrix manipulations.
- Comprehensive unit testing coverage (96% to 100%) using GoogleTest.

For more details, refer to the [header file](include/matrix.h).

## Structure

The project is structured as follows:

```tree
.
├── LICENSE
├── Makefile
├── include
│ └── matrix.h
├── modules
│ ├── matrix_func.cpp
│ ├── matrix_init.cpp
│ ├── matrix_operators.cpp
│ └── matrix_support.cpp
└── tests
└── matrix_tests.cpp
```

## Installation

To use the Matrix-Implementation library in your project, follow these steps:

1. Clone the repository to your local machine.
2. Use the provided Makefile to compile the library:
    ```bash
    make lib_matrix.a
    ```
3. Include the `matrix.h` header in your project and link against the compiled static library `lib_matrix.a` during the compilation of your application.

## Usage

Here is a quick example of how to use the Matrix-Implementation library:

```cpp
#include "matrix.h"

int main() {
 Matrix m1(2, 2), m2(2, 2);
 m1(0, 0) = 1; m1(0, 1) = 2;
 m1(1, 0) = 3; m1(1, 1) = 4;

 m2(0, 0) = 2; m2(0, 1) = 0;
 m2(1, 0) = 1; m2(1, 1) = 2;

 Matrix sum = m1 + m2;
 Matrix product = m1 * m2;
 Matrix inverse = m1.InverseMatrix();

 // Continue with other operations...
}
```

## Building and Testing

To build the library and run unit tests, use the following commands:

```bash
make all              # Builds the library and tests
make test             # Runs the unit tests
make gcov_report      # Creating an HTML Gcov report file
```

Check out the [Makefile](../Makefile) for build instructions.

## Contributing

Contributions to the Matrix-Implementation project are welcome. Please feel free to fork the repository, make your changes, and submit a pull request.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.