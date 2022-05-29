// header guard
#ifndef NODE_H
#define NODE_H
#include <iostream>
#include "Student.h"

using namespace std;

class Node { // main class code
 public:
  // constructor
  Node(Student*);
  // destructor
  ~Node();
  // function prototypes
  Node* getNext(); // get next node pointer
  Student* getStudent(); // get student pointer
  void setNext(Node*); // set the next pointer to the corresponding node pointer
 private:
  // variables
  Student* student;
  Node* next;
};
#endif
// header guard end
