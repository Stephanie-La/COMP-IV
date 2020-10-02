#ifndef FibLFSR_h
#define FibLFSR_h
#include <iostream>
#include <string>
#include <vector>

class FibLFSR {
public:
	FibLFSR(std::string seed);	// constructor to create LFSR with
									// the given initial seed and tap

	int step();				// simulate one step and return the
							// new bit as 0 or 1

	int generate(int k);	// simulate k steps and return
							// k-bit integer
	~FibLFSR();
	friend std::ostream& operator<<(std::ostream& out, const FibLFSR& fibLFSR);

private:
	std::string s;
	std::vector<int>data;
	int tap10;
	int tap12;
	int tap13;
	int tap15; //end of the 16 bits 

};
#endif  //FibLFSR_h

