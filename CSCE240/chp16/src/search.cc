/* Copyright 2019 Jeremy S Lewis CSCE 240 */
#include <cassert>
// using assert
#include <cmath>
// using log2
#include <cstdlib>
// using atoi
#include <iostream>
using std::cout;
using std::endl;

#include <ppt.h>
#include <queue.h>
#include <stack.h>

namespace b_tree {
const unsigned char kRoot = 0; // global root of all trees

inline size_t left_child(size_t root) {
  return 2*root + 1;
}

inline size_t right_child(size_t root) {
  return 2*root + 2;
}

class BinaryTreeOperation {
 public:
  BinaryTreeOperation(const int* tree) : tree_(tree) { /* EMPTY */ }
  virtual ~BinaryTreeOperation() { /* EMPTY */ }

  virtual bool Operate(int index) = 0;
 protected:
  const int *tree_;
};

class BinaryTreeSearch : public BinaryTreeOperation {
 public:
  BinaryTreeSearch(const int* tree, int search_value)
      : BinaryTreeOperation(tree), search_value_(search_value),
        index_(0), found_(false) { /* EMPTY */ }

  bool Operate(int index) {
    if (tree_[index] == search_value_) {
      index_ = index;
      found_ = true;
      return true;
    }
    return false;
  }
 private:
  int search_value_;
  unsigned int index_;
  bool found_;
};

}  // namespace b_tree


/* Visits each node in a tree breadth-first.
 *
 * tree: a binary tree stored in an array
 * t_size: number of elems in tree
 */
void QSearch(const int* tree, const size_t t_size, csce240::PPT* Q,
    BinaryTreeOperation* op) {
  size_t comparisons = 0;

  Q->Push(b_tree::kRoot);
  do {
    size_t curr_ind = Q->Pop();
    // if the top of the Q is matches search val, return index
    ++comparisons;
    if (op->Operate(curr_index))
      break;

    // when current root has left child, process with Q
    if (b_tree::left_child(curr_ind) < t_size)
      Q->Push(b_tree::left_child(curr_ind));

    // when current root has right child, process with Q
    if (b_tree::right_child(curr_ind) < t_size)
      Q->Push(b_tree::right_child(curr_ind));

  } while (!Q->Empty());

  cout << "comparisons: " << comparisons << endl;
}


int main(int argc, char* argv[]) {
  const int kIndexSearchVal = 1;  // index of search value in argument list
  assert(1 < argc);  // avoid segfaults
  int value = atoi(argv[kIndexSearchVal]);  // get int value of argument string

  const int tree[] = {
        0,   7,  11,  13, 17, 23, 29, 31, 37, 41, 43, 47, 51,
       57,  59,  61,  67, 71, 73, 79, 83, 87, 91, 93, 97, 99,
      101, 107, 111, 117
  };
  const size_t t_size = sizeof(tree)/sizeof(int);

  csce240::PPT *ppt_ptr = new csce240::Queue();
  b_tree::BinaryTreeSearch op(tree, value);
  QSearch(tree, t_size, value, ppt_ptr, &op);
  cout << "Breadth-First Search Index of " << value << ": " << index << endl;
  delete ppt_ptr;

  //ppt_ptr = new csce240::Stack();
  //index = QSearch(tree, t_size, value, ppt_ptr);
  //cout << "Depth-First Search Index of " << value << ": " << index << endl;
  //delete ppt_ptr;

  return 0;
}


/* Abstract Classes

class Printer : public BinaryTreeOperation {
 public:

  bool Operate(int index) {
    return false;
  }
};
*/
