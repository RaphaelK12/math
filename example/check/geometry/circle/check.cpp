#include <iostream>
#include <iomanip>
#include <string>

#include "math/math.hpp"

using namespace std;

int main( int argc, char *argv[] )
 {
  cout << "Hello World" << endl;

  ::math::geometry::circle::simple<float,6>  simple;
  ::math::geometry::circle::unit<float,6>    unit;

  ::math::linear::vector::point<float,6>    point;

  simple = unit;

  ::math::geometry::circle::distance<float>( unit, point );
  ::math::geometry::circle::distance<float>( simple, point );

   float  lambda0;
   float  lambda1;
   ::math::geometry::direction::parametric<float,6> direction;

  ::math::geometry::circle::intersect( lambda0, lambda1, direction );
  ::math::geometry::circle::intersect( lambda0, lambda1, simple, direction );

  cin.get();
  return EXIT_SUCCESS;
 }
