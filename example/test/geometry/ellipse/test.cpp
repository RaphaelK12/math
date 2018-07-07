#include <iostream>
#include <iomanip>
#include <string>

#include "math/geometry/ellipse/ellipse.hpp"

using namespace std;

int main( int argc, char *argv[] )
 {
  cout << "Hello World" << endl;

   ::math::geometry::ellipse::base2D<double>   b;
   ::math::geometry::ellipse::simple2D<double>  s;
   ::math::geometry::ellipse::general2D<double>  g;

    g = g;  g= s;   g = b;
            s = s;  s = b;
  cin.get();
  return EXIT_SUCCESS;
 }
