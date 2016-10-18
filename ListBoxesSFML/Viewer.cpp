/*
Arturo Burela
A01019906

Modified viewer class used to draw Boxes stored in a LinkedList while using the terminal
*/
#include "Viewer.h"
#include <iostream>
#include <string>

Viewer::Viewer(std::string window_title, void (*menu)(LinkedList<Box> *boxes)) : window(sf::VideoMode(800, 600), window_title), menu_thread(menu,boxes)
{
  // change the position of the window (relatively to the desktop)
  window.setPosition(sf::Vector2i(700, 100));

  // Prepare all the drawable elements
  configure();

  //greeting = "Nothing yet";
}

void Viewer::configure()
{
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

  // Draw all the elements
  drawBoxes();

  // Draw everything
  window.display();
}

void Viewer::drawBoxes()
{
  if (boxes->getLength()==2) {
    sf::RectangleShape rec(sf::Vector2f(100, 100));
    rec.setFillColor(sf::Color::Red);
    window.draw(rec);
  }
}
