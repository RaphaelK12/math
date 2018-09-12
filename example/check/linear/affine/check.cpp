#include <cstdlib>
#include <iostream>
#include <iomanip>

#include "math/linear/affine/affine.hpp"

using namespace std;

int main( int argc, char *argv[] )
 {
  cout << "Hello World" << endl;

  ::math::linear::affine::structure<double,3> a1,a2,a3;
  ::math::linear::vector::structure<double,3> v1,v2,v3;
  ::math::linear::matrix::structure<double,3,3> m1,m2,m3;

  ::math::linear::affine::addition(a1,a2);
  ::math::linear::affine::addition(a1,a2,a3);

  //::math::linear::affine::compose(a1,a2);
  ::math::linear::affine::compose(a1,a2,a3);

  ::math::linear::affine::invert(a1);
  ::math::linear::affine::invert(a1,a2);


  ::math::linear::affine::NaN(a1);
  ::math::linear::affine::zero(a1);
  ::math::linear::affine::one(a1);

  ::math::linear::affine::NaN<double,5>();
  ::math::linear::affine::zero<double,5>();
  ::math::linear::affine::one<double,5>();

  ::math::linear::affine::scale<double>(a1,5,a2);
  ::math::linear::affine::scale<double>(a1,5);

  ::math::linear::affine::load(a1,m1,v1);
  ::math::linear::affine::look_at(a1,v1,v2,v3);

  ::math::linear::affine::transform(v1,a1,v2);
  ::math::linear::affine::transform(v1,a1);

  return EXIT_SUCCESS;
 }
