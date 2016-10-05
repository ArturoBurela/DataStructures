/*
	Arturo Burela
  A01019906
*/
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;
template <class T>
class Array {
  private:
    int size;
    T * elements;
    void swap(T * a, T * b);
    int binarySearchRecursive(T item, int start, int end);
    void quickSortRecursion(int start, int end);
    int quickSortPartitionHoare(int start, int end);
    int quickSortPartitionLomuto(int start, int end);
    void mergeSortRecursive(int left_index, int right_index);
    void merge(int left_index, int middle, int right_index);
  public:
    //Cosntructor
    Array(int n);
    //Destructor
    ~Array();
    //Other
    void fillOrdered();
    void fillRandom();
    void printRecursive(int n);
    //Searching
    bool linearSearch(T item);
    bool binarySearchIterative(T item);
    int binarySearchRecursive(T item);
    //Sorting
    void bubbleSort();
    void selectionSort();
    void insertionSort();
    void quickSort();
    void mergeSort();
};
Array::Array (int n) {
  srand (time(NULL));
  elements = new T [n];
  size = n;
}
Array::~Array () {
  delete [] elements;
}
void Array::fillOrdered() {
  int step=10;
  for (size_t i = 0; i < size; i++) {
    elements[i]=rand()%100+step;
    step=elements[i];
  }
}
void Array::fillRandom() {
  for (size_t i = 0; i < size; i++) {
    elements[i]=rand()%1000;
  }
}
void Array::printRecursive(int n) {
  cout << elements[n] << endl;
  if(n<size-1){printRecursive(n+1);}
}
bool Array::linearSearch(T item){
  for (size_t i = 0; i < size; i++) {
    if(elements[i]==item){
      return true;
    }
  }
  return false;
}
bool Array::binarySearchIterative(T item){
  int start = 0;
  int end = size -1;
  int middle;
  while (start<=end) {
    middle=(start+end)/2;
    if(item<elements[middle]){end=middle-1;}
    else if(item>elements[middle]){start = middle+1;}
    else{return true;}
  }
  return false;
}
int Array::binarySearchRecursive(int item){
  return binarySearchRecursive(item,0,size-1);
}
int Array::binarySearchRecursive(T item, int start, int end){
  //Base case
  if(start>end){return -1;}
  int middle=(start+end)/2;
  if(item<elements[middle]){return binarySearchRecursive(item,start,middle-1);}
  else if(item>elements[middle]){return binarySearchRecursive(item,middle+1,end);}
  else{return middle;}
}
/*void Array::swap(int * a, int * b){
  int tmp = * a;
  *a = *b;
  *b = tmp;
}
void Array::bubbleSort() {
  for (size_t i = 0; i < size; i++) {
    for (size_t j = 0; j < size-i; j++) {
      if (elements[j]<elements[j-1]) {
        swap(&elements[j],&elements[j-1]);
      }
    }
  }
}
void Array::selectionSort(){
  int min_index = 0;
  //Find the element in each index.
  for (size_t i = 0; i < size; i++) {
    //Store the min_index for the next loop
    min_index = i;
    for (size_t j = i+1; j < size; j++) {
      //If the elements min index is greater then update the index
      if(elements[j]<elements[min_index]){min_index=j;}
    }
    //After all the loop we swap according to the index
    swap(&elements[i],&elements[min_index]);
    }
}
void Array::insertionSort(){
  //Variable to store the selected item value
  int selected_item;
  //We suppose that the first element is sorted, so i = 1
  for (size_t i = 1; i < size; i++) {
    //Get the value of the element to sort
    selected_item = elements[i];
    //We start a loop from the last sorted (i) to the start of the Array
    for (size_t j = i; j < size; j--) {
      //std::cout << "Entró" << std::endl;
      //If the selected index (j) is lesser than the last sorted item (i), move i to the right
      if(selected_item<elements[j-1]){
        //std::cout << "El índice es : " << j << "SWAP"<< std::endl;
        elements[j]=elements[j-1];
      }else{
        //If it is not lesser then the rest of the Array is sorted, we insert the value and cut the loop
        elements[j]=selected_item;
        break;
      }
    }
  }
}
void Array::quickSort(){
  quickSortRecursion(0,size-1);
}
void Array::quickSortRecursion(int start, int end){
  if(start < end){
    //int pivot = quickSortPartitionLomuto(start,end);
    //int pivot = quickSortPartitionHoare(start,end);
  }
}
int Array::quickSortPartitionLomuto(int start, int end){
  int pivot_value = elements[end];
  int pivot_index = 0;
}
int Array::quickSortPartitionHoare(int start, int end){

}*/
void Array::mergeSort(){
  //Initiate the sorting with the values of the Array
  mergeSortRecursive(0,size-1);
}
void Array::mergeSortRecursive(int left_index, int right_index){
  //If the index are equal or have changed then the sort is complete
  if (left_index < right_index)
  {
    //Determine the middle of the Array
    int middle =(right_index+left_index)/2;
    // Call the same funtion to each half
    mergeSortRecursive(left_index, middle);
    mergeSortRecursive(middle+1, right_index);
    //After the calls do the merge, so the "deeper" partitions are sorted first
    merge(left_index, middle, right_index);
  }
}
void Array::merge(int left_index, int middle, int right_index){
  int i, j, k;
  //Determine the size of each partition
  int size1 = middle - left_index + 1;
  int size2 =  right_index - middle;
  //Create the two partitions
  int LP[size1], RP[size2];
  //Fill each part
  for (size_t i = 0; i < size1; i++){
    LP[i] = elements[left_index + i];
  }
  for (size_t i = 0; i < size2; i++) {
    RP[i] = elements[middle + 1+ i];
  }
  //Merge the new partitions
  i = 0; // aux index for left partition
  j = 0; // aux index for right partition
  k = left_index; // aux index for the main array because the left_index is the smaller index
  while (i < size1 && j < size2){//Repeat until the indexes are equal to the size of each partition
    if (LP[i] <= RP[j]){//If the left element is smaller than the right one
      elements[k] = LP[i];//Then put that value in the main array
      i++;//Add one to the left partition
    }
    else{//If not then insert the value from the left
      elements[k] = RP[j];
      j++;//Add one to the right partition
    }
    k++;//Add one to the main array
  }
  while (i < size1){//If the previos while stops by action of the right partition, then copy the rest of the left elements
    elements[k] = LP[i];
    i++;//Add one to the left partition
    k++;//Add one to the main array
  }
  while (j < size2){//If the previos while stops by action of the left partition, then copy the rest of the right elements
    elements[k] = RP[j];
    j++;//Add one to the right partition
    k++;//Add one to the main array
  }
}

/*void Array::merge(int left_index, int middle, int right_index){
  //Determine size of each Array
  //int *result = elements; Why create a new result if the Array may be modified directly?
  int size1 = middle - left_index + 1;
  int size2 =  right_index - middle;
  //Create auxiliar Arrays
  int LP[size1];
  int RP[size2];
  //Copy from the orginal to the partitions
  for (size_t i = 0; i < size1; i++) {

    LP[i]=elements[left_index+i];
    std::cout << LP[i] << std::endl;
    std::cout << "/*Rellenando 1 " << std::endl;
    std::cout << "/*Valor size1: " << size1 << std::endl;
  }
  for (size_t i = 0; i < size2; i++) {
    RP[i]=elements[left_index+middle+i];
    std::cout << RP[i] << std::endl;
    std::cout << "/*Rellenando 2 " << std::endl;
    std::cout << "/*Valor size2: " << size2 << std::endl;
  }
  while (i < size1 && j < size2){
    if (LP[i] <= RP[j]){
      elements[k] = LP[i];
      i++;
    }
    else{
      elements[k] = RP[j];
      j++;
    }
    k++;
  }
  //Copy other sorted elements
  while (i < size1){
    elements[k] = LP[i];
    i++;
    k++;
  }
  //Copy the other sorted elements
  while (j < size2){
    elements[k] = RP[j];
    j++;
    k++;
  }*/
//}
