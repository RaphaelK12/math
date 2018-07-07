#include <iostream>
#include <iomanip>
#include <string>

#include "math/geometry/circle/circle.hpp"

using namespace std;

int main( int argc, char *argv[] )
 {
  cout << "Hello World" << endl;

  ::math::geometry::circle::simple2D<float>  a;
  ::math::geometry::circle::unit2D<float>    b;

   a = b;

  cin.get();
  return EXIT_SUCCESS;
 }
