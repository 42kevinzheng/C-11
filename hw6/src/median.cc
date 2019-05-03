/* Copyright 2019 Kevin Zheng hw6*/
#include <median.h>
namespace csce240 {

Median::Median() {}

void Median::Collect(double datum) {
ok.push_back(datum);
}

double Median::Calculate() const {
std::vector<double> vec;
int n = ok.size();
for (int i = 0; i < n; ++i) {
vec.push_back(ok[i]);
}
if (vec.empty()) {
return 0;
} else {
        std::sort(vec.begin(), vec.end());
        if (vec.size() % 2 == 0)
                return (vec[vec.size()/2 - 1] + vec[vec.size()/2]) / 2;
        else
                return vec[vec.size()/2];
    }
}
}  // namespace csce240
