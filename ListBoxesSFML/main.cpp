/*
Arturo Burela
A01019906

Program to draw different boxes using SFML and Linked lists.

*/
#include "LinkedList.h"
#include "Box.h"
#include "Viewer.h"


void menu()
{
    char option = 'a';
    while (option != 'q')
    {
        std::cout << "\nUSER MENU\n";
        std::cout << "\ta. Say Hello\n";
        std::cout << "\tb. Say Goodbye\n";
        std::cout << "\tq. Quit program\n";
        std::cout << "Choose an option: ";
        std::cin >> option;

        switch(option)
        {
            case 'a':

                std::cout << "A selected: " << std::endl;
                break;
            case 'b':

                std::cout << "B selected: " << std::endl;
                break;
            case 'q':
                std::cout << "Finishing program" << std::endl;
                exit(0);
                break;
            default:
                std::cout << "Unknown option. Try again" << std::endl;
        }
    }
}

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
