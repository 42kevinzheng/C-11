/* Copyright 2019  Jeremy S Lewis  CSCE240 */

#include <queue.h>

using std::list;

namespace csce240 {

Queue::Queue() : list<int>() { /* EMPTY */ }

void Queue::Push(int val) {
  push_front(val);
}

int Queue::Pop() {
  int tmp = back();
  pop_back();
  return tmp;
}

int Queue::Top() const {
  return back();
}

bool Queue::Empty() const {
  return empty();
}

std::ostream& Queue::Extract(std::ostream& out) const {
  for (auto cr_it = crbegin(); cr_it != crend(); ++cr_it)
    out << *cr_it << ' ';
  return out;
}

}  // csce240
