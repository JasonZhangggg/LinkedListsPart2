/*
Jason Zhang
12/19/2019
Linked Lists
*/
#include <iostream>
#include <cstring>
#include "Student.h"

using namespace std;

Student::Student(char* newFirst, char* newLast, int newId, float newGpa){
  firstName = new char[strlen(newFirst)+1];
  lastName = new char[strlen(newLast)+1];
  //set the first name
  strcpy(firstName, newFirst);
  //set the last name
  strcpy(lastName, newLast);
  //set the id
  id = newId;
  //set the gpa
  gpa = newGpa;
}
//get the student's first name
char* Student::getFirstName(){
  return firstName;
}
//get the student's last name
char* Student::getLastName(){
  return lastName;
}
//get the student's Id
int Student::getId(){
  return id;
}
//get the student's gpa
float Student::getGpa(){
  return gpa;
}
