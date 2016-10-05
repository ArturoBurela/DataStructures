/*
	program to test the array
	Arturo Burela A01019906
*/

#include <iostream>
#include "Array.h"

#define SIZE 20

int main()
{
	Array test_array(SIZE);
	/*int number,location;
	//test_array.fillOrdered();
	//std::cout << "Ordered array data:" << std::endl;
	//
	test_array.fillRandom();
	//std::cout << "Random array data:" << std::endl;
	//
	//test_array.insertionSort();
	test_array.printRecursive(0);
	//test_array.fillRandom();
	test_array.mergeSort();
	test_array.printRecursive(0);
	//std::cout << "Enter a number to search" << std::endl;
	//std::cin >> number;
	//cout << test_array.linearSearch(number) << endl;
	//cout << test_array.binarySearchIterative(number) << endl;
	//location=test_array.binarySearchRecursive(number);
	//std::cout << "The number was at index " <<location << std::endl;
	*/
	test_array.fillRandom();
	std::cout << "Random array data:" << std::endl;
	test_array.printRecursive(0);
	test_array.mergeSort();
	std::cout << "Ordered array data:" << std::endl;
	test_array.printRecursive(0);
	return 0;
}
