/*
Arturo Burela
A01019906

Box class

You should create a Box class, that holds the details for a single rectangle, storing the coordinates of its top left corner, its width and height. Additionally you could add more details, like the color to be painted, the border width, etc. Then you can create a list of such boxes.

*/
#ifndef BOX
#define BOX
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
class Box {
private:
  int x;
  int y;
  unsigned int width;
  unsigned int height;
  sf::Color color;
public:
  // Constructors
  Box() { //Empty constructor set random values
    srand(time(NULL));
    width = rand() % 500 + 50;
    height = rand() % 500 + 50;
    x = rand() % 600;
    y = rand() % 600;
    color = rand_color();
  }
  Box(int x, int y, int w, int h) { //Custom constructor only set random color
    srand(time(NULL));
    this->x = x;
    this->y = y;
    width = w;
    height = h;
    color = rand_color();
  }
  // Destructor
  ~Box() {}
  // Access methods
  int getX(){return x;}
  int getY(){return y;}
  int getWidth(){return width;}
  int getHeight(){return height;}
  void setX(int n){x = n;}
  void setY(int n){y = n;}
  void setWidth(int n){width = n;}
  void setHeight(int n){height = n;}
  sf::Color getColor(){return color;}
  void setColor(sf::Color c){color = c;}
  //Aux color random
  sf::Color rand_color(){return sf::Color(std::rand() % 255, std::rand() % 255, std::rand() % 255);}
};
#endif
