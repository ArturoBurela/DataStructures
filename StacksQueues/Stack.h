/*
	Arturo Burela
  A01019906
*/
#include <iostream>

using namespace std;

class Stack {
private:
	int *array;//Where the numbers are stored
	int size;//Stores the Stack size
	int index;//Indicates the actual index

public:
	Stack(int n);
	~Stack();
	void push(int n);
	int pop();
	int top();
	bool Empty();
	bool Full();
	void print();
};

Stack::Stack(int n){
	index=0;
	size=n;
	array = new int [size];
}

Stack::~Stack () {
  delete [] array;
}

void Stack::push(int n)
{
	if(!Full()){
		array[index]=n;//Add to the top of the stack
		index++;
	}else{
		std::cout << "The Stack is full" << std::endl;
	}
}

int Stack::pop()
{
	if(!Empty()){
		int x = array[index-1];//Get the first element in the queue -> FIFO
		array[index-1]=0;//Erase
		index--;//Reduce index
		return x;//Return the last element in the stack -> LIFO
	}else{
		std::cout << "The Stack is empty" << std::endl;
		return -1;
	}
}

int Stack::top()
{
	if(!Empty()){
		return array[index-1];
	}else{
		std::cout << "The Stack is empty" << std::endl;
		return -1;
	}
}

bool Stack::Empty()//Checks if the array is empty
{
	if (index == 0)
		return true;
	return false;
}
bool Stack::Full()//Checks if the array is full
{
	if (index == size)
		return true;
	return false;
}

void Stack::print()//Print the stack
{
	cout << array[0] << "<- Bottom" << endl;
	for (int i = 1; i<size ; i++)	{
		cout << array[i] << endl;
	}
}
