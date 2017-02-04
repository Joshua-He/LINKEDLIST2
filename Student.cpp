#include <iostream>
#include "Student.h"
#include <iomanip>

using namespace std;

//Constructor
Student::Student(){
  first[0] = '\0';
  last[0] = '\0';
  id = 0;
  gpa = 0;
}

//Deconstructor
Student::~Student(){
 
}

//Create Student; Enter Information
void Student::createStudent(){
  cin.ignore();
  cout << "Enter first name" << endl;
  cin.getline(first, 80);
  cout << "Enter last name" << endl;
  cin.getline(last, 80);

  cout << "Enter id" << endl;
  cin >> id;
  cin.ignore();
  
  cout << "Enter gpa" << endl;
  cin >> gpa;
  cin.ignore();
  
}

//Print Student; Prints student info
void Student::printStudent() {
  cout << "Student: " << first << " " << last << ", ID: " << id << ", GPA: " << setprecision(2) << fixed << gpa << endl;
}

int Student::getID(){
  return id;
}
float Student::getGPA(){
  return gpa;
}
