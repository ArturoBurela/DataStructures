/*
Arturo Burela
A01019906

Program to draw different boxes using SFML and Linked lists.

*/
#include "Viewer.h"

//Menu function, has a pointer to a LinkedList of Boxes passed as an argument
void menu(LinkedList<Box> *boxes)
{
  //Char and while only to display the option
  char option = 'a';
  while (option != 'q')
  {
    std::cout << "\nChoose an option\n";
    std::cout << "\ta. Add a Box (random)\n";
    std::cout << "\tb. Remove last Box\n";
    std::cout << "\tq. Quit program\n";
    std::cin >> option;
    //Execute any valid selected option
    switch(option)
    {
      case 'a':
      //If a is selected we insertTail a new box because the tail is the last readed box so its drawed last and in fron of the others
      std::cout << "New box created: " << std::endl;
      boxes->insertTail(Box(1,2,3,4));
      break;
      case 'b':
      //If b is selected we simply remove the tail of the list
      std::cout << "Last box removed: " << std::endl;
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
  Viewer test("LinkedList of Boxes", &menu);
  //Start the Viewer Listener
  test.windowListener();
  //Return 0 to avoid compiler problems
  return 0;
}
