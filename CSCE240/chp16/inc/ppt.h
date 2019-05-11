/* Copyright 2019 Jeremy S Lewis CSCE240 */
#ifndef _LECT_CHP15_PPT_H_  //NOLINT  
#define _LECT_CHP15_PPT_H_  //NOLINT

#include <ostream>

namespace csce240 {

template <class T>
class PPT {
 public:
  virtual ~PPT();
  virtual void Push(T) = 0;
  virtual T Pop() = 0;
  virtual T Top() const = 0;
  virtual bool Empty() const = 0;

  virtual std::ostream& Extract(std::ostream&) const = 0;
};

template <class T>
std::ostream& operator<<(std::ostream&, const PPT<T>&);

}  // namespace csce240

#include <ppt.cc>

#endif  //NOLINT
