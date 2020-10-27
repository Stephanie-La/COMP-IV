// Copyright 2020 Stephanie La
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Main

#include <stdint.h>
#include <boost/test/unit_test.hpp>
#include <iostream>
#include <string>
#include <exception>
#include <stdexcept>
#include "CircularBuffer.h"

// comment out one or another to test

BOOST_AUTO_TEST_CASE(build_constructor) {
    // comment out one or another to test
  BOOST_REQUIRE_NO_THROW(CircularBuffer(20));

  BOOST_REQUIRE_THROW(CircularBuffer(0), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(test_enqueue_and_dequeue) {
    // make object
    CircularBuffer cb(3);

    // lambda
    auto check_dq = [&](int16_t x) { return cb.dequeue() == x; };

    // enqueue
    cb.enqueue(2);
    cb.enqueue(3);
    cb.enqueue(4);
    BOOST_REQUIRE(cb.peek() == 2);
    BOOST_REQUIRE_THROW(cb.enqueue(5), std::runtime_error);
    // dequeue

    BOOST_REQUIRE(check_dq(2));
    BOOST_REQUIRE(check_dq(3));
    BOOST_REQUIRE(check_dq(4));


   /* BOOST_REQUIRE(cb.dequeue() == 2);
    BOOST_REQUIRE(cb.dequeue() == 3);
    BOOST_REQUIRE(cb.dequeue() == 4);*/

    BOOST_REQUIRE_THROW(cb.dequeue(), std::runtime_error);
}

BOOST_AUTO_TEST_CASE(test_peek) {
    CircularBuffer cb(3);

    cb.enqueue(10);
    cb.enqueue(50);
    cb.enqueue(100);
    BOOST_REQUIRE(cb.peek() == 10);
    BOOST_REQUIRE(cb.dequeue() == 10);
    BOOST_REQUIRE(cb.peek() == 50);
}
