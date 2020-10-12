#include "NBody.h"
#include <cmath>


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
		//cant just convert a CelestialBody* into a smart pointer
		std::unique_ptr<CelestialBody>ptr(new CelestialBody());
		CelestialBody(); //assign a new CelestialBody to that pointer 
		planets.push_back(std::move(ptr));
		//planets.push_back(new CelestialBody()); //allocate space for a CelestialBody, and pushes allocated pointer into vector
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

//fix here
void Universe::step(double seconds)
{
	
	//for each planet, implement net forces
	for (int i = 0; i < numberOfPlanets; i++) {
		//all horizontal forces on a body
		double net_fx = 0;
		double net_fy = 0;
		//for each planet, calculate total forces
		//outside force
		for (int k = 0; k < numberOfPlanets; k++) {

			if (k != i) {
				double G = 6.67e-11; //gravitational constant
				//compiler reads top down
				double deltaX = planets[k]->get_posx() - planets[i]->get_posx();
				double deltaY = planets[k]->get_posy() - planets[i]->get_posy();
				//double Force = (6.67e-11 * planets[k]->get_mass() * planets[i]->get_mass()) / pow(r, 2);
				double r = sqrt(pow(deltaX, 2) + pow(deltaY, 2));
				double Force = (G * planets[k]->get_mass() * planets[i]->get_mass())/ pow(r, 2);
				double forceX = Force * (deltaX / r);
				double forceY = Force * (deltaY / r);
				//adding force to total net force acting on body
				net_fy += forceY;
				net_fx += forceX;
				
			}
		}
		double accX = net_fx / planets[i]->get_mass();
		double accY = net_fy / planets[i]->get_mass();
		double velX = planets[i]->get_velx() + seconds * accX;
		double velY = planets[i]->get_vely() + seconds * accY;
		planets[i]->set_velx(velX);
		planets[i]->set_vely(velY);
		double newX = (planets[i]->get_posx()) + velX * seconds;
		double newY = (planets[i]->get_posy()) + velY * seconds;
		planets[i]->set_x_y_pos(newX, newY);
	}
}

//prints info out to screen
void Universe::printInfo() {
	std::cout << numberOfPlanets << std::endl;
	std::cout << r << std::endl;
	for (int i = 0; i < numberOfPlanets; i++) {
		std::cout << planets[i]->get_posx() << " " << planets[i]->get_posy() << " " << planets[i]->get_velx() << " " << planets[i]->get_vely() << " " << planets[i]->get_mass() << " " << planets[i]->get_filename() << std::endl;
	}
}

double Universe::get_r() {
	return r;

}
int Universe::get_numPlanets() {
	return numberOfPlanets;
}

//find force
//step used on one body
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
	/*xpos = (windowSize / 2) * (xpos / radius) + (windowSize / 2);
	ypos = (windowSize / 2) * (ypos / radius) + (windowSize / 2);*/

	double rxpos = (windowSize / 2) * (xpos / radius) + (windowSize / 2);
	double rypos = (windowSize / 2) * (ypos / radius) + (windowSize / 2);


	texture.loadFromFile(filename);  //Load Texture from image


	sprite.setTexture(texture);
	sprite.setPosition(rxpos, rypos);
}

std::istream& operator >>(std::istream& in, CelestialBody& ci) {
	in >> ci.xpos >> ci.ypos >> ci.xvel
		>> ci.yvel >> ci.mass >> ci.filename;

	/*ci.xpos = (ci.windowSize / 2) * (ci.xpos / ci.radius) + (ci.windowSize / 2);
	ci.ypos = (ci.windowSize / 2) * (ci.ypos / ci.radius) + (ci.windowSize / 2);*/

	double rxpos = (ci.windowSize / 2) * (ci.xpos / ci.radius) + (ci.windowSize / 2);
	double rypos = (ci.windowSize / 2) * (ci.ypos / ci.radius) + (ci.windowSize / 2);

	ci.texture.loadFromFile(ci.filename);  //Load Texture from image


	ci.sprite.setTexture(ci.texture);
	ci.sprite.setPosition(rxpos, rypos);


	return in;
}

void CelestialBody::draw(sf::RenderTarget& target, sf::RenderStates states)const {
	target.draw(sprite, states);
}

//void CelestialBody::set_position() {
//
//	double result = (windowSize / 2) / radius;
//	double rxpos = xpos * result + (windowSize / 2);
//	double rypos = ypos * result + (windowSize / 2);
//	sprite.setPosition(sf::Vector2f(rxpos, rypos));
//}

CelestialBody::~CelestialBody() {

}

double CelestialBody::get_posx() {
	return xpos;
}

double CelestialBody::get_posy() {
	return ypos;
}

double CelestialBody::get_velx() {
	return xvel;
}

double CelestialBody::get_vely() {
	return yvel;
}

double CelestialBody::get_mass() {
	return mass;
}

std::string CelestialBody::get_filename() {
	return filename;
}

void CelestialBody::set_radius(double r) {
	radius = r;
}

void CelestialBody::set_window(double size) {
	windowSize = size;
}

void CelestialBody::set_velx(double vx) {
	xvel = vx;

}
void CelestialBody::set_vely(double vy) {
	yvel = vy;

}


void CelestialBody::set_x_y_pos(double x_input, double y_input) {
	xpos = x_input;
	ypos = y_input;
	double rxpos = (windowSize / 2) * (xpos / radius) + (windowSize / 2);
	double rypos = (windowSize / 2) * (-ypos / radius) + (windowSize / 2);
	sprite.setPosition(sf::Vector2f(rxpos, rypos));
}


