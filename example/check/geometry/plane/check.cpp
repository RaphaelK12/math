#include <cstdlib>
#include <iostream>
#include <iomanip>

#include "math/geometry/plane/plane.hpp"
#include "math/geometry/direction/direction.hpp"

using namespace std;

int main( int argc, char *argv[] )
 {
  cout << "Hello World" << endl;

  ::math::geometry::plane::no3d<double>              a, no3d;
  ::math::geometry::plane::parametric3d<double>      b;
  ::math::geometry::plane::noNd<double, 5>           c;

  a=b;
  b=a;

  double l;
   ::math::linear::vector::point<double,3>             point3;
   ::math::linear::vector::point<double,2>             point2;
   ::math::geometry::direction::ABC2D<double>             abc;

  ::math::geometry::direction::parametric<double, 3 > parametric;

  ::math::geometry::plane::intersect( point3, no3d, parametric );
  ::math::geometry::plane::intersect( point3, l, no3d, parametric );
  
  ::math::geometry::plane::distance( point3, no3d );

  return EXIT_SUCCESS;
 }
