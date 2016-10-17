/*
Arturo Burela
A01019906

Program to draw different boxes using SFML and Linked lists.

*/
#include "LinkedList.h"
#include "Box.h"
#include "Viewer.h"
int main()
{
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
                //window.setSize(sf::Vector2u(640, 480));
        }

        window.clear();
        window.draw(shape);
        window.display();
    }
    LinkedList<int> ok;
    ok.insertTail(1);
    ok.insertHead(2);
    ok.printList();
    Box ok1(1,2,3,4);
    return 0;

}
