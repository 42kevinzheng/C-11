/* Copyright 2019 Jeremy S Lewis CSCE240 */

namespace csce240 {

template <class T>
PPT<T>::~PPT() { /* EMPTY */ }

template <class T>
std::ostream& operator<<(std::ostream& lhs, const PPT<T>& rhs) {
  return rhs.Extract(lhs);
}

}  // namespace csce240

#include <ppt.h>
