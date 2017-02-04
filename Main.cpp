#include <iostream>
#include <string.h>
#include "Student.h"
#include "Node.h"
#include <iomanip>

using namespace std;


/*
Joshua He 
This is the Student List program using LinkedLists. 
There are five functions: 
ADD - Adds a student to the list
DELETE - Deletes a student from the list
PRINT - Prints the information of all students in the list
AVERAGE - Averages the GPA of all students in the list
QUIT - Quits the program
 */

// function prototyping
void deleteID(Node* &head, int idNumber);
void averageList(Node* head);
void addList(Node* n, Node* &head);
void printList(Node* pointer);


int main(){
  Node* head = NULL;
  char input[100];
  int  in_loop = 1;
  int idNumber = 0;
  
  cout << "Welcome to StudentList (LinkedLIST V1.21 VOLTA)! The four commands are:" << endl;

  cout << "  ADD (Adds a student)" << endl;
  cout << "  DELETE (Delete a student)" << endl;
  cout << "  PRINT (Prints all the students)" << endl;
  cout << "  AVERAGE (Averages the GPA of all students)" << endl;
  cout << "  QUIT (Quits program)" << endl << endl;

  // while loop to take commands
  while (in_loop == 1) {
    cout << endl << "please input your command: "; 
    cin >> input; 
    
    if (strcmp(input, "QUIT") == 0){
      in_loop =0;
    }

    // add to list
    if (strcmp(input, "ADD") == 0){
      Student* s = new Student;
      s->createStudent();
      Node* n = new Node(s);
      addList(n, head);
    }

    // print list
    if (strcmp(input, "PRINT") == 0){
      printList(head);
    }

    // find average
    if (strcmp(input, "AVERAGE") == 0){
      averageList(head);
    }

    // delete from list
    if (strcmp(input, "DELETE") == 0){
      cout << "Enter id of student you want to delete" << endl;
      cin >> idNumber;
      deleteID(head, idNumber);
    }
  }
}

//Adds student to the studentlist recursively, in increasing order
void addList(Node* n, Node* &head){
  if (head == NULL){
    head = n;
    return;
  }
  if (n->getStudent()->getID() < head->getStudent()->getID()) {
    n->setNext(head);
    head = n;
  }
  else  // add n to the list that starts with nptr (sublist)
    {
      Node* nptr = head->getNext(); 
      addList(n, nptr);  // recursive call
      head->setNext(nptr);
    }
}

//Prints student information recursively
void printList(Node* pointer){
  if (pointer != NULL){
    pointer->getStudent()->printStudent();
    printList(pointer->getNext());  //Recursive call
  }
}

//Averages all student GPAs
void averageList(Node* head){
  float total = 0;
  int number = 0;
  Node* temp = head;
  float average = 0;
  if(head == NULL){
    cout << "There are no students" << endl;
    return;
  }
  while(temp != NULL){
    total = total + temp->getStudent()->getGPA();
    number++;
    temp = temp->getNext();
  }
  average = total/number;
  cout << "Average: " << setprecision(2) << fixed << average << endl;
}

//Deletes the inputted ID recursively
void deleteID(Node* &head, int idNumber){
  Node* temp; 
  if (head == NULL){
    cout << "There are no students to delete" << endl;
    return;
  }

  // if the head is the node to delete
  if (head->getStudent()->getID() == idNumber){
    temp = head;
    head = head->getNext();
    delete temp;    // deconstruct
    cout << "Student with ID " << idNumber << " was deleted" << endl;
    return;
  }
  else  // delete idNumber in the sublist
    {
      temp = head->getNext();
      deleteID(temp, idNumber); //Recursive call
      head->setNext(temp); 
    }  
  
}
