/*
Jason Zhang
1/20/2020
LinkedLists part 2

Note: My partner forgot to set next to null in his Node.cpp constructor, so I added that into his Node.cpp code.
*/

#include <iostream>
#include <cstring>
#include <math.h>
#include "Student.h"
#include "Node.h"
using namespace std;

void printNode(Node*);
void printStudent(Student*);
void add(Student*, Node*&);
void deleteNode(int id, Node*&);
void printAverage(int count, float total, Node*);
void commands (char[], Node *&);
int main(){
  //only show 2 decimal points
  cout.setf(ios::showpoint);
  cout.setf(ios::fixed, ios::floatfield);
  cout.precision(2);
  //declare the head
  Node* head = NULL;
  //Main loop
  while(true){
    char input[80];
    cout<<"Input ADD to add a student, PRINT to print the students, DELETE to delete a student, AVERAGE to get the average GPA, and QUIT to exit the program."<<endl;
    //take in input
    cin.getline(input, sizeof(input));
    //set input to upper case
    for(int i = 0; i<sizeof(input); i++){
      input[i] = toupper(input[i]);
    }
    //if user types quit, return 0
    if(strcmp(input, "QUIT") == 0){
      return 0;
    }
    //otherwise check what command he ran, and run it
    commands(input, head);   
  }
}
void commands(char input[], Node* &head){
    //if they inputed ADD
    if(strcmp(input, "ADD") == 0){
      //promt first, last, Id, and GPA
      char first[80];
      char last[80];
      int id = 0;
      float gpa = 0;
      cout<<"What is the student's first name?"<<endl;
      cin.getline(first, 80);
      cout<<"What is the student's last name?"<<endl;
      cin.getline(last, 80);
      cout<<"What is the student's Id?"<<endl;
      cin>>id;
      cout<<"What is the student's GPA?"<<endl;
      cin>>gpa;
      //add a student
      add(new Student(first, last, id, gpa), head);
      cin.ignore(1000, '\n');
    }
    //if they inputed PRINT
    else if(strcmp(input, "PRINT") == 0){
      printNode(head);
    }
    //if they inputed DELETE
    else if(strcmp(input, "DELETE") == 0){
      //prompt for Id
      int id = 0;
      cout<<"What is the student's Id?"<<endl;
      cin>>id;
      //delete that id
      deleteNode(id, head);
      cin.ignore(1000, '\n');
    }
    //if they inputed AVERAGE
    else if(strcmp(input, "AVERAGE") == 0){
      printAverage(0, 0, head);
    }
    //otherwise input is invalid
    else{
      cout<<"That is invalid."<< endl;
    }
}

void add(Student* newStudent, Node* &head){
  //if list is empty add the student
  if(head == NULL){
    head = new Node(newStudent);
    return;
  }
  //check if the Id is less than the current Node, if it is, add the student before the current Node
  if(newStudent->getId() < head->getStudent()->getId()){
    Node* temp = new Node(newStudent);
    temp->setNext(head);
    head = temp;
    return;
  }
  if(head->getNext() != NULL){
    //check if the Id is less than the next node, if it is, add the student after the current Node
    if(newStudent->getId() < head->getNext()->getStudent()->getId()){
      Node* temp = new Node(newStudent);
      temp->setNext(head->getNext());
      head->setNext(temp);
      return;
    }
  }
  //Add to the end if the Id is the largest
  else{
    head->setNext(new Node(newStudent));
    return;
  }
  //recurse to next Node
  Node* next = head->getNext();
  add(newStudent, next);
}

void deleteNode(int id, Node* &head){
  //check if list is empty
  if(head == NULL){
    cout<<"The list is empty"<<endl;
    return;
  }
  //check if the current Id is equal to the one that needs to be deleted
  if(head->getStudent()->getId() == id){
    Node* temp = head->getNext();
    delete head;
    head = temp;
    return;
  }
  if(head->getNext() != NULL){
    //check if the next Id is the one that needs to be deleted
    if(head->getNext()->getStudent()->getId() == id){
      Node* temp = head->getNext();
      head ->setNext(head->getNext()->getNext());
      delete temp;
      return;
    }
  }
  //if we hit the end of the list, the id was not found
  else{
    cout<<"Id not found"<<endl;
    return;
  }
  //recurse to next Node
  Node* next = head->getNext();
  return deleteNode(id, next);
}

void printNode(Node* head){
  if(head != NULL){
    //print the student
    printStudent(head->getStudent());
    //recall print with next student in list 
    printNode(head->getNext());
  }
  
}

//print student formating
void printStudent(Student* student){
  cout<<"Student: "<<student->getFirstName()<<" "<<student->getLastName()<< ", Id: "<<student->getId()<<", GPA: "<<student->getGpa()<<endl;
}

void printAverage(int count, float total, Node*head){
  if(head!=NULL){
    //recursivly call printAverage and increase the count and total
    printAverage(++count, total+head->getStudent()->getGpa(), head->getNext());
  }
  //print once we reach the end of the list
  else{
    cout<<"The average GPA is: "<<total/count<<endl;
    return;
  }
}
