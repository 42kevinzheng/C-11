/* Copyright 2019  Jeremy S Lewis  CSCE240 */
#ifndef _LECT_CHP15_INC_STACK_H_  //NOLINT
#define _LECT_CHP15_INC_STACK_H_  //NOLINT


#include <list>
#include <ostream>
#include <vector>

#include <ppt.h>

namespace csce240 {

template <class T>
class Stack : public std::vector<T>, public PPT<T> {
 public:
  Stack();

  void Push(T);

  T Pop();

  T Top() const;

  bool Empty() const;

  std::ostream& Extract(std::ostream&) const;
};

}

#include <stack.cc>

#endif  //NOLINT
