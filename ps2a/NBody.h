#ifndef NBODY_H
#define NBODY_H
#include <SFML/Graphics.hpp>
#include <string>
#include <vector>
#include <iostream>


class CelestialBody :public sf::Drawable {
private:
    double windowSize;
    double xpos;
    double ypos;
    double xvel;
    double yvel;
    double mass;
    double radius;
    std::string filename;
    sf::Sprite sprite;
    sf::Texture texture;

public:
    //constructors
    CelestialBody();
    CelestialBody(double x_pos, double y_pos, double x_vel, double y_vel, double m, std::string name, double radius, double windowSize);
    ~CelestialBody();
    //istream
    friend std::istream& operator >>(std::istream& input, CelestialBody& ci);
    //draw function
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states)const;
    //accessor functions
    double get_posx();
    double get_posy();
    //mutators
    void set_radius(double radius);
    void set_window(double size);
    void set_position();
   // sf::Sprite& get_sprite() { return sprite; };
};

class Universe : public sf::Drawable {
public:
    Universe();
    Universe(double radius, int window, int num_of_planets,std::istream &in);//creates/ allocates space for a celestialbody, completely empty
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states)const;

private:
    double r;
    int windowSize;
    std::vector<CelestialBody*> planets; //allocating space for them
    int numberOfPlanets;

};
#endif //NBODY_H
