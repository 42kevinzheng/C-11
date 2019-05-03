/* Copyright 2019 Kevin Zheng hw6*/

#include <mean.h>
#include <vector>



namespace csce240 {
Mean::Mean() { }


void Mean::Collect(double datum) {
push_back(datum);
}
double Mean::Calculate() const {
int total = 0;
double sum = 0;
for (unsigned i = 0; i <size(); ++i) {
sum += at(i);
++total;
}
double result = sum/total;
return result;
}

}  // namespace csce240
