#include <iostream>
#include <iomanip>
#include <string>

#include "math/geometry/circle/circle.hpp"

using namespace std;

int main( int argc, char *argv[] )
 {
  cout << "Hello World" << endl;

  ::math::geometry::circle::simple<float,2>  a;
  ::math::geometry::circle::unit<float,2>    b;

   a = b;

  cin.get();
  return EXIT_SUCCESS;
 }