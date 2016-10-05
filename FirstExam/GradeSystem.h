/*
System for school grades
It uses a template Array and a Student class to keep track of student grades.

Arturo Burela A01019906
Fernando Alcántara A01019595
September 14, 2016

Partial_Evaluation_1

*/
#ifndef GS
#define GS

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <cstring>
#include "Student.h"
#include "Array.h"

using namespace std;

class GradeSystem 
{
private:
  Array<Student> * Students; //Array of objects from the class Student
  int NoOfStudents; //Number of registered students

public:
   GradeSystem(); //Constructor
   ~GradeSystem(); //Destructor
   void loadFile(); //This functions reads the file, intialize the array and enter the values to the Students Array
   void saveFile(); //This file saves the Students Array to the file
   void menu(); //Menu of the program
};

GradeSystem::GradeSystem() //Constructor of the GradeSystem class
{
  loadFile(); //Call the function to load data from the text file
  menu(); //Call the menu of the program
}

GradeSystem::~GradeSystem() //Destructor of the GradeSystem class
{
  delete Students; //free dynamic memory
  Students = NULL; //Point to NULL to avoid problems
}

void GradeSystem::loadFile() //Function to load the file
{   
  std::cout << "Loading data..." << std::endl;
  ifstream in_file; //File variable
  char line[128]; // aux to read lines
  int c= 0;   //Index for number of student data
  in_file.open("StudentData.txt");  //Open the file
  if(in_file.fail())  // If file not found exit the function and return to main menu
  {
    cout<<"No Data File Found"<<endl;
    return;
  }
  in_file.getline(line,sizeof(line)); //Get the first line
  string str(line);
  istringstream iss(str);
  iss>>NoOfStudents;  // The line is store as an int to know the number of student data
  Students = new Array<Student>(NoOfStudents);  //Create the number of students in the array
  Student tmp; //Temporary object of class student to load each one in the program
  for (int i = 0; i < NoOfStudents; i++) // For to go through each student
  {
    in_file.getline(line,sizeof(line));
    string str(line);
    istringstream iss(str);
    string name;
    iss >> name;  //Get the first word, that is the name of the student
    tmp.setName(name); //set the name to the temporary object of class student
    for (int j = 0; j < 6; j++) //For to load each grade and subject of the student into the temporary object
    {
      string subject;
      iss >> subject;
      int grade;
      iss >> grade;
      tmp.setGrade(grade,j);
      tmp.setSubject(subject,j);
    }
    Students->setElement(i,tmp); //Set the temporary object into the array of students
  }
  in_file.close(); //Close the text file
  std::cout << "Done" << std::endl;
  Students->quickSort(); //For sorting the students per average
}

void GradeSystem::saveFile()
{
  Students->quickSort();//First make sure the students are sorted, then save
  std::cout << "Saving!..." << std::endl;
  ofstream out_file;// Create an out file variable
  out_file.open("StudentData.txt");//Override the content
  out_file << NoOfStudents <<endl;//Insert the number of students
  for(int i=0; i<NoOfStudents; i++)//For each student repeat
  {
    out_file << Students->getElement(i).getName();//Save the Student name
    for (int j = 0; j < 6; j++) //Save each grade of the student in the same line
    {
      out_file << " " << Students->getElement(i).getSubject(j) << " " << Students->getElement(i).getGrade(j);
    }
    out_file << std::endl;// Add a endl to separate students
  }
  out_file << "EOF"<<endl;//Add an end of file indicator
  out_file.close();//Close the file
  std::cout << "Done...Goodbye" << std::endl;
}

void GradeSystem::menu() //Menu of the program
{ 
  char op='x'; //Variable to store the selected option
  std::cout << "Please select an option" << std::endl;
  std::cout << "a) Grades by student" << std::endl; //Show the grades per student
  std::cout << "b) Grades by subject" << std::endl; //Show the grades per subject
  std::cout << "c) List students (by average)" << std::endl; //Show students per average
  std::cout << "d) Modify grades" << std::endl; //Modify grades in a student
  std::cout << "e) Save and Exit" << std::endl; //Save changes to the information
  std::cin >> op; //Select an option
  if(op=='a')
  {
    int index;
    std::cout << "Select a student (by number):" << std::endl;
    for (int i = 0; i < NoOfStudents; i++) 
    {
      std::cout << i << " " << Students->getElement(i).getName() << std::endl; //Print all the students to choice
    }
    std::cin >> index;//Save the input value
    if(!std::cin.fail())//If cin to int do not fail, means its a number
    {
      if(index >=0 && index < NoOfStudents)//If the index is correct print
        {
          Students->getElement(index).printStudent();
          std::cin.clear();//Clear cin to avoid multiple function calling
          std::cin.ignore(256,'\n');// Ignore 256 characters to avoid multiple function calling
        }
        else //If is not correct send error and restart
        {
          std::cout << "\nIncorrect option\n" << endl;
          std::cin.clear();
          std::cin.ignore(256,'\n');
        }
    }
    else // If cin fails, ask to enter a number
    {
      std::cout << "Please enter a number" << std::endl;
      std::cin.clear();
      std::cin.ignore(256,'\n');
    }
    menu();//Return to menu after the operation
  }
  else if(op=='b')
  {
    int index;
    std::cout << "Select a subject (by number):" << std::endl;
    for (int i = 0; i < 6; i++) 
    {
      std::cout << i << " " << Students->getElement(0).getSubject(i) << std::endl; //Print subjects to choose
    }
    std::cin >> index;
    if(!std::cin.fail())//If cin fails then its not a number
    {
      if(index >= 0 && index < 6) //If the index is correct then print
      {
        cout << endl;
        for (int i = 0; i <NoOfStudents ; i++) 
        {
          std::cout << "Grade of "<< Students->getElement(i).getName() << ": " << Students->getElement(i).getGrade(index) << std::endl;
        }
        cout << endl;
        std::cin.clear();
        std::cin.ignore(256,'\n');
      }
      else //If not correct, send error message
      {
        std::cout << "\nIncorrect option\n" << endl;
        std::cin.clear();
        std::cin.ignore(256,'\n');
      }
    }
    else //If cin fails, ask for a number
    {
      std::cout << "Please enter a number" << std::endl;
      std::cin.clear();
      std::cin.ignore(256,'\n');
    }
    menu(); //Return to menu after the operation
  }
  else if(op=='c')
  {
    Students->quickSort(); //Make sure the students are sorted
    for (int i=0; i<NoOfStudents; i++) 
    {
      Students->getElement(i).printStudent(); //Print each student
    }
    std::cin.clear();// Clear to avoid problems
    std::cin.ignore(256,'\n');
    menu();//Return to menu
  }
  else if(op=='d')
  {
    int index; //Variable to store index
    std::cout << "Enter the student number(index) to modify:" << std::endl;
    for (int i = 0; i < NoOfStudents; i++) 
    {
      std::cout << i << " " << Students->getElement(i).getName() << std::endl; //Print all to choose
    }
    std::cin >> index;
    if(!std::cin.fail()) //If cin fails then its no a number
    {
      if(index >=0 && index < NoOfStudents) //If the index is correct assign grade
      {
        int grade;
        cout << endl;
        for (int i = 0; i < 6; i++)  //Repeat for every grade
        {
          std::cout << "Enter the grade (from 0 to 100) for: " << Students->getElement(index).getSubject(i) << std::endl;
          std::cin >> grade;
          if(!std::cin.fail()) //Again, if cin fails then its not a number
          {
            Student tmp;//Temporary student object to store the grade since we only may set student data type
            if(grade >= 0 && grade <= 100)
            {
              tmp = Students->getElement(index); //Copy the object
              tmp.setGrade(grade,i); //Modify the grade
              Students->setElement(index,tmp);//Set back the object to the array
              std::cin.clear();//Clear to avoid problems
              std::cin.ignore(256,'\n');
            }
            else //If the grade is beyond limits, assign 100 by default
            {
              cout << "\nThat grade is out of the school's scale, setting 100 by default\n" << endl;
              tmp = Students->getElement(index);
              tmp.setGrade(100,i);
              Students->setElement(index,tmp);
              std::cin.clear();
              std::cin.ignore(256,'\n');
            }
          }
          else // If cin fails ask for a number
          {
            std::cout << "Please enter a number" << std::endl;
            std::cin.clear();
            std::cin.ignore(256,'\n');
            i--;
          }
        }
      }
      else // Send error if option isnt valid
      {
        std::cout << "\nIncorrect option\n" << endl;
        std::cin.clear();
        std::cin.ignore(256,'\n');
      }
    }
    else //If cin fails, then ask for a number
    {
      std::cout << "Please enter a number" << std::endl;
      std::cin.clear();
      std::cin.ignore(256,'\n');
    }
    menu();//Return to menu
  }
  else if(op=='e')
  {
    saveFile(); //Call saveFile
    return;//Exit menu
  }
  else //If no valid option is selected, send error
  {
    std::cout << "Option doesn't exist, try again" << std::endl;
    std::cin.clear();//Clear to avoid problems
    std::cin.ignore(256,'\n');
    menu();//Return to menu
  }
}
#endif
