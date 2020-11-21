// Copyright 2020 Stephanie La


#ifndef EDITDISTANCE_H // NOLINT
#define EDITDISTANCE_H // NOLINT

#include <SFML/System.hpp>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm> // NOLINT

const int GAP = 2;

class EditDistance {
 public:
  EditDistance(std::string a, std::string b);
  static int penalty(char a, char b);
  static int min(int a, int b, int c);
  int OptDistance();
  std::string Alignment();
  ~EditDistance();

 private:
  // input strings
  std::string one;
  std::string two;

  // dynamic array to resize automatically
  // std::vector< std::vector< int > > data;
  std::vector< std::vector< int > > matrix;
};
#endif // NOLINT
