/*
Arturo Burela
A01019906

Modified viewer class used to draw Boxes stored in a LinkedList while using the terminal
*/
#include "Viewer.h"
#include <iostream>
#include <string>

Viewer::Viewer(std::string window_title, void (*menu)(Box * aux)) : window(sf::VideoMode(800, 800), window_title), menu_thread(menu,&aux)
{
  //initialize random seed:
  srand (time(NULL));
  // change the position of the window (relatively to the desktop)
  window.setPosition(sf::Vector2i(700, 100));
  //Load default values as 0
  aux.setX(0);
  aux.setY(0);
  aux.setWidth(0);
  aux.setHeight(0);
}

void Viewer::windowListener()
{
  //Launch the menu thread
  menu_thread.launch();
  while(window.isOpen())
  {
    while(window.pollEvent(event))
    {
      switch(event.type)
      {
        //If the close boton is clicked close the window and exit
        case sf::Event::Closed:
        window.close();
        std::cout << "Goodbye!..." << std::endl;
        exit(0);
        break;
      }
    }
    //Execute the drawing functions
    mainDraw();
  }
}

void Viewer::mainDraw()
{
  // Clean the window
  window.clear(sf::Color::White);
  //Check for new or removing boxes
  addRemoveBox();
  // Draw all the boxes
  drawBoxes();
  // Display everything
  window.display();
}

void Viewer::drawBoxes()
{
  if (boxes.getLength()>0) { //If the boxes list is not empty then draw all boxes in the list
    for (int i = 0; i < boxes.getLength(); i++) {
      rec.setSize(sf::Vector2f(boxes.getDataAtPosition(i).getWidth(), boxes.getDataAtPosition(i).getHeight()));
      rec.setFillColor(boxes.getDataAtPosition(i).getColor());
      rec.setPosition(sf::Vector2f(boxes.getDataAtPosition(i).getX(),boxes.getDataAtPosition(i).getY()));
      window.draw(rec);
    }
  }
}
void Viewer::addRemoveBox() {
  if (aux.getX()==1) { //If the box aux x is set to 1 add a new random box
    Box other;
    boxes.insertTail(other);
    aux.setX(0);
    std::cout << "Box dimensions (Xpos,Ypos,width,height): ("<< other.getX()<< "," << other.getY()<< "," << other.getWidth()<< "," << other.getHeight() << ")" << std::endl;
  }
  if (aux.getX()==-1 && boxes.getLength()>0) { //If the aux x is set to -1 and the list is not empty, remove the tail
    boxes.removeTail();
    aux.setX(0);
  }
  if (aux.getX()==-2) {//If aux x is -2 clear all the list
    boxes.clear();
    aux.setX(0);
  }
  if (aux.getX()>=0&&aux.getY()>=0&&aux.getWidth()>0&&aux.getHeight()>0) { //If all the aux atributes are set then draw the aux box (custom)
    boxes.insertTail(aux);
    std::cout << "Box dimensions (Xpos,Ypos,width,height): ("<< aux.getX()<< "," << aux.getY()<< "," << aux.getWidth()<< "," << aux.getHeight() << ")" << std::endl;
    aux.setX(0);//Set the values back to 0
    aux.setY(0);
    aux.setWidth(0);
    aux.setHeight(0);
    aux.setColor(aux.rand_color());// Add a new random color for the next custom box
  }
}
