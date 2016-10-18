/*
Arturo Burela
A01019906

Program to draw different boxes using SFML and Linked lists.

*/
#include "Viewer.h"


void menu()
{
    char option = 'a';
    while (option != 'q')
    {
        std::cout << "\nChoose an option\n";
        std::cout << "\ta. Add a Box (random)\n";
        std::cout << "\tb. Remove last Box\n";
        std::cout << "\tq. Quit program\n";
        std::cin >> option;

        switch(option)
        {
            case 'a':

                std::cout << "A selected: " << std::endl;
                break;
            case 'b':

                std::cout << "B selected: " << std::endl;
                break;
            case 'q':
                std::cout << "Goodbye!" << std::endl;
                exit(0);
                break;
            default:
                std::cout << "Unknown option. Try again" << std::endl;
        }
    }
}

int main()
{
    LinkedList<Box> ok;
    //ok.insertTail(1);
    //ok.insertHead(2);
    //ok.printList();
    Box ok1(1,2,3,4);
    Box ok3(1,2,3,4);
    Box ok2(1,2,3,4);
    ok.insertHead(ok1);
    ok.insertHead(ok3);
    ok.insertHead(ok2);
    ok.insertHead(ok1);
    //menu();
    Viewer test("Viewer test", &menu);
    test.windowListener();
    return 0;

}
