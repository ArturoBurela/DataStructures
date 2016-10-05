/*
System for school grades
It uses a template Array and a Student class to keep track of student grades.

Arturo Burela A01019906
Fernando Alcántara A01019595
September 14, 2016

Partial_Evaluation_1

*/
#ifndef S
#define S

#include <iostream>
#include <string>

using namespace std;

class Student{
public:
    int grades[6]; //Grades of the student
    string subjects[6]; //Subjects of the student
    string name; //Name of the student
    float averageGrade; //Average of grades

public:
    Student(); //Constructor of the class
    int getGrade(int i); //Function to return the grades array
    void setGrade(float g, int i); //Function to set a grade for the student
    string getSubject(int i); //Function to return the subjects array
    void setSubject(string s, int i); //Function to set a Subject for the student
    string getName(); //Function to return the name of the student
    void setName(string n); //Function to set the name of the Student
    void printStudent(); //Function to print the students and their grades
    bool operator< (const Student & other);
    bool operator> (const Student & other);
};


Student::Student() //Constructor of the class
{
    averageGrade = 0; // Set the average of the student to 0
}

int Student::getGrade(int i) //Function to return the grades array
{
    return grades[i]; //Return the array of grades from the student
}

void Student::setGrade(float g, int i) //Function to set a grade for the student
{
    grades[i] = g; //Set the Grade to the student in the wished index
    averageGrade = (grades[0]+grades[1]+grades[2]+grades[3]+grades[4]+grades[5])/6; //New average of the student
}

string Student::getSubject(int i) //Function to return the subjects array
{
    return subjects[i]; //Return the array of subjects from the student
}

void Student::setSubject(string s, int i) //Function to set a Subject for the student
{
    subjects[i] = s; //Set the Subject to the student in the wished index
}

string Student::getName() //Function to get the name of the student
{
    return name; //Return the name of the student
}

void Student::setName(string n)//Function to give the student a name
{
    name = n; //Set the name of the student
}

void Student::printStudent() //Function to print the student's information
{ 
    std::cout <<std::endl << name << std::endl; //Print the name
    std::cout << "Average: "<<averageGrade << std::endl; //Print the average
    for(int i=0;i<6;i++)  //Print the subjects and their grades
    {
        std::cout << subjects[i] << " ";
        std::cout << grades[i] << std::endl;
    }
    std::cout << std::endl;
}

bool Student::operator< (const Student & other)//Overload of < operator to be able to use quicksort to sort by average
{
  return (averageGrade < other.averageGrade);//Recieve the other average and compare, return true or false
}

bool Student::operator> (const Student & other)//Overload of > operator to be able to use quicksort to sort by average
{
  return (averageGrade > other.averageGrade);//Recieve the other average and compare, return true or false
}
#endif