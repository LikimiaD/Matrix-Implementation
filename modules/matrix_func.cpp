#include "../include/matrix.h"

bool Matrix::EqMatrix(const Matrix& other) {
  bool status = true;
  if (this->cols_ == other.cols_ && this->rows_ == other.rows_ &&
      this->matrix != nullptr && other.matrix != nullptr && this->rows_ > 0 &&
      this->cols_ > 0) {
    for (int i = 0; i < this->rows_ && status; i++) {
      for (int j = 0; j < this->cols_; j++) {
        if (this->matrix[i][j] != other.matrix[i][j]) {
          status = false;
          break;
        }
      }
      if (!status) break;
    }
  } else {
    status = false;
  }
  return status;
}
void Matrix::SumMatrix(const Matrix& other) {
  if (this->cols_ == other.cols_ && this->rows_ == other.rows_ &&
      this->matrix != nullptr && other.matrix != nullptr && this->rows_ > 0 &&
      this->cols_ > 0) {
    for (int i = 0; i < this->rows_; i++)
      for (int j = 0; j < this->cols_; j++)
        this->matrix[i][j] += other.matrix[i][j];
  } else {
    throw std::invalid_argument("Matrices are not uniform or not declared.");
  }
}
void Matrix::SubMatrix(const Matrix& other) {
  if (this->cols_ == other.cols_ && this->rows_ == other.rows_ &&
      this->matrix != nullptr && other.matrix != nullptr && this->rows_ > 0 &&
      this->cols_ > 0) {
    for (int i = 0; i < this->rows_; i++)
      for (int j = 0; j < this->cols_; j++)
        this->matrix[i][j] -= other.matrix[i][j];
  } else {
    throw std::invalid_argument("Matrices are not uniform or not declared.");
  }
}
void Matrix::MulNumber(const double num) {
  if (!std::isnan(num) && this->rows_ > 0 && this->cols_ > 0) {
    for (int i = 0; i < this->rows_; i++)
      for (int j = 0; j < this->cols_; j++) this->matrix[i][j] *= num;
  } else {
    throw std::invalid_argument("Attempt of matrix multiplication by NaN.");
  }
}
void Matrix::MulMatrix(const Matrix& other) {
  if (this->matrix != nullptr && other.matrix != nullptr && this->cols_ > 0 &&
      other.rows_ > 0 && this->rows_ > 0) {
    if (this->cols_ == other.rows_) {
      double** tmpMatrix = this->createTempMatrix(this->rows_, other.cols_);
      this->mulTempMatrix(tmpMatrix, other);
      for (int i = 0; i < this->rows_; i++) delete[] this->matrix[i];
      delete[] this->matrix;
      this->matrix = tmpMatrix;
      this->cols_ = other.cols_;
    } else {
      throw std::invalid_argument(
          "Matrix dimensions do not allow multiplication.");
    }
  } else {
    throw std::invalid_argument(
        "One or both matrices are not initialized properly.");
  }
}
Matrix Matrix::Transpose() {
  if (!(this->matrix != nullptr && this->cols_ > 0 && this->rows_ > 0))
    throw std::invalid_argument(
        "This matrix cannot be transposed, the matrix does not exist.");

  Matrix answer(this->cols_, this->rows_);
  for (int i = 0; i < this->rows_; i++)
    for (int j = 0; j < this->cols_; j++)
      answer.matrix[j][i] = this->matrix[i][j];
  return answer;
}
double Matrix::Determinant() {
  if (this->matrix == nullptr || this->rows_ <= 0 || this->cols_ <= 0 ||
      this->cols_ != this->rows_)
    throw std::invalid_argument(
        "It is impossible to find the determinant of this matrix.");
  return calculateDeterminantRecursively();
}
Matrix Matrix::CalcComplements() {
  if (this->matrix == nullptr || this->rows_ != this->cols_ ||
      this->rows_ < 1) {
    throw std::invalid_argument("Invalid matrix for calculating complements.");
  }
  Matrix result(this->rows_, this->cols_);
  if (this->rows_ > 1) {
    this->fillComplements(result);
  } else {
    result.matrix[0][0] = 1;
  }
  return result;
}
Matrix Matrix::InverseMatrix() {
  double det = this->Determinant();
  if (det == 0) {
    throw std::invalid_argument("Matrix is singular and cannot be inverted.");
  }
  Matrix cofactors = this->CalcComplements();
  Matrix adjugate = cofactors.Transpose();
  for (int i = 0; i < adjugate.rows_; i++) {
    for (int j = 0; j < adjugate.cols_; j++) {
      adjugate.matrix[i][j] /= det;
    }
  }
  return adjugate;
}