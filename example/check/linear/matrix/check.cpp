#include <iostream>
#include <iomanip>
#include <chrono>

#include "math/linear/matrix/matrix.hpp"


template< typename scalar_name, unsigned width_number, unsigned height_number >
 void print ( ::math::linear::matrix::structure<scalar_name,width_number,height_number> const& m )
  {
   for( unsigned j=0; j< width_number; j++ )
    {
     std::cout << std::endl;
     for( unsigned i=0; i< height_number; i++ )
      {
       std::cout << std::setw(10) << std::fixed << m[j][i] << ", ";
      }
    }
  }



int main( int argc, char*argv[] )
 {
  std::cin.get();

  ::math::linear::matrix::structure<double,10,11> mAB;
  ::math::linear::matrix::structure<double,11,12> mBC;
  ::math::linear::matrix::structure<double,2,2>   m22;
  ::math::linear::matrix::structure<double,3,3>   m33;
  ::math::linear::matrix::structure<double,4,4>   m44;

  ::math::linear::vector::structure<double,2>   v2;
  ::math::linear::vector::structure<double,3>   v3;
  ::math::linear::vector::structure<double,4>   v4;

  ::math::linear::matrix::zero( mAB );

  ::math::linear::matrix::addition( mAB, mAB, mAB );  ::math::linear::matrix::addition( mAB, mAB );
  ::math::linear::matrix::addition( m22, m22, m22 );  ::math::linear::matrix::addition( m22, m22 );
  ::math::linear::matrix::addition( m33, m33, m33 );  ::math::linear::matrix::addition( m33, m33 );
  ::math::linear::matrix::addition( m44, m44, m44 );  ::math::linear::matrix::addition( m44, m44 );

  ::math::linear::matrix::subtraction( mAB, mAB, mAB );  ::math::linear::matrix::subtraction( mAB, mAB );
  ::math::linear::matrix::subtraction( m22, m22, m22 );  ::math::linear::matrix::subtraction( m22, m22 );
  ::math::linear::matrix::subtraction( m33, m33, m33 );  ::math::linear::matrix::subtraction( m33, m33 );
  ::math::linear::matrix::subtraction( m44, m44, m44 );  ::math::linear::matrix::subtraction( m44, m44 );

  //::math::linear::matrix::multiply( mAB, mAB, mAB );  ::math::linear::matrix::multiply( mAB, mAB );
  ::math::linear::matrix::multiply( m22, m22, m22 );
  ::math::linear::matrix::multiply( m33, m33, m33 );
  ::math::linear::matrix::multiply( m44, m44, m44 );

  ::math::linear::matrix::one( mAB );
  ::math::linear::matrix::one( m22 );
  ::math::linear::matrix::one( m33 );
  ::math::linear::matrix::one( m44 );

  ::math::linear::matrix::zero( mAB );
  ::math::linear::matrix::zero( m22 );
  ::math::linear::matrix::zero( m33 );
  ::math::linear::matrix::zero( m44 );

  //::math::linear::matrix::invert( mAB );
  ::math::linear::matrix::invert( m22, m22 );
  ::math::linear::matrix::invert( m33, m33 );
  ::math::linear::matrix::invert( m44, m44 );

  //::math::linear::matrix::determinant( mAB );
  ::math::linear::matrix::determinant( m22 );
  ::math::linear::matrix::determinant( m33 );
  ::math::linear::matrix::determinant( m44 );

//::math::linear::matrix::multiply( mAB );
  ::math::linear::matrix::multiply( m22, m22, m22 );
  ::math::linear::matrix::multiply( m33, m33, m33 );
  ::math::linear::matrix::multiply( m44, m44, m44 );

  ::math::linear::matrix::NaN( mAB );
  ::math::linear::matrix::NaN( m22 );
  ::math::linear::matrix::NaN( m33 );
  ::math::linear::matrix::NaN( m44 );

  ::math::linear::matrix::NaN( mAB );
  ::math::linear::matrix::NaN( m22 );
  ::math::linear::matrix::NaN( m33 );
  ::math::linear::matrix::NaN( m44 );

   ::math::linear::matrix::transpose(m22,m22);
   ::math::linear::matrix::transpose(m33,m33);
   ::math::linear::matrix::transpose(m44,m44);
   ::math::linear::matrix::transpose(m22);
   ::math::linear::matrix::transpose(m33);
   ::math::linear::matrix::transpose(m44);

    ::math::linear::matrix::system( m22,v2,v2);
    ::math::linear::matrix::system( m33,v3,v3,v3);
    ::math::linear::matrix::system( m44,v4,v4,v4,v4);

    ::math::linear::matrix::scale( m22, 123.0 );
    ::math::linear::matrix::scale( m33, 123.0 );
    ::math::linear::matrix::scale( m44, 123.0 );

    ::math::linear::matrix::scale( m22, 123.0, m22 );
    ::math::linear::matrix::scale( m33, 123.0, m33 );
    ::math::linear::matrix::scale( m44, 123.0, m44 );

    ::math::linear::matrix::scale( m22, m22, 123.0 );
    ::math::linear::matrix::scale( m33, m33, 123.0 );
    ::math::linear::matrix::scale( m44, m44, 123.0 );

    ::math::linear::matrix::transform( v2, m22, v2 );
    ::math::linear::matrix::transform( v3, m33, v3 );
    ::math::linear::matrix::transform( v4, m44, v4 );

    ::math::linear::matrix::transform( v2, v2, m22 );
    ::math::linear::matrix::transform( v3, v3, m33 );
    ::math::linear::matrix::transform( v4, v4, m44 );


 return 0;
 }