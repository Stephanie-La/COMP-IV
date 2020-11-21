// Copyright 2020 Stephanie La

// #include "/home/slaw/ps4/EditDistance.h" // NOLINT

// this should be the write header file below
#include "EditDistance.h"

#include <string>
#include <vector>
#include <algorithm> // NOLINT


// constructor
EditDistance::EditDistance(std::string a, std::string b) {
  // accepts the two strings to be compared
  one = a;
  two = b;

  // temp vector to use to store
  std::vector<int> temp;

  // lambda
  auto return_push = [&](int n) { temp.push_back(0); };

  // fill matrix with 0's
  for (unsigned j = 0; j < two.length() + 1; j++) {
  return_push(0);
  // temp.push_back(0);
  }
  // fill the other string with the temp
  for (unsigned i = 0; i < one.length() + 1; i++) {
  matrix.push_back(temp);
  }
}

// destructor
EditDistance::~EditDistance()
{}

int EditDistance::penalty(char a, char b) {
	/* returns the penalty for aligning chars a
		and b(this will be a 0 or a 1).*/
  if (a == b) {
  return 0;
  } else {
  return 1;
  }
}

int EditDistance::min(int a, int b, int c) {
	/* returns the minimum of the three
		arguments.*/
  if (a <= b && a <= c) {
  return a;
  } else if (b <= c) {
  return b;
  } else {
  return c;
  }
}

int EditDistance::OptDistance() {
	/* populates the matrix based on having the two strings, and
		returns the optimal distance(from the[0][0] cell of the matrix when done).*/

  // two indexes for two strings
  int i = 0;
  int j = 0;
  // initializing strings
  int string_one_length = one.length();
  int string_two_length = two.length();

  // fill bottom row and last column with gap penalty
  for (i = string_one_length; i >= 0; i--) {
  matrix[i][string_two_length] = GAP * (string_one_length - i);
  }
  for (j = string_two_length; j >= 0; j--) {
  matrix[string_one_length][j] = GAP * (string_two_length - j);
  }

  // fill inside matrix with ints in every row and column
  // passing the matrix the min value of the 3 values
  for (i = (string_one_length - 1); i >= 0; i--) {
  for (j = (string_two_length - 1); j >= 0; j--) {
  int first = GAP + matrix[i + 1][j];
  int second = GAP + matrix[i][j + 1];
  int third = matrix[i + 1][j + 1] + penalty(one[i], two[j]);
  matrix[i][j] = min(first, second, third);
  }
  }
  return matrix[0][0];
}

std::string EditDistance::Alignment() {
  // traces the matrix and returns a string that can be printed
  // to display the actual alignment. In general, this will be a multi
  // line string with embedded \n's

  // get alignment from top left to bottom right


  // inherited from ostream functionality, object oriented
  std::stringstream return_string;

  // my indexes for two strings
  int i = 0;
  int j = 0;

  // accessing strings
  // string one represents columns
  // string two represents rows
  int string_one = one.length();
  int string_two = two.length();

  // while matrix is not filled
  while (i < string_one || j < string_two) {
  int current_position = matrix[i][j];

  // if i < string_one {return GAP + matrix[i + 1][j } else {return -1}
  // same as second var
  int first = i < string_one ? GAP + matrix[i + 1][j] : -1;
  int second = j < string_two ? GAP + matrix[i][j + 1] : -1;
  int penalty_result = penalty(one[i], two[j]);

  // down
  if (current_position == first) {
  return_string << one[i] << " - " <<  "2\n";
  i++;
  } else if (current_position == second) {
  // right
  return_string << "- " << two[j] << " 2\n";
  j++;
  } else {
  // diagonal
  return_string << one[i] << " " << two[j] << " " << penalty_result << " \n";
  i++;
  j++;
  }
  }
  string result_string = return_string.str();
  return result_string;
}


