#include "NBody.h"

Universe::Universe() {
	r = 0;
	windowSize = 0;
}

Universe::Universe(double radius, int window, int num_of_planets, std::istream& in) {
	//set radius, windows
	r = radius;
	windowSize = window;
	numberOfPlanets = num_of_planets;

	//initialize planets
	for (int i = 0; i < num_of_planets; i++) {
		planets.push_back(new CelestialBody()); //allocate space for a CelestialBody, and pushes allocated pointer into vector
		planets[i]->set_radius(r); //planets[i] is a pointer to the object
		planets[i]->set_window(window);
		in >> *planets[i];
	}

}

void Universe::draw(sf::RenderTarget& target, sf::RenderStates states)const {
	for (int i = 0; i < numberOfPlanets; i++) {
		target.draw(*planets.at(i), states); //draw each of the planets 
	}

}


CelestialBody::CelestialBody() {
	windowSize = 0;
	xpos = 0;
	ypos = 0;
	xvel = 0;
	yvel = 0;
	mass = 0;
	radius = 0;
	filename = "";

}

CelestialBody::CelestialBody(double x_pos, double y_pos, double x_vel, double y_vel, double m, std::string name, double rad, double window_size) {
	xpos = x_pos;
	ypos = y_pos;
	xvel = x_vel;
	yvel = y_vel;
	mass = m;
	radius = rad;
	windowSize = window_size;
	filename = name;

	

	//fit universe onto screen
	xpos = (windowSize / 2) * (xpos / radius) + (windowSize / 2);
	ypos = (windowSize / 2) * (ypos / radius) + (windowSize / 2);


	
	texture.loadFromFile(filename);  //Load Texture from image

	
	sprite.setTexture(texture);
	sprite.setPosition(xpos, ypos);
}

std::istream& operator >>(std::istream& in, CelestialBody& ci) {
	in >> ci.xpos >> ci.ypos >> ci.xvel
		>> ci.yvel >> ci.mass >> ci.filename;

	ci.xpos = (ci.windowSize / 2) * (ci.xpos / ci.radius) + (ci.windowSize / 2);
	ci.ypos = (ci.windowSize / 2) * (ci.ypos / ci.radius) + (ci.windowSize / 2);

	ci.texture.loadFromFile(ci.filename);  //Load Texture from image


	ci.sprite.setTexture(ci.texture);
	ci.sprite.setPosition(ci.xpos, ci.ypos);


	return in;
}

void CelestialBody::draw(sf::RenderTarget &target, sf::RenderStates states)const {
	target.draw(sprite, states);
}

void CelestialBody::set_position() {
	
	double result = (windowSize / 2) / radius;
	double rxpos = xpos * result + (windowSize / 2);
	double rypos = ypos * result + (windowSize / 2);
	sprite.setPosition(sf::Vector2f(rxpos, rypos));
}

CelestialBody::~CelestialBody() {

}

double CelestialBody::get_posx() {
	return xpos;
}

double CelestialBody::get_posy() {
	return ypos;
}

void CelestialBody::set_radius(double r) {
	radius = r;
}

void CelestialBody::set_window(double size) {
	windowSize = size;
}