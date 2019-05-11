/* Copyright 2019  Jeremy S Lewis  CSCE240 */


#include <iostream>
using std::cout;
using std::cin;
using std::endl;
#include <ostream>
using std::ostream;
#include <vector>
using std::vector;

#include <stack.h>
using csce240::Stack;


void PrintStack(Stack<int>* stack) {
  while (!stack->Empty())
    cout << stack->Pop() << ' ';
}

void FillStack(unsigned int size, Stack<int>* stack) {
  for (unsigned int i = 0; i < size; ++i)
    stack->Push(i + 1);
}

ostream& operator<<(ostream& lhs, const vector<int>& rhs) {
  for (auto it = rhs.begin(); it != rhs.end(); ++it)
    lhs << *it << " ";
  return lhs;
}

void FillVector(unsigned int size, vector<int>* vec) {
  for (unsigned int i = 0; i < size; ++i)
    vec->push_back(i + 1);
}


int main(int argc, char* argv[]) {
  vector<int> int_vector;
  Stack<int>* int_stack;

  FillVector(10, &int_vector);

  cout << int_vector << endl;

  cout << "Testing Stack:" << endl;
  int_stack = new Stack<int>();
  FillStack(10, int_stack);
  cout << *int_stack << endl;

  delete int_stack;
  return 0;
}
