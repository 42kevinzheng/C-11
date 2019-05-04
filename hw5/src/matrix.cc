/* Copyright 2019 Kevin Zheng CSCE240 Hw5*/
#include <matrix.h>

Matrix::Matrix() : m_(nullptr), rows_(0), cols_(0) {}

Matrix::Matrix(unsigned int rows, unsigned int cols) :
    rows_(rows), cols_(cols) {
  assert(rows > 0);  // assert preconditions are true
  assert(cols > 0);  // assert preconditions are true

  m_ = new double *[rows_];  // create array of double pointers
  for (unsigned int i = 0; i < rows_; ++i)
    m_[i] = new double[cols_];  // create array of doubles
}

Matrix::Matrix(const Matrix& that)
:rows_(that.getRows()), cols_(that.getCols()) {
    m_ = new double *[rows_];
  for (unsigned int i = 0; i < rows_; ++i)
    m_[i] = new double[cols_];
  for (unsigned int i = 0; i < rows_; ++i)
    for (unsigned int j = 0; j < cols_; ++j)
         m_[i][j] = that.m_[i][j];
}

Matrix::~Matrix() {
    if (m_) {
        for (unsigned i = 0; i < rows_; ++i)
            delete[] m_[i];
        delete[] m_;
    }
}

double Matrix::Get(unsigned int row, unsigned int col) const {
    if (row <= rows_  && col <= cols_)
        return m_[row][col];
    else
        return 0;
}

const Matrix& Matrix::operator=(const Matrix& rhs) {
       if ((cols_ != rhs.cols_) || (rows_ != rhs.rows_)) {
             if (m_) {
       for (unsigned i = 0; i < rows_; ++i)
          delete[] m_[i];
       delete[] m_;
        }
          m_ = new double *[rhs.rows_];
    for (unsigned int i = 0; i < rhs.rows_; ++i)
    m_[i] = new double[rhs.cols_];
        }
        rows_ = rhs.rows_;
        cols_ = rhs.cols_;
  for (unsigned int i = 0; i < rows_; ++i) {
    for (unsigned int j = 0; j < cols_; ++j)
         m_[i][j] = rhs.m_[i][j];
  }
    return *this;
}

const Matrix& Matrix::operator*=(double rhs) {
  for (unsigned int i = 0; i < rows_; ++i)
    for (unsigned int j = 0; j < cols_; ++j)
         m_[i][j] *=rhs;
return *this;
}

const Matrix Matrix::operator+(const Matrix& rhs) const {
unsigned int rr = rhs.rows_;
unsigned int cc = rhs.cols_;
unsigned int r = rows_;
unsigned int c = cols_;
  if ((r != rr) || (c !=cc)) {
    r = rr;
    c = cc;
  }


Matrix lhs(r, c);
for (unsigned int i = 0; i < rr; ++i) {
    for (unsigned int j = 0; j < cc; ++j) {
          lhs.m_[i][j] = m_[i][j] + rhs.m_[i][j];
}
}
return lhs;
}
