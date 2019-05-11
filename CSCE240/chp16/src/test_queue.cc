/* Copyright 2019  Jeremy S Lewis  CSCE 240 */

#include <iostream>
using std::cout;
using std::cin;
using std::endl;
#include <list>
using std::list;
#include <ostream>
using std::ostream;

#include <queue.h>
using csce240::Queue;


void PrintQueue(Queue* queue) {
  while (!queue->Empty())
    cout << queue->Pop() << ' ';
}

ostream& operator<<(ostream& lhs, const list<int>& rhs) {
  for (auto it = rhs.begin(); it != rhs.end(); ++it)
    lhs << *it << ' ';
  return lhs;
}

void FillList(unsigned int size, list<int>* list) {
  for (unsigned int i = 1; i < size+1; ++i)
    list->push_back(i);
}

int main(int argc, char* argv[]) {
  list<int> int_list;
  Queue *queue;

  FillList(10, &int_list);
  cout << "list: " << int_list << endl;

  cout << "Test Queue:" << endl;
  queue = new Queue(int_list);
  cout << *queue << endl;

  delete queue;
  return 0;
}
