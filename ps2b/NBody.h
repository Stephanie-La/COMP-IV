#ifndef NBODY_H
#define NBODY_H
#include <SFML/Graphics.hpp>
#include <string>
#include <vector>
#include <iostream>
#include <memory>


class CelestialBody :public sf::Drawable {
private:
    double windowSize;
    double xpos;
    double ypos;
    double xvel;
    double yvel;
    double mass;
    double radius;
    double display_x;
    double display_y;
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
    //ostream
    //friend std::ostream& operator <<(std::ostream& out, CelestialBody& co);
    //draw function
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states)const;
    //accessor functions
    double get_posx();
    double get_posy();
    double get_velx();//added this
    double get_vely();//added this
    double get_mass();//added this
    std::string get_filename();//added
    //mutators
    void set_x_y_pos(double x_input, double y_input);
    void set_velx(double vx);
    void set_vely(double vy);
    void set_radius(double radius);
    void set_window(double size);
    void set_position();

};

class Universe : public sf::Drawable {
public:
    Universe();
    Universe(double radius, int window, int num_of_planets, std::istream& in);//creates/ allocates space for a celestialbody, completely empty
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states)const;
    //ostream
    friend std::ostream& operator <<(std::ostream& out, const Universe& co);
    void step(double seconds);
    void printInfo();
    //accessor functions
    double get_r();//added
    int get_numPlanets();//added
   
private:
    double r;
    int windowSize;
    //std::vector<CelestialBody*> planets; //allocating space for them
    std::vector<std::unique_ptr<CelestialBody>>planets;
    int numberOfPlanets;

};
#endif //NBODY_H
