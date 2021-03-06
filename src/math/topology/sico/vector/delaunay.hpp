#ifndef math_topology_sico_delaunay
#define math_topology_sico_delaunay

// ::math::topology::sico::delaunay<data_name>

#include <vector>
#include <array>
#include "../../../linear/vector/distance.hpp"
#include "../../../geometry/circle/inside.hpp"
#include "../../../geometry/circle/construct.hpp"
#include "../property/point.hpp"
#include "./nng.hpp"

namespace math
 {
  namespace topology
   {
    namespace sico
     {

     template
       <
         typename   scalar_name
        ,typename     data_name //!< Essentially whatever. Copyable
       >
       std::size_t delaunay //!< Delaunay Triangulation
       (
         ::math::topology::sico::structure<data_name>       & result
       )
       {
       ::math::topology::sico::NNG<scalar_name,2,data_name>( result );

        for( std::size_t a=0; a < result.size(1); ++a )
         {
          auto const& simplex = result.simplex( 1, a );
          auto const& B = simplex.face()[0];
          auto const& C = simplex.face()[1];

          auto const & first   = ::math::topology::sico::property::point<scalar_name,2>( result.vertex( B ) );
          auto const & second  = ::math::topology::sico::property::point<scalar_name,2>( result.vertex( C ) );
          for( std::size_t A =0; A < result.size(0); ++A )
           {
            if( A == B ) continue;
            if( A == C ) continue;
            auto const & third  = ::math::topology::sico::property::point<scalar_name,2>( result.vertex( A ) );

            ::math::geometry::circle::simple<scalar_name,2> circle;
            if( false == ::math::geometry::circle::construct( circle, first, second, third ) )
             {
              continue;
             }
            bool flag = true;
            for( std::size_t T =0; T < result.size(0); ++T )
             {
              if( T == A ) continue;
              if( T == B ) continue;
              if( T == C ) continue;
              auto const & fourth  = ::math::topology::sico::property::point<scalar_name,2>( result.vertex( T ) );
              if( true == ::math::geometry::circle::inside<scalar_name>( circle, fourth ) )
               {
                flag = false;
                break;
               }
             }

            if( true == flag )
             {
              auto b = result.push( data_name{}, { A, C } );
              auto c = result.push( data_name{}, { A, B } );
              result.push( data_name{}, { a, b, c } );
            }
           }
         }

        return result.size();
       }

     }
   }
 }

#endif
