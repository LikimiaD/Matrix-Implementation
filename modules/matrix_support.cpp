#include "../include/matrix.h"

void Matrix::resizeMatrix(int new_rows, int new_cols) {
  double** new_matrix = nullptr;
  if (new_cols > 0 && new_rows > 0) {
    new_matrix = new double*[new_rows];
    for (int i = 0; i < new_rows; ++i) {
      new_matrix[i] = new double[new_cols]{0};
    }

    int min_rows = std::min(new_rows, rows_);
    int min_cols = std::min(new_cols, cols_);
    for (int i = 0; i < min_rows; ++i) {
      for (int j = 0; j < min_cols; ++j) {
        new_matrix[i][j] = this->matrix[i][j];
      }
    }
  }

  for (int i = 0; i < rows_; ++i) {
    delete[] this->matrix[i];
  }
  delete[] this->matrix;

  this->matrix = new_matrix;
  this->rows_ = new_rows;
  this->cols_ = new_cols;
}
double Matrix::calculateDeterminantRecursively() {
  if (this->rows_ == 1) {
    return this->matrix[0][0];
  } else if (this->rows_ == 2) {
    return this->matrix[0][0] * this->matrix[1][1] -
           this->matrix[0][1] * this->matrix[1][0];
  } else {
    double result = 0.0;
    for (int j = 0; j < this->cols_; j++) {
      Matrix minor(this->rows_ - 1, this->cols_ - 1);
      for (int row = 1; row < this->rows_; row++) {
        for (int col = 0, minorCol = 0; col < this->cols_; col++) {
          if (col != j) {
            minor.matrix[row - 1][minorCol++] = this->matrix[row][col];
          }
        }
      }
      result +=
          (j % 2 == 0 ? 1 : -1) * this->matrix[0][j] * minor.Determinant();
    }
    return result;
  }
}
double** Matrix::createTempMatrix(int rows, int cols) {
  double** tmpMatrix = new double*[rows];
  for (int i = 0; i < rows; i++) {
    tmpMatrix[i] = new double[cols]{};
  }
  return tmpMatrix;
}
void Matrix::mulTempMatrix(double** tmpMatrix, const Matrix& other) {
  for (int i = 0; i < this->rows_; i++) {
    for (int j = 0; j < other.cols_; j++) {
      tmpMatrix[i][j] = 0;
      for (int k = 0; k < this->cols_; k++) {
        tmpMatrix[i][j] += this->matrix[i][k] * other.matrix[k][j];
      }
    }
  }
}
double Matrix::calculateMinor(int dodgeRow, int dodgeCol) {
  Matrix minor(this->rows_ - 1, this->cols_ - 1);
  for (int i = 0, minorRow = 0; i < this->rows_; ++i) {
    if (i == dodgeRow) continue;
    for (int j = 0, minorCol = 0; j < this->cols_; ++j) {
      if (j == dodgeCol) continue;
      minor.matrix[minorRow][minorCol++] = this->matrix[i][j];
    }
    ++minorRow;
  }
  return minor.Determinant();
}
void Matrix::fillComplements(Matrix& result) {
  for (int i = 0; i < this->rows_; ++i) {
    for (int j = 0; j < this->cols_; ++j) {
      double minorDet = this->calculateMinor(i, j);
      result.matrix[i][j] = ((i + j) % 2 == 0 ? 1 : -1) * minorDet;
    }
  }
}