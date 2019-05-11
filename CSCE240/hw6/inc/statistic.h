/* This is an abstract base class which Statistic classes extend.
 */
/* Copyright 2019 Kevin Zheng hw6*/
#ifndef _BIN_STATISTIC_H_  //NOLINT  
#define _BIN_STATISTIC_H_  //NOLINT

namespace csce240 {
class Statistic {
 public:
  /* Not a pure virtual so that children may not override if unused
   */
  virtual ~Statistic() {}

  /* Defined by children
   */
  virtual void Collect(double) = 0;

  /* Defined by children
   */
  virtual double Calculate() const = 0;
};
}  // namespace csce240

#endif //NOLINT
