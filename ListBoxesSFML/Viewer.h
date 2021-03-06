/*
Arturo Burela
A01019906

Modified viewer class used to draw Boxes while using the terminal
*/

#ifndef VIEW_H
#define  VIEW_H
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "LinkedList.h"
#include "Box.h"

class Viewer {
public:
  // Drawable elements
  sf::RenderWindow window;
  //Used to track if the user closed the window
  sf::Event event;
  // Thread object, used to run the menu function while displaying the window
  sf::Thread menu_thread;
  // List to store the boxes
  LinkedList<Box> boxes;
  //A rectangle to draw the boxes
  sf::RectangleShape rec;
  //Flag to now if a new box must be added or an existing box must be removed
  Box aux;

public:
  //The constructor passing the window title, the function menu() and its parameters
  Viewer (std::string window_title, void (*menu)(Box * aux));
  // Draw methods
  void windowListener();
  //Main Windows Drawer
  void mainDraw();
  //Draw the boxes of the list
  void drawBoxes();
  //Check for new or removed boxes
  void addRemoveBox();
};
#endif
