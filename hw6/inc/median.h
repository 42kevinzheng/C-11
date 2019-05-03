/* This class inherits from the Statistic class such that it  may be used
 * polymorphically.
 */

/* Copyright 2019 Kevin Zheng hw6*/
#ifndef _BIN_MEDIAN_H_  //NOLINT  
#define _BIN_MEDIAN_H_  //NOLINT
#include <statistic.h>
#include <vector>
#include <algorithm>

namespace csce240 {
class Median:public Statistic {
 public:
std::vector<double> ok;
  Median();
  /* Stores data (datum) such than the median may be determined.
   */
  void Collect(double datum);

  /* Calculates the median of the data (datum) from the Collect method.
   */
  double Calculate() const;
};

}  // namespace csce240

#endif  //NOLINT

