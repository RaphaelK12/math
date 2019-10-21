#ifndef math_topology_sico_NNG
#define math_topology_sico_NNG

// ::math::topology::sico::NNG<data_name>

#include <array>
#include <vector>
#include <limits> 

#include "../structure.hpp"
#include "../../../linear/vector/distance.hpp"
#include "../property/point.hpp"

namespace math
 {
  namespace topology
   {
    namespace sico
     {

     template
       <
         typename    scalar_name
        ,unsigned  dimesion_number
        ,typename      data_name //!< Essentially whatever. Copyable
       >
       std::size_t NNG //!< Nearest neighbor graph
       (
         ::math::topology::sico::structure<data_name>                     & result
       )
       {
        result.trim( 0 );
        for( std::size_t index=0; index< result.size(0); ++index )
         {
          size_t neighbor = result.size(0);
          scalar_name nearest = std::numeric_limits<scalar_name>::max();
          auto const & left  = ::math::topology::sico::property::point<scalar_name,dimesion_number>( result.simplex( 0, index ) );

          for( std::size_t j=0; j < result.size(0); ++j )
           {
            if( index == j )
             {
              continue;
             }

            scalar_name distance;
            {
             auto const & right = ::math::topology::sico::property::point<scalar_name,dimesion_number>( result.simplex( 0, j ) );
             distance = ::math::linear::vector::distance( left, right );
            }
            if( distance < nearest )
             {
              nearest = distance;
              neighbor = j;
             }

           }
           result.push( data_name{}, {index,neighbor} );
         }
        return result.size();
       }

     }
   }
 }

#endif
