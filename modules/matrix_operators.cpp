#include "../include/matrix.h"

bool Matrix::operator==(const Matrix& other) { return this->EqMatrix(other); }

Matrix Matrix::operator+(const Matrix& other) const {
  Matrix result = *this;
  result.SumMatrix(other);
  return result;
}

Matrix& Matrix::operator+=(const Matrix& other) {
  this->SumMatrix(other);
  return *this;
}

Matrix Matrix::operator-(const Matrix& other) const {
  Matrix result = *this;
  result.SubMatrix(other);
  return result;
}

Matrix& Matrix::operator-=(const Matrix& other) {
  this->SubMatrix(other);
  return *this;
}

Matrix Matrix::operator*(const double num) const {
  Matrix result = *this;
  result.MulNumber(num);
  return result;
}

Matrix& Matrix::operator*=(const double num) {
  this->MulNumber(num);
  return *this;
}

Matrix Matrix::operator*(const Matrix& other) const {
  Matrix result = *this;
  result.MulMatrix(other);
  return result;
}

Matrix& Matrix::operator*=(const Matrix& other) {
  Matrix temp = *this * other;
  *this = temp;
  return *this;
}

Matrix& Matrix::operator=(const Matrix& other) {
  if (this != &other) {
    this->set_size(other.get_rows(), other.get_cols());
    for (int i = 0; i < other.get_rows(); i++)
      for (int j = 0; j < other.get_cols(); j++)
        this->matrix[i][j] = other.matrix[i][j];
  }
  return *this;
}

double& Matrix::operator()(int i, int j) {
  if (i < 0 || i >= rows_ || j < 0 || j >= cols_) {
    throw std::out_of_range("Index out of range");
  }
  return matrix[i][j];
}