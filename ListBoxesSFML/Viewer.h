/*
Arturo Burela
A01019906

Modified viewer class used to draw while using the terminal
*/

#ifndef VIEW_H
#define  VIEW_H
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class Viewer {
    private:
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

    public:
        Viewer (std::string window_title, std::string font_name, void (*menu)(std::string *));
        //Viewer (std::string window_name, std::string font_name);

        // Draw methods
        void configure();
        void windowListener();
        void mainDraw();
        void drawTitle();
        void drawAnimatedCircle();

        //void menu();
};
#endif
