#include <iostream>
#include "Node.h"
#include "LinkedList.h"
int main()
{
    LinkedList<float> testList;

    ///Insert Data
    testList.insertTail(234.23);
    testList.insertHead(34.123);
    testList.insertHead(78.343);
    testList.insertHead(12.428);

    testList.printList();

    testList.clear();

    testList.insertTail(2343.2);
    testList.insertHead(345.3);
    testList.insertHead(41234.44);
    testList.insertHead(34.45);
    testList.printList();

    Node<float> * loner;
    loner = testList.removeTail();
    std::cout << *loner << std::endl;

    testList.printList();
    //Insert a pointer to a node
    /*Node<float> * loner= new Node<float>(3.1415);
    std::cout << "This is the data in the node: " << loner << std::endl;
    loner->setData(loner);
    std::cout << "This is the data in the node: " << loner << std::endl;
    */return 0;
}
