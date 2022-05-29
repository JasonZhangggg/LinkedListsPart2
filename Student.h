/*
Jason Zhang
12/19/2019
Linked Lists
*/

#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <cstring>

using namespace std;

class Student{
 public:
  //Student constructor
  Student(char*,char*, int, float);
  //get first name
  char* getFirstName();
  //get last name
  char* getLastName();
  //get id
  int getId();
  //get gpa
  float getGpa();
 private:
  //first name of student
  char* firstName;
  //last name of student
  char* lastName;
  //Id of student
  int id;
  //Gpa of student
  float gpa;
};
#endif
