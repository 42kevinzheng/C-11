/*
*@Copyright 2019 
* Kevin Zheng 
* CSCE 240, Hw3 
*/
#include "./gradebook.h" //NOLINT

GradeBook tmp;
void GradeBook::Add(double grade) {
ok.push_back(grade);
}
double GradeBook::Get(size_t index) const {
    int siz = ok.size() -1;
    int dex = index;
    if (dex <= siz)
        return ok[index];
    else
        return NAN;
}
const GradeBook GradeBook::Add(const GradeBook& that) const {
      int siz = that.ok.size();
for (int i = 0; i < siz; ++i) {
    tmp.ok.push_back(that.Get(i));
}
return GradeBook(tmp);
}
double GradeBook::GetGPA() const {
int rt = ok.size();
if (rt == 0) {
return NAN;
}
    double total = 0;
    int index = 0;
    int siz = ok.size();
    for (int i = 0; i < siz; ++i) {
          total +=ok[i];
          ++index;
    }
    double result = total/index;
    return result;
}
    double GradeBook::GetMax() const {
      int siz = ok.size();
if (siz == 0) {
return NAN;
}
      double max_score = 0;
      for (int i = 0; i <siz; ++i) {
            if (max_score <= ok[i])
                max_score = ok[i];
      }
      return max_score;
    }
  const size_t GradeBook::GetSize() const {
      return ok.size();
}




bool GradeBook::Equals(const GradeBook& that) const {
int siz = ok.size();
int sizz = that.ok.size();
double epi = 0.00001;
double a = GetGPA();
double b = that.GetGPA();

if ((siz == 0) || (sizz ==0)) {
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
if ((fabs(a-b) < epi) || (fabs(b-a) < epi)) {
return true;
} else { return false; }
}
}

bool GradeBook::LessThan(const GradeBook& that) const {
  int one = ok.size();
  int two = that.ok.size();
  double oneGPA = GetGPA();
  double twoGPA = that.GetGPA();
if ((one == 0) || (two == 0)) {
if (one == 0) {
oneGPA = -1.0/0.0;
if(oneGPA < twoGPA)
return true;
else
return false;
} else {
return false;
}
} else if (oneGPA < twoGPA) {
return true;
} else if (oneGPA == twoGPA) {
double max_score = 0;
double max_score2 = 0;
for (int i = 0; i < one; ++i) {
if(ok[i] >= max_score)
max_score = ok[i];
}
for (int i = 0; i < two; ++i) {
if(that.ok[i] >= max_score2)
max_score2 = that.ok[i];
}
    if (max_score < max_score2)
      return true;
    else
      return false;
  } else { return false; }
}








