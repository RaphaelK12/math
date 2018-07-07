#include <cstdlib>
#include <iostream>
#include <iomanip>

#include "math/geometry/plane/plane.hpp"

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
   ::math::geometry::direction::ABC2D<double>     abc;

  ::math::geometry::direction::parametric<double, 3 > parametric;

  ::math::geometry::plane::intersect( point3, no3d, parametric );
  ::math::geometry::plane::intersect( point3, l, no3d, parametric );
  
  ::math::geometry::plane::distance( point3, no3d );

  ::math::geometry::plane::construct( no3d, abc, abc, abc, abc );
  ::math::geometry::plane::construct( no3d, point2, point2, point2, point2 );
  ::math::geometry::plane::construct( b, no3d, point2, point2 );

  return EXIT_SUCCESS;
 }
