#include <iostream>
#include <string>
#include "LFSR.h"
#include <SFML/Graphics.hpp>

using namespace std;
void transform(sf::Image& image, FibLFSR* bit) {
	
	/*if (!image.loadFromFile("picture.png"))
		exit(1);*/

	sf::Vector2u size = image.getSize();
	sf::RenderWindow window1(sf::VideoMode(size.x, size.y), "Mario Mushroom Input");

	sf::Texture texture_input;
	texture_input.loadFromImage(image);

	sf::Sprite sprite_input;
	sprite_input.setTexture(texture_input);

	// p is a pixel
	sf::Color p;
	int x_size = image.getSize().x;
	int y_size = image.getSize().y;
	//manipulate image 
	// create photographic negative image
	for (int x = 0; x < x_size; x++) {
		for (int y = 0; y < y_size; y++) {
			p = image.getPixel(x, y);
			p.r = p.r ^ bit->generate(8);
			p.g = p.g ^ bit->generate(8);
			p.b = p.b ^ bit->generate(8);
			image.setPixel(x, y, p);
		}
	}

	sf::RenderWindow window2(sf::VideoMode(size.x, size.y), "Mario Mushroom output");

	sf::Texture texture_output;
	texture_output.loadFromImage(image);
	
	sf::Sprite sprite_output;
	sprite_output.setTexture(texture_output);

	while (window1.isOpen() && window2.isOpen()) {
		sf::Event event;
		while (window1.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window1.close();
		}
		while (window2.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window2.close();
		}
		window1.clear();
		window1.draw(sprite_input);
		window1.display();
		window2.clear();
		window2.draw(sprite_output);
		window2.display();
	}
}




int main(int argc, char** argv) {
	argv[0] = "./Photomagic";//executable
	FibLFSR bit(argv[3]);// seed 1011011000110110
	sf::Image image;
	//image.loadFromFile(argv[1]);
	if (!image.loadFromFile (argv[1])) //picture.png
			exit(1);
	transform(image, &bit);
	//image.saveToFile(argv[2]);
	if (!image.saveToFile(argv[2])) //picture-out.png 
			exit(1);

	return 0;
}









