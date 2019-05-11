/* Copyright 2019 Kevin Zheng Hw7*/

#ifndef _inc_matrix_h_  //NOLINT
#define _inc_matrix_h_  //NOLINT


#include <cassert>
// using assert
#include <ostream>

class MatrixTester;

template <class T>
class Matrix {
 public:
  friend class MatrixTester;

  Matrix();  //  for testing, useless in practice
  Matrix(unsigned int rows, unsigned int cols);

  /* Copy Constructor: 2 Points
   *   Performs deep copy.
   */
  Matrix(const Matrix<T>& that);


  /* Destructor: Required For Any Points
   *   Cleans up memory to avoid leaks
   */
  ~Matrix();


  /* Accessor: 1 Point
   *   Precondition(s):
   *   - Parameter row is less than rows in matrix
   *   - Parameter col is less than cols in matrix
   *   Returns matrix element from row and col. Type is same as matrix type.
   */
  T Get(unsigned int row,  unsigned int col) const;


  /* Assignment Op: 2 Points
   *   Precondition(s):
   *   - lhs rows must equal rhs rows
   *   - lhs cols must equal rhs cols
   *   Performs deep copy.
   */
  const Matrix<T>& operator=(const Matrix<T>& rhs);


  /* Times Equals Op: 1 Point
   *   Returns calling object with matrix scaled by rhs.
   *   Parameter:
   *    - rhs will be the same type as the matrix
   */
  const Matrix<T>& operator*=(T rhs);


  /* Add Op: 1 Point
   *   Returns the sum of calling object's matrix and rhs's matrix as a new
   *   object.
   * Precondition(s):
   *   - lhs rows must equal rhs rows
   *   - lhs cols must equal rhs cols
   */
  const Matrix<T> operator+(const Matrix<T>& rhs) const;


 private:
    T **m_;
    unsigned int rows_;
    unsigned int cols_;
};









template <class T>
Matrix<T>::Matrix() : m_(nullptr), rows_(0), cols_(0) {}


template <class T>
Matrix<T>::Matrix(unsigned int rows, unsigned int cols) :
    rows_(rows), cols_(cols) {
  assert(rows > 0);
  assert(cols > 0);

  m_ = new T *[rows_];
  for (unsigned int i = 0; i < rows_; ++i)
    m_[i] = new T[cols_];
}



template <class T>
Matrix<T>::Matrix(const Matrix<T>& that)
:rows_(that.rows_), cols_(that.cols_) {
    m_ = new T *[rows_];
  for (unsigned int i = 0; i < rows_; ++i)
    m_[i] = new T[cols_];
  for (unsigned int i = 0; i < rows_; ++i)
    for (unsigned int j = 0; j < cols_; ++j)
         m_[i][j] = that.m_[i][j];
}

template <class T>
Matrix<T>::~Matrix() {
    if (m_) {
        for (unsigned i = 0; i < rows_; ++i)
            delete[] m_[i];
        delete[] m_;
    }
}


template <class T>
T Matrix<T>::Get(unsigned int row, unsigned int col) const {
    if (row <= rows_  && col <= cols_)
        return m_[row][col];
    else
        return 0;
}



template <class T>
const Matrix<T>& Matrix<T>::operator=(const Matrix<T>& rhs) {
    if ((cols_ != rhs.cols_) || (rows_ != rhs.rows_)) {
             if (m_) {
       for (unsigned i = 0; i < rows_; ++i)
          delete[] m_[i];
       delete[] m_;
        }
          m_ = new T *[rhs.rows_];
    for (unsigned int i = 0; i < rhs.rows_; ++i)
    m_[i] = new T[rhs.cols_];
        }
        rows_ = rhs.rows_;
        cols_ = rhs.cols_;
  for (unsigned int i = 0; i < rows_; ++i) {
    for (unsigned int j = 0; j < cols_; ++j)
         m_[i][j] = rhs.m_[i][j];
  }
    return *this;
}

template <class T>
const Matrix<T>& Matrix<T>::operator*=(T rhs) {
        for (unsigned int i = 0; i < rows_; ++i)
    for (unsigned int j = 0; j < cols_; ++j)
         m_[i][j] *=rhs;
return *this;
}

template <class T>
const Matrix<T> Matrix<T>::operator+(const Matrix<T>& rhs) const {
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

#endif //NOLINT