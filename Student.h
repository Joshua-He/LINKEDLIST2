#include <iostream>
#ifndef STUDENT_H
#define STUDENT_H

/*
Header File for Student
Has Functions: createStudent, printStudent
 */
class Student{
 public:
  Student();
  ~Student();
  void createStudent();
  void printStudent();
  int getID();
  float getGPA();
 private:
  char first[80];
  char last[80];
  int id;
  float gpa;
};

#endif
