#ifndef FibLFSR_h
#define FibLFSR_h
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class FibLFSR {
public:
	FibLFSR(std::string seed);
	int step();
	int generate(int k);
	~FibLFSR();
	friend std::ostream& operator<<(std::ostream& out, const FibLFSR& fibLFSR);

private:
	int length;
	std::string s;
	std::vector<int>data;
	bool isBinary(std::string seed); //to check if string is a binary password
	int tap10;
	int tap12;
	int tap13;
	int tap15; //end of the 16 bits 

};
#endif  //FibLFSR_h

inline void transform(sf::Image& image, FibLFSR* bit);
