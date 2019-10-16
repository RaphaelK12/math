#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

#include "math/topology/topology.hpp"



template< typename data_type >
 void print( ::math::topology::sico::container<data_type> const& sico  )
  {
   std::cout << "{ " << std::endl;
   for( size_t dimension=0; dimension < sico.size(); ++dimension )
    {
     std::cout << "    " <<dimension << ": | " << sico.size(dimension) << " | = ";
     std::cout << "[ ";

     for( size_t index=0; index < sico.size(dimension); ++index )
      {
       std::cout << index << "< ";
       for( size_t face=0; face < sico.simplex(dimension,index).face().size(); ++face )
        {
         std::cout << sico.simplex(dimension,index).face()[face] <<",";
        }
       std::cout << "> ";
      }
     std::cout << " ] "<< std::endl;
    }
   std::cout << "}" << std::endl;
  }

template < typename data_name >
void print( std::vector<data_name> const& v )
 {
  std::cout << "[ ";
  for( auto const& e : v )
   {
    std::cout << e <<", ";
   }
  std::cout << "]" << std::endl;
 }

template < typename data_name >
void print( std::vector<std::vector<data_name>> const& v )
 {
  int dimension=0;
  std::cout << "{ ";
  for( auto const& e : v )
   {
    std::cout << std::endl;
    std::cout << "    " << dimension++ << ": " ;
    std::cout << "|" << v.size() << "| = " ;
    std::cout << "    [" ;
    for( auto const& d : e )
     {
      std::cout << d <<", ";
     }
     std::cout << "]";
   }
    std::cout << std::endl;
  std::cout << "}" << std::endl;
 }

// <svg height="210" width="500">
//    <line x1="0" y1="0" x2="200" y2="200" style="stroke:rgb(255,0,0);stroke-width:2" />
// </svg>

template< typename scalar_name >
 void SVG( std::string const& filename, ::math::topology::sico::container<std::array<scalar_name,2> > const&  sico )
  {
   std::ofstream ofs( filename );
   ofs << "<svg height=\"10\" width=\"10\">" << std::endl;
   for( size_t index=0; index < sico.size(1) ; ++index )
    {
     auto simplex = sico.simplex( 1, index );
     auto first = sico.vertex( simplex.face()[0] ).data();
     auto second = sico.vertex( simplex.face()[1] ).data();
     ofs << "<line "
              << " x1=\""<< 10* first[0]  << "\""
              << " y1=\""<< 10* first[1]  << "\""
              << " x2=\""<< 10* second[0] << "\""
              << " y2=\""<< 10* second[1] << "\""
              <<" style=\"stroke:rgb(255,0,0);stroke-width:0.01\" />"
         << std::endl;
    }
   ofs << "</svg>" << std::endl;
  }

void hyper_point( ::math::topology::sico::container<float> const& sico )
 {
  std::cout << __FUNCTION__ << std::endl;
  ::std::vector<size_t> r;
  ::math::topology::sico::hyper_point( r, 3, 0, sico );  print( r );
 }

void join( ::math::topology::sico::container<float> const& sico )
 {
  std::cout << __FUNCTION__ << std::endl;
  ::math::topology::sico::container<float> r;
  ::math::topology::sico::concatenate( r, sico, sico );
 }

void vertex( ::math::topology::sico::container<float> const& sico )
 {
  std::cout << __FUNCTION__ << std::endl;
  ::std::vector<size_t> r;
  ::math::topology::sico::vertex( r, 3, 0, sico ); print( r );
  ::math::topology::sico::vertex( r, 2, 4, sico ); print( r );
  ::math::topology::sico::vertex( r, 0, 4, sico ); print( r );
}

void link_up( ::math::topology::sico::container<float> const& sico  )
 {
  std::cout << __FUNCTION__ << std::endl;
  std::vector< std::size_t > l;
  ::math::topology::sico::star( l, 1, 0, sico ); print( l );
  ::math::topology::sico::star( l, 1, 1, sico ); print( l );
  ::math::topology::sico::star( l, 1, 2, sico ); print( l );
  ::math::topology::sico::star( l, 1, 3, sico ); print( l );
  ::math::topology::sico::star( l, 2, 3, sico ); print( l );
}

void find( ::math::topology::sico::container<float> const& needle, ::math::topology::sico::container<float> const& haystack  )
 {
  std::cout << __FUNCTION__ << std::endl;
  ::math::topology::sico::container<float> position;
  //::math::topology::sico::find( position, needle, haystack );
  print( position );
 }

void erase( ::math::topology::sico::container<float> const& sico  )
 {
  std::cout << __FUNCTION__ << std::endl;
  ::math::topology::sico::container<float> copy = sico ;
  print( copy );
  copy = sico; std::cout<< "this::erase(0,0): " ;copy.erase(0,0);  print( copy );
  copy = sico; std::cout<< "this::erase(0,1): " ;copy.erase(0,1);  print( copy );
  copy = sico; std::cout<< "this::erase(1,0): " ;copy.erase(1,0);  print( copy );
 }

void trim( ::math::topology::sico::container<float> const& sico  )
 {
  std::cout << __FUNCTION__ << std::endl;
  ::math::topology::sico::container<float> copy = sico ;
  print( copy );
  copy = sico; std::cout<< "this::trim(6): " ;copy.trim(6);  print( copy );
  copy = sico; std::cout<< "this::trim(5): " ;copy.trim(5);  print( copy );
  copy = sico; std::cout<< "this::trim(4): " ;copy.trim(4);  print( copy );
  copy = sico; std::cout<< "this::trim(3): " ;copy.trim(3);  print( copy );
  copy = sico; std::cout<< "this::trim(1): " ;copy.trim(2);  print( copy );
  copy = sico; std::cout<< "this::trim(1): " ;copy.trim(1);  print( copy );
  copy = sico; std::cout<< "this::trim(0): " ;copy.trim(0);  print( copy );
}

void closur( ::math::topology::sico::container<float> const& sico )
 {
  std::cout << __FUNCTION__ << std::endl;
  std::vector< std::vector<std::size_t > > closure;
  print( sico );
  ::math::topology::sico::closure( closure, 0, 1, sico ); print( closure );
  ::math::topology::sico::closure( closure, 1, 0, sico ); print( closure ); 
  ::math::topology::sico::closure( closure, 2, 0, sico ); print( closure );
  ::math::topology::sico::closure( closure, 3, 0, sico ); print( closure );
 }

void star( ::math::topology::sico::container<float> & sico )
 {
  std::cout << __FUNCTION__ << std::endl;
  std::vector< std::size_t >                r0;
  std::vector< std::vector< std::size_t > > rX;
  print( sico );
  ::math::topology::sico::star <float>( r0, 0, 0, sico ); print( r0 );
  ::math::topology::sico::star <float>( rX, 0, 0, sico ); print( rX );
  ::math::topology::sico::star <float>( rX, 1, 0, sico ); print( rX );
  ::math::topology::sico::star <float>( rX, 2, 0, sico ); print( rX );
  ::math::topology::sico::star <float>( rX, 3, 0, sico ); print( rX );
}

void link( ::math::topology::sico::container<float> & sico )
 {
  std::cout << __FUNCTION__ << std::endl;
  std::vector< std::size_t >                r0;

  ::math::topology::sico::link<float>( r0, 0, 0, sico ); print( r0 );
  ::math::topology::sico::link<float>( r0, 1, 0, sico ); print( r0 );
  ::math::topology::sico::link<float>( r0, 2, 0, sico ); print( r0 );
  ::math::topology::sico::link<float>( r0, 3, 0, sico ); print( r0 );

  ::math::topology::sico::link <float>( r0, 0, 0, sico ); print( r0 );
  ::math::topology::sico::link <float>( r0, 0, 1, sico ); print( r0 );
  ::math::topology::sico::link <float>( r0, 0, 2, sico ); print( r0 );
  ::math::topology::sico::link <float>( r0, 0, 3, sico ); print( r0 );

  ::math::topology::sico::link <float>( r0, 1, 0, sico ); print( r0 );
  ::math::topology::sico::link <float>( r0, 1, 1, sico ); print( r0 );
  ::math::topology::sico::link <float>( r0, 1, 2, sico ); print( r0 );
  ::math::topology::sico::link <float>( r0, 1, 3, sico ); print( r0 );

  ::math::topology::sico::link <float>( r0, 2, 0, sico ); print( r0 );
  ::math::topology::sico::link <float>( r0, 2, 1, sico ); print( r0 );
  ::math::topology::sico::link <float>( r0, 2, 2, sico ); print( r0 );
  ::math::topology::sico::link <float>( r0, 2, 3, sico ); print( r0 );

  ::math::topology::sico::link <float>( r0, 3, 0, sico ); print( r0 );
  ::math::topology::sico::link <float>( r0, 3, 1, sico ); print( r0 );
  ::math::topology::sico::link <float>( r0, 3, 2, sico ); print( r0 );
  ::math::topology::sico::link <float>( r0, 3, 3, sico ); print( r0 );
}

void NNG()
 {
  typedef std::array<float,2> data_type;
  ::math::topology::sico::container<data_type>   sico;

  sico.push( {0,0}, {} );
  sico.push( {0,1}, {} );
  sico.push( {1,0}, {} );
  sico.push( {1,3}, {} );

  ::math::topology::sico::NNG<float,2,data_type>( sico );
  print( sico );
 }

void delaunay()
 {
  typedef std::array<double,2> data_type;
  ::math::topology::sico::container<data_type>   sico;

  sico.push( {0,0}, {} );
  sico.push( {1,0}, {} );
  sico.push( {0,2}, {} );
  sico.push( {1,3}, {} );

  ::math::topology::sico::delaunay<double>( sico );
  print( sico );
  SVG( "simple.svg", sico );

  sico.clear();
  for( int i=0; i < 100; ++i )
   {
    sico.push( {rand()/(double)RAND_MAX,rand()/(double)RAND_MAX}, {} );
   }
  ::math::topology::sico::delaunay<double>( sico );
  SVG( "rand-100.svg", sico );

  sico.clear();
  for( int i=0; i < 1000; ++i )
  {
    sico.push( {rand()/(double)RAND_MAX,rand()/(double)RAND_MAX}, {} );
  }
  ::math::topology::sico::delaunay<double>( sico );
  SVG( "rand-1000.svg", sico );
}

void make_tetraedar( ::math::topology::sico::container<float> & sico  )
 {
  std::cout << __FUNCTION__ << std::endl;
  sico.clear();
  sico.push(0, {});  // New point
  sico.push(1, {});  // New point
  sico.push(2, {});  // New point
  sico.push(3, {});  // New point

  sico.push(0, {0,1});  // 0 - line
  sico.push(1, {0,2});  // 1 - line
  sico.push(2, {0,3});  // 2 -line

  sico.push(3, {1,2});  // 3 -line
  sico.push(4, {1,3});  // 4 -line
  sico.push(5, {2,3});  // 5 -line

  sico.push(0, {0,1,3}); // triangle
  sico.push(1, {1,2,5}); // triangle
  sico.push(2, {3,4,5}); // triangle
  sico.push(3, {0,2,4}); // triangle

  ::math::topology::sico::push<float>( sico, 0.123f, {0,1,2,3} ); // tetra
 }


int main( int argc, char *argv[] )
 {
  std::cout << "Hello World" << std::endl;

  ::math::topology::sico::container<float> left;

  left.push(0.0f, {});  // New point
  left.push(0.1f, {});  // New point
  left.push(0.2f, {});  // New point

  left.push(1.0f, {0,1});  // 0 - line
  left.push(1.1f, {0,2});  // 1 - line
  left.push(1.2f, {1,2});  // 2 -line

  left.push(3.0f, {0,1,2}); // triangle
  print( left );

  ::math::topology::sico::container<float> right;

  right.push(0, {});  // New point
  right.push(1, {});  // New point
  right.push(2, {});  // New point
  right.push(3, {});  // New point

  right.push(4, {});  // New point
  right.push(5, {});  // New point
  right.push(6, {});  // New point

  //right.push(-1, {0}); // Change old
  //right.push(-2, {1}); // Change old
  //right.push(-3, {2}); // Change old

  right.push(0, {0,1});  // 0 - line
  right.push(1, {0,2});  // 1 - line
  right.push(2, {0,3});  // 2 -line

  right.push(3, {1,2});  // 3 -line
  right.push(4, {1,3});  // 4 -line
  right.push(5, {3,2});  // 5 -line

  right.push(6, {4,5});  // 6 -line
  right.push(7, {5,6});  // 7 -line
  right.push(8, {4,6});  // 8 -line

  right.push(0, {0,1,3}); // triangle
  right.push(1, {1,2,5}); // triangle
  right.push(2, {3,4,5}); // triangle
  right.push(3, {0,2,4}); // triangle

  right.push(4, {6,7,8}); // triangle

  ::math::topology::sico::push<float>( right, 0.123f, {0,1,2,3} ); // tetra
  print( right );

  ::math::topology::sico::container<float> tetra;
  make_tetraedar( tetra );
  print( tetra );

  right.find( {0,1,2,3} );

  hyper_point( right );
  join( right );
  vertex( right );
  link_up( right );
  erase( left );
  erase( right );
  find( left, right );
  trim( right );
  closur( right );
  star( tetra );
  link( tetra );
  NNG();
  delaunay();

  std::vector< std::vector< std::size_t> >              position;

  //::math::topology::sico::find( position, left, right );

  std::cout << "End" << std::endl;
  std::cin.get();
  return EXIT_SUCCESS;
 }

