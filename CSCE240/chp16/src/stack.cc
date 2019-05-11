/* Copyright 2019  Jeremy S Lewis  CSCE240 */

namespace csce240 {

template <class T>
Stack<T>::Stack() { /* EMPTY */ }

template <class T>
void Stack<T>::Push(T value) {
  std::vector<T>::push_back(value);
}

template <class T>
T Stack<T>::Pop() {
  int tmp = std::vector<T>::back();
  std::vector<T>::pop_back();
  return tmp;
}

template <class T>
T Stack<T>::Top() const {
  return std::vector<T>::back();
}

template <class T>
bool Stack<T>::Empty() const {
  return std::vector<T>::empty();
}

template <class T>
std::ostream& Stack<T>::Extract(std::ostream& out) const {
  for (unsigned int i = std::vector<T>::size() - 1; i >= 0; --i)
    out << std::vector<T>::at(i) << ' ';
  return out;
}

}  // namespace csce240
