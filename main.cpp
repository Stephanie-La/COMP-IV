// Copyright 2020 Stephanie La

#include <SFML/System.hpp>

#include "EditDistance.h"
#include <iostream>
#include <string>


int main() {
    sf::Clock clock;
    sf::Time t;

    // passing in two strings
    std::string one;
    std::string two;

    std::cin >> one;
    std::cin >> two;

    // make an object
    EditDistance ED(one, two);

    // initialize two functions
    int opt = ED.OptDistance();

    std::string align = ED.Alignment();


    std::cout << "Edit distance = " << opt << std::endl;
    std::cout << align << std::endl;

    t = clock.getElapsedTime();
    std::cout << "Execution time is " << t.asSeconds() << " seconds \n";


    return 0;
}
// At the end of main, after computing the solution, capture the running time:
// t = clock.getElapsedTime();
// Then after printing out the solution, display the running time:
// cout << "Execution time is " << t.asSeconds() << " seconds \n";

