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
class Box {
    private:
      int x;
      int y;
      int width;
      int height;
      sf::Color color;
    public:
        // Constructors
        Box() {}
        Box(int x, int y, int w, int h) {
          this->x = x;
          this->y = y;
          width = w;
          height = h;
        }
        // Destructor
        ~Box() {}
        // Access methods
        int getX(){return x;}
        int getY(){return y;}
        int getWidth(){return width;}
        int getHeight(){return height;}
};
#endif
