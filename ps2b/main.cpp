#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <cstdlib>
#include <vector>
#include "NBody.h"


//compare with other bodies
//apply force x and y
//apply step function

using namespace std;
int main(int argc, char* argv[]){
    if (argc != 3) {
        cout << "Not enough arguments" << endl;
        return -1;
    }

    int num_bodies;
    double radius;
    std::string filename;
    double time_passed = 0;

    filename = argv[0];
    double T = strtod(argv[1], NULL); //max time
    double deltaT = strtod(argv[2], NULL);
   


    std::cin >> num_bodies;
    std::cin >> radius;


    Universe cb(radius, 500, num_bodies, std::cin);
    //event window

    sf::RenderWindow window(sf::VideoMode(600, 600), "Solar System");
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
        if (time_passed < T) {
                cb.step(deltaT);
                time_passed += deltaT;
        }
        window.draw(cb);
        window.display();
    }
    //close the solar system window to see the input information
    cb.printInfo();
    return 0;
}








