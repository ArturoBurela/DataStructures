#include<iostream>
#include<string>
#include "LinkedList.h"
#include "Vector3D.h"

void listTest();
Vector3D vectorAddition(const LinkedList<Vector3D> & vector_list);

int main(){
  listTest();
  return 0;
}

void listTest(/* arguments */) {
  Vector3D result;
  //Create the list that holds the vectors
  LinkedList<Vector3D> vector_list;
  vector_list.insertTail(Vector3D(3.6,7.2,8.1));
  vector_list.insertTail(Vector3D(7.12,23.54,34.2));
  vector_list.insertTail(Vector3D(232,23,234123));
  vector_list.printList();

  result = vectorAddition(vector_list);
  std::cout << "The addition of all vectors is: " << result << std::endl;

}

Vector3D vectorAddition(const LinkedList<Vector3D> & vector_list){
  Vector3D result;
  for (int i = 0; i < vector_list.getLength(); i++) {
    result += vector_list.getDataAtPosition(i);
  }
  return result;
}
