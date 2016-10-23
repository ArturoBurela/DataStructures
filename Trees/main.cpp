#include <iostream>
#include "BinarySearchTree.h"

void treeMenu();

int main()
{
    std::cout << "BINARY SEARCH TREE TEST" << std::endl;
    treeMenu();

    return 0;
}

void treeMenu()
{
    BinarySearchTree<char> charTree;

    charTree.insert('9');
    charTree.insert('-');
    charTree.insert('5');
    charTree.insert('+');
    charTree.insert('2');
    charTree.insert('^');
    charTree.insert('4');
    charTree.insert('*');
    charTree.insert('2');
    charTree.insert('+');
    charTree.insert('9');

    charTree.printInOrder();
    std::cout << std::endl;
    charTree.printTree();
}
