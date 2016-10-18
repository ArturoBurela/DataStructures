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
  sf::Font font;
  sf::Text title;
  sf::Text info;
  sf::Text message;
  //Used to track if the user closed the window
  sf::Event event;
  // Thread object, used to run the menu function while displaying the window
  sf::Thread menu_thread;
  // Additional variables
  LinkedList<Box> *boxes;
  int *geometry;

public:
  //The constructor passing the window title, the function menu() and its parameters
  Viewer (std::string window_title, void (*menu)(LinkedList<Box> *boxes));
  // Draw methods
  void configure();
  void windowListener();
  void mainDraw();
  void drawBoxes();
};
#endif
