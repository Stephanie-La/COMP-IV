// Dr. Rykalova
// test.cpp for PS1a
// updated 1/31/2020

#include <iostream>
#include <string>

#include "FibLFSR.h"

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Main
#include <boost/test/unit_test.hpp>


BOOST_AUTO_TEST_CASE(sixteenBitsThreeTaps) {

  FibLFSR l("1011011000110110");
  BOOST_REQUIRE(l.step() == 0);
  BOOST_REQUIRE(l.step() == 0);
  BOOST_REQUIRE(l.step() == 0);
  BOOST_REQUIRE(l.step() == 1);
  BOOST_REQUIRE(l.step() == 1);
  BOOST_REQUIRE(l.step() == 0);
  BOOST_REQUIRE(l.step() == 0);
  BOOST_REQUIRE(l.step() == 1);

  FibLFSR l2("1011011000110110");
  BOOST_REQUIRE(l2.generate(9) == 51);
}
//test if all the bits will result in zeros using step functions worked
BOOST_AUTO_TEST_CASE(allBitsOne) {

    FibLFSR FibLFSR_One("1111111111111111");
    BOOST_REQUIRE(FibLFSR_One.step() == 0);
    BOOST_REQUIRE(FibLFSR_One.step() == 0);
    BOOST_REQUIRE(FibLFSR_One.step() == 0);
    BOOST_REQUIRE(FibLFSR_One.step() == 0);
    BOOST_REQUIRE(FibLFSR_One.step() == 0);
    BOOST_REQUIRE(FibLFSR_One.step() == 0);
    BOOST_REQUIRE(FibLFSR_One.step() == 0);
    BOOST_REQUIRE(FibLFSR_One.step() == 0);

}

//this test was to check if the xor functions implemented in step worked
BOOST_AUTO_TEST_CASE(sixteenBits)
{
    FibLFSR line("1101001101010001");
    BOOST_REQUIRE(line.step() == 0);
    BOOST_REQUIRE(line.step() == 1);
    BOOST_REQUIRE(line.step() == 1);
    BOOST_REQUIRE(line.step() == 0);
    BOOST_REQUIRE(line.step() == 1);
}
    

