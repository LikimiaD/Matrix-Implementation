#ifndef MATRIX_H_
#define MATRIX_H_

#include <algorithm>
#include <cmath>
#include <iostream>
#include <stdexcept>

class Matrix {
 public:
  Matrix();
  Matrix(int rows, int cols);
  Matrix(const Matrix& other);
  ~Matrix();

  int get_rows() const;
  int get_cols() const;
  void set_size(int new_rows, int new_cols);

  bool EqMatrix(const Matrix& other);
  void SumMatrix(const Matrix& other);
  void SubMatrix(const Matrix& other);
  void MulNumber(const double num);
  void MulMatrix(const Matrix& other);

  Matrix Transpose();
  double Determinant();
  Matrix CalcComplements();
  Matrix InverseMatrix();

  Matrix& operator=(const Matrix& other);
  bool operator==(const Matrix& other);
  Matrix operator+(const Matrix& other) const;
  Matrix& operator+=(const Matrix& other);
  Matrix operator-(const Matrix& other) const;
  Matrix& operator-=(const Matrix& other);
  Matrix operator*(const double num) const;
  Matrix& operator*=(const double num);
  Matrix operator*(const Matrix& other) const;
  Matrix& operator*=(const Matrix& other);
  double& operator()(int i, int j);

 private:
  int rows_, cols_;
  double** matrix;

  void resizeMatrix(int new_rows, int new_cols);

  double** createTempMatrix(int rows, int cols);
  void mulTempMatrix(double** tmpMatrix, const Matrix& other);
  double calculateDeterminantRecursively();
  void fillComplements(Matrix& ptr);
  double calculateMinor(int i, int j);
};

#endif