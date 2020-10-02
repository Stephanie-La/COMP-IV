#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <vector>
#include "NBody.h"


using namespace std;
int main()
{

    int num_bodies;
    double radius;
    std::cin >> num_bodies;
    std::cin >> radius;


    Universe cb(radius, 500, num_bodies, std::cin);
    //event window
    sf::RenderWindow window(sf::VideoMode(500, 500), "Solar System");
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();

            }
        }
        window.clear();
        window.draw(cb);
        window.display();
    }
return 0; 
}








