/*
*@Copyright 2019 
* Kevin Zheng 
* CSCE 240, Hw4 
*/

#include "../hw4/gradebook.h" //NOLINT


void GradeBook::Add(double grade) {
  grades_.push_back(grade);
}
double GradeBook::Get(size_t index) const {
  return index < grades_.size() ? grades_[index] : NAN;
}

double GradeBook::GetGPA() const {
    double total = 0;
    int siz = grades_.size();
    for (int i = 0; i < siz; ++i) {
          total +=grades_[i];
    }
    double result = total/siz;
    return result;
}

int GradeBook::GetSize() const {
int rr = grades_.size();
return rr;
}

double GradeBook::GetMax() const {
double max_score = 0;
int siz = grades_.size();
      for (int i = 0; i <siz; ++i) {
            if (max_score <= Get(i))
                max_score = Get(i);
      }
      return max_score;
}

/* Returns a new GradeBook instance with the floating point parameter
   * appended, increasing size by 1.
   *
   * Note: This is a very expensive operator (O(n) time) for what should be
   * near-constant process. Would be better implemented as operator+= which
   * requires Chapter 10.
   */
const GradeBook GradeBook::operator+(double rhs) const {
GradeBook tmp;
for (int i = 0; i < GetSize(); ++i) {
tmp.Add(Get(i));
}
tmp.Add(rhs);
return tmp;
}
 /* Adds two GradeBook instances together and returns their join as a new
   * object.
   * Order is maintained by adding the calling instance's grades to the new
   * Gradebook instance, followed by the parameter GradeBook's instances.
   */
const GradeBook GradeBook::operator+(const GradeBook& rhs) const {
GradeBook t;
for (int i = 0; i < GetSize(); ++i) {
t.Add(Get(i));
}
for (int i = 0; i < rhs.GetSize(); ++i) {
    t.Add(rhs.Get(i));
}
return t;
}
  /* Returns true when two GradeBook instances have the same average grade
   * value; returns false otherwise. An empty instance is treated as having an
   * average grade value of -infinity.
   * Equality should be true if the grades' average are within 0.00001 of each
   * other.
   */
bool GradeBook::operator==(const GradeBook& rhs) const {  // Done, but recheck
int siz = GetSize();
int sizz = rhs.GetSize();
double a = GetGPA();
double b = rhs.GetGPA();
double epi = 0.00001;
if ((siz == 0) || (sizz == 0)) {
    if ((siz == 0) && (sizz == 0)) {
        a = -1.0/0.0;
        b = -1.0/0.0;
    }
if (a == b) {
    return true;
} else {
    return false;
}
} else {
if ((fabs(a-b) < epi) || (fabs(b-a) < epi))
return true;
else
return false;
}
}

 /* Returns true when the double parameter is equal to the average of all the
   * grades stored in calling GradeBook instance. Treat average as -INFINITY if
   * calling instance is empty.
   * Equality should be true if the grade's instance are within 0.00001 of
   * floating point parameter.
   */
bool GradeBook::operator==(double rhs) const {  // Done, but recheck
int siz = GetSize();
double a = GetGPA();
double epi = 0.00001;
if (siz == 0) {
     a = -1.0/0.0;
}
if ((fabs(a-rhs) < epi) || (fabs(rhs-a) < epi))
return true;
else
return false;
}

  /* Returns true when the calling instance has a smaller grade average than the
   * paramter instance's average. If they are even, it compares their max
   * grades. An empty instance is treated as having an average grade value of
   * -infinity.
   */

bool GradeBook::operator<(const GradeBook& rhs) const {  // recheck THIS ONE.
  int one = GetSize();
  int two = rhs.GetSize();
  double oneGPA = GetGPA();
  double twoGPA = rhs.GetGPA();
if ((one == 0) || (two == 0)) {
    if (one == 0) {
       oneGPA = -1.0/0.0;
       if (oneGPA < twoGPA) {
          return true;
       } else {
          return false;
       }
    } else {
       return false;
    }
} else if (oneGPA < twoGPA) {
      return true;
} else if (oneGPA == twoGPA) {
double max_score = GetMax();
double max_score2 = rhs.GetMax();
    if (max_score < max_score2)
      return true;
    else
      return false;
  } else { return false; }
}
 /* Returns true when the calling instance has a smaller grade average than the
   * floating point parameter. 
   */
bool GradeBook::operator<(double rhs) const {
if(GetGPA() < rhs)
return true;
else
return false;
}
/* Returns a new GradeBook instance with the floating point parameter
 * appended.
 *
 * Note: This is a very expensive operator (O(n) time) for what should be
 * near-constant process. Would be better implemented as operator+= which
 * requires Chapter 10.
 */
// Outside the class gradebook
const GradeBook operator+(double lhs, const GradeBook& rhs) {
GradeBook tmp;
for (int i = 0; i < rhs.GetSize(); ++i) {
tmp.Add(rhs.Get(i));
}
tmp.Add(lhs);
return tmp;
}

/* Returns true when the double parameter is equal to the average of all the
 * grades stored in the GradeBook instance. Treat average as -INFINITY if
 * either GradeBook instance is empty.
 * Equality should be true if the grade's instance are within 0.00001 of
 * floating point parameter.
 */
bool operator==(double lhs, const GradeBook& rhs) {  // Done, recheck
int sizz = rhs.GetSize();
double b = rhs.GetGPA();
double epi = 0.00001;
if (sizz == 0) {
b = -1.0/0.0;
}
if ((fabs(b-lhs) < epi) || (fabs(lhs-b) < epi))
    return true;
else
    return false;
}
/* Returns true when the floating point parameter is less than the grade average
 * of the GradeBook parameter.
 */
bool operator<(double lhs, const GradeBook& rhs) {
if(lhs < rhs.GetGPA())
    return true;
else
    return false;
}
