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
  sf::CircleShape circle;
  sf::Event event;
  // Thread object
  sf::Thread menu_thread;
  // Time variables
  sf::Clock clock;
  sf::Time elapsed_time;
  sf::Time total_time;
  // Additional variables
  std::string greeting;
  float scale_factor = 0.5;
  //char option = 'a';
  float x_pos = 100;
  float y_pos = 300;
  int direction = 1;
  float speed = 30;
  
  LinkedList<Box> *boxes;
  bool draw = false;

public:
  //The constructor passing the window title, the function menu() and its parameters
  Viewer (std::string window_title, void (*menu)(LinkedList<Box> *boxes));
  // Draw methods
  void configure();
  void windowListener();
  void mainDraw();
  void drawTitle();
  void drawAnimatedCircle();

  //void menu();
};
#endif
