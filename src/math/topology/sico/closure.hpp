#ifndef math_topology_sico_closure
#define math_topology_sico_closure

// ::math::topology::sico::closure <data_name>( result, dimension, index, container )
// ::math::topology::sico::closure <data_name>( result<<>>, dimension, index, container )
// ::math::topology::sico::closure <data_name>( container, dimension, index, container )

#include <algorithm>
#include <vector>
#include "./container.hpp"

namespace math
 {
  namespace topology
   {
    namespace sico
     {

      template
       <
         typename  data_name
       >
       inline size_t closure // All faces of given simplex( dimension, index )
        (
           std::vector< std::size_t >              & result
         , std::size_t const& dimension
         , std::size_t const& index
         ,::math::topology::sico::container<data_name> const& sc // can be very big.
        )
        {
         if( false == sc.exists( dimension, index ) )
          {
           return result.size();
          }

         auto const& simplex = sc.simplex( dimension, index );
         result = simplex.face();

         return result.size();
        }

      template
       <
         typename  data_name
       >
       inline size_t closure // All (sub-)faces
        (
           std::vector< std::vector< std::size_t > >         & result
         , std::size_t                                         dimension
         , std::size_t                                  const& index
         , ::math::topology::sico::container<data_name> const& sc // can be very big.
        )
        {
         result.clear();
         if( false == sc.exists( dimension, index ) )
          {
           return result.size();
          }
         result.resize( dimension + 1 );
         result[dimension].push_back( index );

         std::vector< std::size_t > closure;
         for( ; dimension; dimension-- )
          {
           auto const& face = result[ dimension ];
           auto & lower_level = result[ dimension -1 ];

           for( auto const& index : face )
            {
             ::math::topology::sico::closure( closure, dimension, index, sc );
             lower_level.insert( lower_level.end(), closure.begin(), closure.end() );
            }
           std::sort( lower_level.begin(), lower_level.end() );
           lower_level.erase( std::unique( lower_level.begin(), lower_level.end() ), lower_level.end() );
          }

         return result.size();
        }

      template
       <
         typename  data_name
       >
       inline size_t closure // All (sub-)faces as new topology
        (
           ::math::topology::sico::container<data_name>      & result
         , std::size_t                                  const& dimension
         , std::size_t                                  const& index
         , ::math::topology::sico::container<data_name> const& sc // can be very big.
        )
        {
         result.clear();
         if( false == sc.exists( dimension, index ) )
          {
           return result.size();
          }

          // TODO
         std::vector< std::vector< std::size_t > > closure;
         ::math::topology::sico::closure( closure, dimension, index, sc );

         // TODO calc reindex
         for( std::size_t level=1; level < dimension; ++level )
          {
           // TODO
          }

         return result.size();
        }

     }
   }
 }

#endif
