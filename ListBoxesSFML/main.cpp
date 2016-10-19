/*
Arturo Burela
A01019906

Program to draw different boxes using SFML and Linked lists.

*/
#include "Viewer.h"

//Menu function, has a pointer to a LinkedList of Boxes passed as an argument
void menu(Box *aux)
{
  //Char and while only to display the option
  char option = 'a';
  int n;
  std::cout << "/* Welcome! Let's draw boxes! */" << std::endl;
  while (option != 'q')
  {
    std::cout << "\nChoose an option\n";
    std::cout << "\ta. Add a Box (random)\n";
    std::cout << "\tb. Add a Box (custom)\n";
    std::cout << "\tc. Remove last Box\n";
    std::cout << "\td. Clear all\n";
    std::cout << "\tq. Quit program\n";
    std::cin >> option;
    //Execute any valid selected option
    switch(option)
    {
      case 'a':
      //If a is selected we insertTail a new box because the tail is the last readed box so its drawed last and in fron of the others
      std::cout << "New box created: " << std::endl;
      //*op = 1;
      //USE A NON POINTER LINKED LIST OR IT WILL CRASH
      aux->setX(1);
      break;
      case 'b':
      //If b is selected then enter the data to the box
      std::cout << "New box created: " << std::endl;
      std::cout << "Please enter the data:" << std::endl;
      std::cout << "X position: " << std::endl;
      std::cin >> n;
      aux->setX(n);
      std::cout << "Y position: " << std::endl;
      std::cin >> n;
      aux->setY(n);
      std::cout << "width: " << std::endl;
      std::cin >> n;
      aux->setWidth(n);
      std::cout << "height: " << std::endl;
      std::cin >> n;
      aux->setHeight(n);
      break;
      case 'c':
      //If b is selected we set flag to remove tail
      std::cout << "Last box removed: " << std::endl;
      aux->setX(-1);
      break;
      case 'd':
      //If b is selected we set flag to clear list
      std::cout << "All clear!" << std::endl;
      aux->setX(-2);
      break;
      case 'q':
      //Exit the program
      std::cout << "Goodbye!..." << std::endl;
      exit(0);
      break;
      default:
      //For any other option
      std::cout << "Unknown option. Try again" << std::endl;
    }
  }
}
//Main function of the program
int main()
{
  //Create an instance of "Viewer" the Window title and the menu function are passed as parameters
  Viewer window("LinkedList of Boxes", &menu);
  //Start the Viewer Listener
  window.windowListener();
  //Return 0 to avoid compiler problems
  return 0;
}
