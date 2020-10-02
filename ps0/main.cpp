//Stephanie La 
#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(1000, 1000), "SFML window!");
    window.setFramerateLimit(90); // call it once, after creating the window
    //load a sprite to display
    sf::Texture texture;
    if(!texture.loadFromFile("sprite.png")){
	return EXIT_FAILURE;
	}
    sf::Sprite sprite(texture);
	float position1 = 500;//left and right
	float position2 = 500;//up and down
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
		//define arrow keys
		//use the key pressed/key release
        }
	sprite.setPosition(position1, position2);
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
		position1--;
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
		position1++;
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
		position2--;
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
		position2++;
	}
	sprite.rotate(9.f);
	 window.clear();
	//draw sprite
        window.draw(sprite);
        window.display();
    }

    return 0;
}
