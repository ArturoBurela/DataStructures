/*
	Arturo Burela
  A01019906
*/
#include <iostream>

using namespace std;

class Queue {
private:
	int *array;//Where the numbers are stored
	int size;//Stores the Queue size
	int index;//Indicates the actual index

public:
	Queue(int n);
	~Queue();
	void push(int n);
	int pop();
	int top();
	bool Empty();
	bool Full();
	void print();
};

Queue::Queue(int n){
	index=0;
	size=n;
	array = new int [size];
}

Queue::~Queue () {
  delete [] array;
}

void Queue::push(int n)
{
	if(!Full()){
		array[index]=n;//Add to the end of the queue
		index++;//Add index
	}else{
		std::cout << "The Queue is full" << std::endl;
	}
}

int Queue::pop()
{
	if(!Empty()){
		int i; //Aux to move the values
		int x = array[0];//Gets the first element in the queue
		//Move the values
		for (i = 0; i < size; i++) {
			if(i<index-1){
				array[i]=array[i+1];
			}else{
				array[i]=0;
			}
		}
		index--;//Decrease index
		return x;//Return the first element in the queue -> FIFO
	}else{
		std::cout << "The Queue is empty" << std::endl;
		return -1;
	}
}

int Queue::top()
{
	if(!Empty()){
		return array[0];//Return the first element in the queue -> FIFO
	}else{
		std::cout << "The Queue is empty" << std::endl;
		return -1;
	}
}

bool Queue::Empty()
{
	if (index == 0)
		return true;
	return false;
}
bool Queue::Full()
{
	if (index == size)
		return true;
	return false;
}

void Queue::print()
{
	cout << array[0] << "<- Front" << endl;
	for (int i = 1; i<size ; i++)	{
		cout << array[i] << endl;
	}
}
