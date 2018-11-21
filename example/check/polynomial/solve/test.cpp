#include <iostream>
#include <iomanip>
#include <string>

#include "math/math.hpp"


using namespace std;

int main( int argc, char *argv[] )
 {
  cout << "Hello World" << endl;

//std::array<float,10>   r;
  std::array<float,1>   r1;
  std::array<float,2>   r2;
  std::array<float,3>   r3;
  std::array<float,4>   r4;

//std::array<float,10>   c;
  std::array<float,2>   c2{1,2};
  std::array<float,3>   c3{1,2,3};
  std::array<float,4>   c4{1,2,3,4};
  std::array<float,5>   c5{1,2,3,4,5};



  ::math::polynomial::solve::linear<float>( r1, c2 );
  ::math::polynomial::solve::linear<float>( r1.data(), c2.data() );

  ::math::polynomial::solve::quadric::full<float>( r2, c3 );
  ::math::polynomial::solve::cubic::full<float>( r3, c4 );

  ::math::polynomial::solve::quartic::bi<float>(        r4.data(), c5.data() );
  ::math::polynomial::solve::quartic::depressed<float>( r4.data(), c5.data() );
  ::math::polynomial::solve::quartic::full<float>(      r4.data(), c5.data() );


  cin.get();
  return EXIT_SUCCESS;
 }

