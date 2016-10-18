/*
Arturo Burela
A01019906

Modified viewer class used to draw Boxes stored in a LinkedList while using the terminal
*/
#include "Viewer.h"
#include <iostream>
#include <string>

Viewer::Viewer(std::string window_title, void (*menu)(int * numboxes)) : window(sf::VideoMode(800, 800), window_title), menu_thread(menu,&numboxes)
{
  //initialize random seed:
  srand (time(NULL));
  // change the position of the window (relatively to the desktop)
  window.setPosition(sf::Vector2i(700, 100));
  //Load 0 boxes as default
  numboxes=0;
}

void Viewer::windowListener()
{
  menu_thread.launch();

  while(window.isOpen())
  {
    while(window.pollEvent(event))
    {
      switch(event.type)
      {
        case sf::Event::Closed:
        window.close();
        std::cout << "Goodbye!..." << std::endl;
        exit(0);
        break;
      }
    }
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
  // Draw everything
  window.display();
}

void Viewer::drawBoxes()
{
  if (boxes.getLength()>0) {
    for (int i = 0; i < boxes.getLength(); i++) {
      sf::RectangleShape rec(sf::Vector2f(boxes.getDataAtPosition(i).getWidth(), boxes.getDataAtPosition(i).getHeight()));
      rec.setFillColor(boxes.getDataAtPosition(i).getColor());
      rec.setPosition(sf::Vector2f(boxes.getDataAtPosition(i).getX(),boxes.getDataAtPosition(i).getY()));
      window.draw(rec);
    }
  }
}
void Viewer::addRemoveBox() {
  if (numboxes==1) {
    Box other;
    boxes.insertTail(other);
    std::cout << "Box dimensions (Xpos,Ypos,width,height): ("<< other.getX()<< "," << other.getY()<< "," << other.getWidth()<< "," << other.getHeight() << ")" << std::endl;
    numboxes = 0;
  }
  if (numboxes==-1 && boxes.getLength()>0) {
    boxes.removeTail();
    numboxes = 0;
  }
}
