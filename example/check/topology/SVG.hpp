#ifndef _6dacc71d2544408c901ba6ca7e615f09
#define _6dacc71d2544408c901ba6ca7e615f09


#include "math/topology/topology.hpp"

template< typename scalar_name, typename data_name >
 void SVG( std::string const& filename, ::math::topology::sico::structure<data_name> const&  sico )
  {
   scalar_name scale  = scalar_name( 10.00 );
   scalar_name radius = scalar_name(  0.15 );
   scalar_name line   = scalar_name(  0.05 );

   std::ofstream ofs( filename );
   ofs << "<svg height=\"32\" width=\"32\">" << std::endl;

   for( size_t index=0; index < sico.size(2) ; ++index )
    {
     std::vector< std::size_t > vertex;
     ::math::topology::sico::vertex<data_name>( vertex, 2, index, sico );

     auto first = ::math::topology::sico::property::point<scalar_name,2>(  sico.vertex( vertex[0] ) );
     auto second = ::math::topology::sico::property::point<scalar_name,2>( sico.vertex( vertex[1] ) );
     auto third = ::math::topology::sico::property::point<scalar_name,2>(  sico.vertex( vertex[2] ) );

     decltype(first) center = { (first[0]+second[0]+third[0])/3, (first[1]+second[1]+third[1])/3  };
     ::math::linear::vector::convex<scalar_name>( first,   first, 0.2f, center );
     ::math::linear::vector::convex<scalar_name>( second, second, 0.2f, center );
     ::math::linear::vector::convex<scalar_name>( third,   third, 0.2f, center );

     ofs << "<polygon "
              << " points=\""
              << scale *  first[0] << ","  << scale *  first[1] << " "
              << scale * second[0] << ","  << scale * second[1] << " "
              << scale *  third[0] << ","  << scale *  third[1]
              << "\""
              <<" style=\"fill:rgb(127,255,127);stroke:none\" />"
         << std::endl;
    }

   for( size_t index=0; index < sico.size(1) ; ++index )
    {
     auto simplex = sico.simplex( 1, index );
     auto first = ::math::topology::sico::property::point<scalar_name,2>( sico.vertex( simplex.face()[0] ) );
     auto second = ::math::topology::sico::property::point<scalar_name,2>( sico.vertex( simplex.face()[1] ) );

     ofs << "<line "
              << " x1=\""<< scale * first[0]  << "\""
              << " y1=\""<< scale * first[1]  << "\""
              << " x2=\""<< scale * second[0] << "\""
              << " y2=\""<< scale * second[1] << "\""
              <<" style=\"stroke:rgb(255,0,0);stroke-width:"<< line << "\" />"
         << std::endl;
    }

   for( size_t index=0; index < sico.size(0) ; ++index )
    {
     auto vertex =  sico.vertex( index );
     auto center = ::math::topology::sico::property::point<scalar_name,2>( vertex );
     std::string  color = "#0000ff";

     switch( ::math::topology::sico::property::ID( vertex ) )
      {
       case ( 0 ): color="red"; break;
       case ( 1 ): color="green"; break;
       case ( 2 ): color="blue"; break;
       case ( 3 ): color="cyan"; break;
       case ( 4 ): color="yellow"; break;
       case ( 5 ): color="magenta"; break;
       case ( 6 ): color="gold"; break;
       case ( 7 ): color="chocolate"; break;
       case ( 8 ): color="lime"; break;
       case ( 9 ): color="purple"; break;
     }

     ofs << "<circle "
       << " cx=\""<< scale * center[0]  << "\""
       << " cy=\""<< scale * center[1]  << "\""
       << " r=\""<< radius  << "\""
       <<" style=\"fill:" << color <<  ";stroke:none;\" />"
       << std::endl;
    }

   ofs << "</svg>" << std::endl;
  }

#endif
