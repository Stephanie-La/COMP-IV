//Stephanie La
#include <iostream>
#include "FibLFSR.h"
using namespace std;


FibLFSR::FibLFSR(string seed) {
	while (seed.length() != 16) {
		cout << "The sequence entered is less or greater than 16. Enter another sequence:";
		cin >> seed;
	}
	s = seed; //initializing seed string
}

int FibLFSR::step() {
	int result = 0;
	//srings are read in left to right, so 10,12,13 becomes 2,3,5 left to right
	tap13 = s.at(2) - '0'; //subtract the ascii value from 2
	tap12 = s.at(3) - '0';
	tap10 = s.at(5) - '0';
	tap15 = s.at(0) - '0';

	//if they both equal 1 or 0, output is 0
	//ex. 0 xor 0 = 0 and 1 xor 1 = 0
	if ((tap15 == 1 && tap13 == 1) || (tap15 == 0 && tap13 == 0)) {
		result = 0;
	}
	else {
		result = 1;
	}
	if (result == tap12) {
		result = 0;
	}
	else {
		result = 1;
	}
	if (result == tap10) {
		result = 0;
	}
	else {
		result = 1;
	}
	s.erase(s.begin());//erase the bit spot at the beginning 
	s.push_back(result + '0');//push back output towards the back
	return result;
}

int FibLFSR::generate(int k) {
	int x = 0;
	for (int i = 0; i < k; i++) {
		x = x * 2;
		x += step();
	}
	return x;
}

FibLFSR::~FibLFSR() {
	data.clear();
}

ostream& operator<<(std::ostream& out, const FibLFSR& fibLFSR) {
	return out << fibLFSR.s;
}
