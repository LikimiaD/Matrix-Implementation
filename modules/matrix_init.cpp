#include "../include/matrix.h"

Matrix::Matrix() : Matrix(0, 0) {}
Matrix::Matrix(int rows, int cols) {
  if (rows < 0 || cols < 0 || (rows == 0 && cols != rows)) {
    throw std::invalid_argument(
        "The dimensionality of the matrix cannot be negative.");
  }

  rows_ = rows;
  cols_ = cols;
  if (rows > 0 && cols > 0) {
    matrix = {new double* [rows] {}};
    for (int i = 0; i < rows; i++) matrix[i] = {new double[cols]{}};
  } else {
    matrix = nullptr;
  }
}
Matrix::Matrix(const Matrix& other) {
  if (this != &other) {
    rows_ = other.rows_;
    cols_ = other.cols_;
    matrix = new double*[rows_];
    for (int i = 0; i < rows_; ++i) {
      matrix[i] = new double[cols_]{};
    }
    for (int i = 0; i < rows_; ++i) {
      for (int j = 0; j < cols_; ++j) {
        matrix[i][j] = other.matrix[i][j];
      }
    }
  }
}
Matrix::~Matrix() {
  for (int i = 0; i < rows_; ++i) {
    delete[] matrix[i];
  }
  delete[] matrix;
}
int Matrix::get_rows() const { return rows_; }
int Matrix::get_cols() const { return cols_; }
void Matrix::set_size(int new_rows, int new_cols) {
  resizeMatrix(new_rows, new_cols);
}