/* Copyright 2019  Jeremy S Lewis  CSCE240 */
#ifndef _LECT_CHP15_INC_QUEUE_H_  //NOLINT
#define _LECT_CHP15_INC_QUEUE_H_  //NOLINT

#include <list>
#include <ostream>

#include <ppt.h>

namespace csce240 {

class Queue : public std::list<int>, public PPT {
 public:
  Queue();

  void Push(int val);

  int Pop();

  int Top() const;

  bool Empty() const;

  std::ostream& Extract(std::ostream&) const;
};

}  // namespace csce240
#endif
