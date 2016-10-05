/*
	Simple program to test the Array class

	Gilberto Echeverria
	Data Structures
	09/08/2016
	gilecheverria@yahoo.com
*/

#include <iostream>
#include "Array.h"

#define SIZE 50

void printSearchResults(int index)
{
	if (index > -1)
		std::cout << "The element was found at position: " << index << std::endl;
	else
		std::cout << "The element was NOT found" << std::endl;
}

int main()
{
	int search;
	int location;

	Array<int> test_array(SIZE);

	std::cout << "\n#### SEARCHING ####" << std::endl;
	//// ORDERED DATA ////

	test_array.fillOrdered();
	std::cout << "\nOrdered array data:" << std::endl;
	test_array.printRecursive(0);

	std::cout << "Enter a number to search: ";
	std::cin >> search;

	std::cout << "Binary Iterative Search:" << std::endl;
	location = test_array.binarySearchIterative(search);
	printSearchResults(location);

	std::cout << "Binary Recursive Search:" << std::endl;
	location = test_array.binarySearchRecursive(search);
	printSearchResults(location);

	//// RANDOM DATA ////

	test_array.fillRandom();
	std::cout << "\nRandom array data:" << std::endl;
	test_array.printRecursive(0);

	std::cout << "Enter a number to search: ";
	std::cin >> search;

	std::cout << "Linear Search:" << std::endl;
	location = test_array.linearSearch(search);
	printSearchResults(location);

	return 0;
}
