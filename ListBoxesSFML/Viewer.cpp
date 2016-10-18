/*
Arturo Burela
A01019906

Modified viewer class used to draw Boxes stored in a LinkedList while using the terminal
*/
#include "Viewer.h"
#include <iostream>
#include <string>

Viewer::Viewer(std::string window_title, void (*menu)()) : window(sf::VideoMode(800, 600), window_title), menu_thread(menu)
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
                    std::cout << "Goodbye..." << std::endl;
                    exit(0);
                    break;
            }
        }
        mainDraw();
    }
}

void Viewer::mainDraw()
{
    // Keep track of the time elapsed since the last frame
    elapsed_time = clock.restart();
    total_time += elapsed_time;

    // Clean the window
    window.clear(sf::Color::White);

    // Draw all the elements
    drawTitle();
    drawAnimatedCircle();

    // Draw everything
    window.display();
}

void Viewer::drawAnimatedCircle()
{
    /*// Create a moving animation
    circle.setPosition(sf::Vector2f(x_pos, y_pos));
    x_pos += speed * direction * elapsed_time.asSeconds();
    if (x_pos <= circle.getRadius() || x_pos >= window.getSize().x-circle.getRadius())
    {
        direction = direction * -1;
    }

    //window.draw(circle);
    */
    sf::RectangleShape rec(sf::Vector2f(100, 100));
    rec.setFillColor(sf::Color::Red);
    window.draw(rec);
}
