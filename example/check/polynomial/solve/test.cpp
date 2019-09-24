#include <iostream>
#include <iomanip>
#include <string>
#include <array>

#include "math/math.hpp"


using namespace std;

void quadric( std::array<double,3> const& coefficients )
{
  std::cout << "------------" << __FUNCTION__ << endl;
  std::array<double,2>   root;

  std::cout << "# Solutions: " << ::math::polynomial::solve::quadric::full<double>(  root, coefficients ) << std::endl;

  std::cout << "Check 1: P( " << root[0] << ") = " << ::math::polynomial::evaluate( root[0], coefficients ) << std::endl;
  std::cout << "Check 2: P( " << root[1] << ") = " << ::math::polynomial::evaluate( root[1], coefficients ) << std::endl;

  std::array<double,3> d;
  std::cout << "Shift: " <<::math::polynomial::solve::quadric::depressing( d, coefficients ) << std::endl;

  std::cout << "Depressed:" << d[0] << ", " << d[1] << ", " << d[2] << "; " <<  std::endl;
}

void cubic( std::array<double,4> const& coefficients )
{
  std::cout << "------------" << __FUNCTION__ << endl;
  std::array<double,3>   root;

  std::cout << "# Solutions: " << ::math::polynomial::solve::cubic::full<double>(  root, coefficients ) << std::endl;

  std::cout << "Check 1: P( " << root[0] << ") = " << ::math::polynomial::evaluate( root[0], coefficients ) << std::endl;
  std::cout << "Check 2: P( " << root[1] << ") = " << ::math::polynomial::evaluate( root[1], coefficients ) << std::endl;
  std::cout << "Check 3: P( " << root[2] << ") = " << ::math::polynomial::evaluate( root[2], coefficients ) << std::endl;

  std::array<double,4> d;
  std::cout << "Shift: " <<::math::polynomial::solve::cubic::depressing( d, coefficients ) << std::endl;

  std::cout << "Depressed:" << d[0] << ", " << d[1] << ", " << d[2] << ", " << d[3] << "; " <<  std::endl;
}

void quartic( std::array<double,5> const& coefficients )
{
  std::cout << "------------" << __FUNCTION__ << endl;
  std::array<double,4>   r4;

  std::cout << "# Solutions: " << ::math::polynomial::solve::quartic::full<double>( r4.data(), coefficients.data() ) << std::endl;

  std::cout << "Check 1: P( " << r4[0] << ") = " << ::math::polynomial::evaluate( r4[0], coefficients ) << std::endl;
  std::cout << "Check 2: P( " << r4[1] << ") = " << ::math::polynomial::evaluate( r4[1], coefficients ) << std::endl;
  std::cout << "Check 3: P( " << r4[2] << ") = " << ::math::polynomial::evaluate( r4[2], coefficients ) << std::endl;
  std::cout << "Check 4: P( " << r4[3] << ") = " << ::math::polynomial::evaluate( r4[3], coefficients ) << std::endl;

  std::cout << "# Solutions: " << ::math::polynomial::solve::quartic::shmakov<double>( r4.data(), coefficients.data() ) << std::endl;

  std::cout << "Check 1: P(" <<  r4[0] << ") = " << ::math::polynomial::evaluate( r4[0], coefficients ) << std::endl;
  std::cout << "Check 2: P(" <<  r4[1] << ") = " << ::math::polynomial::evaluate( r4[1], coefficients ) << std::endl;
  std::cout << "Check 3: P(" <<  r4[2] << ") = " << ::math::polynomial::evaluate( r4[2], coefficients ) << std::endl;
  std::cout << "Check 4: P(" <<  r4[3] << ") = " << ::math::polynomial::evaluate( r4[3], coefficients ) << std::endl;

  std::array<double,5> d;
  std::cout << "Shift: " <<::math::polynomial::solve::quartic::depressing( d, coefficients ) << std::endl;

  std::cout << "Depressed:" << d[0] << ", " << d[1] << ", " << d[2] << ", " << d[3] << ", "<< d[4] << "; " <<  std::endl;
}

int main( int argc, char *argv[] )
 {
  cout << "Hello World" << endl;

  quadric({0,0,1});
  quadric({1,-2,1});

  cubic({-350,162,-30,2});
  cubic({1,2,3,4});
  cubic({0,0,0,1});

  //quartic({ 1,0,-2,0,1});
  quartic({-1,-2,-3,4,5});
  quartic({ -0.15767074955840688, 6.2751997042642671e-05, -0.095080148369023565, 0,1 } );
  quartic({ -0.15767074955840688,                      0, -0.095080148369023565, 0,1 } );

  quartic({4*sqrt(30)-28, 2*sqrt(30)-16, 12 ,8, 1});
  quartic({ 1,0,2,0,1});

  quartic({ 2, -3, 3, -3, 1 });
  quartic({ 1,0,0,0,1});
  quartic({0,0,0,0,1});
  quartic({4,0,-5,0,1});
  quartic({24,-50,35,-10,1});


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

  // TODO math_polynomial_solve_quadric


  ::math::polynomial::solve::linear<float>( r1, c2 );
  ::math::polynomial::solve::linear<float>( r1.data(), c2.data() );

  ::math::polynomial::solve::quadric::full<float>( r2, c3 );
  ::math::polynomial::solve::cubic::full<float>( r3, c4 );
  ::math::polynomial::solve::cubic::depressing<float>( c4, c4 );

  ::math::polynomial::solve::quartic::bi<float>(        r4.data(), c5.data() );
  ::math::polynomial::solve::quartic::depressed<float>( r4.data(), c5.data() );
  ::math::polynomial::solve::quartic::full<float>(      r4.data(), c5.data() );

   ::math::polynomial::solve::quadric::depressed<float>( r2.data(), 1, 2  );
   ::math::polynomial::solve::quadric::trivial<float>( r2.data(), 1 );

    ::math::polynomial::solve::quadric::monic<float>( r2.data(), c2.data() );
    ::math::polynomial::solve::quadric::monic<float>( r2.data(), 123, 234  ) ;

  cin.get();
  return EXIT_SUCCESS;
 }

