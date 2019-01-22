#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>


#include "math/math.hpp"
//#include "pnm/pnm.hpp"


int main( int argc, char *argv[] )
 {
  std::cout << "Hello World" << std::endl;

  std::cout << "normal(1,1)" <<::math::function::distribution::normal<double>(1,1) << std::endl;
  std::cout << "normal(1)" <<::math::function::distribution::normal<double>(1) << std::endl;
  std::cout << "normal_invert(1,1,1)" <<::math::function::distribution::normal_invert<double>(1,1,1) << std::endl;
  std::cout << "normal_cumulative(0.99,1)" << ::math::function::distribution::normal_cumulative<double>(0.99,1.0) << std::endl;

  std::vector< std::uint8_t> image;
  auto height = 1500;
  auto width  = 1500;
  image.resize( height * width, 0 );

  for( int i=0; i< width; ++i)
   {
    double x = 5*( i/(width/2.0) - 1.0);

    auto v = ::math::function::distribution::normal<double>( x, 0.9, 0 );
    int y= int( ((v) * (height/30) +(height/2) ) ); y = height-y-1; auto index = width *y + i;image[ index ] = 255;

    v = ::math::function::distribution::normal<double>( x, 0.8, 0 );
    y= int( ((v) * (height/30) +(height/2) ) ); y = height-y-1;index = width *y + i; image[ index ] = 255;

    v = ::math::function::distribution::normal<double>( x, 0.7, 0 );
    y= int( ((v) * (height/30) +(height/2) ) ); y = height-y-1;index = width *y + i;  image[ index ] = 255;

    v = ::math::function::distribution::normal<double>( x, 0.6, 0 );
    y= int( ((v) * (height/30) +(height/2) ) ); y = height-y-1;index = width *y + i; image[ index ] = 255;


    //index = width *i + width/2;image[ index ] = 255;
   image[ index ] = 255;
   }

  //{ std::ofstream( "image2.pgm" ) << PNM::save( image, width, height, PNM::P2 ); }

  //std::cin.get();
  return EXIT_SUCCESS;
 }

