#ifndef math_linear_vector_BMP
#define math_linear_vector_BMP

// ::math::linear::vector::BMP<scalar_name,dimesion_number>

#include <array>
#include <vector>
#include <limits>

#include "./distance.hpp"

 namespace math
  {
   namespace linear
    {
     namespace vector
      {

     template
       <
         typename    scalar_name
        ,unsigned  dimesion_number
       >
       void BMP //!< Best matching pairs
       (
         ::std::vector< std::size_t >                                      & to_left  //!< index toward left  side.
        ,::std::vector< std::size_t >                                      & to_right //!< index toward right side.
        ,::std::vector< std::array< scalar_name, dimesion_number >  > const& left
        ,::std::vector< std::array< scalar_name, dimesion_number >  > const& right
       )
       {
        to_left.resize(  right.size()  ); std::fill( right.begin(), right.end(),  std::size_t( -1 ) );
        to_right.resize(  left.size() ); std::fill( left.begin(),  left.end(),   std::size_t( -1 ) );

        while( true )
         {
          std::size_t alone_left = std::size_t( -1 );
          for( std::size_t index_left=0; index_left < left.size(); ++index_left )
           {
            if( std::size_t( -1 ) == to_right[index_left] )
             {
              alone_left = index_left;
              break;
             }
           }

          if( std::size_t( -1 ) == alone_left )
           {
            return;
           }

          scalar_name nearest = std::numeric_limits<scalar_name>::max();
          std::size_t neighbor_right = std::size_t( -1 );

          for( std::size_t candidate_right=0; candidate_right < right.size(); ++candidate_right )
           {
            scalar_name distance = ::math::linear::vector::distance( left[alone_left], right[ candidate_right ] );
            if( nearest <= distance )
             {
              continue;
             }

            if( std::size_t( -1 ) != to_left[ candidate_right ] )
             {
              scalar_name d = ::math::linear::vector::distance( left[ to_left[ candidate_right ] ], right[ candidate_right ] );
              if( distance < d )
               {
                nearest = distance;
                neighbor_right = candidate_right;
               }
             }
            else
             {
              nearest = distance;
              neighbor_right = candidate_right;
             }
           }

          if( std::size_t( -1 ) == neighbor_right )
           {
            return;
           }

          if( std::size_t( -1 ) != to_left[ neighbor_right ] )
           {
            to_right[ to_left[ neighbor_right ] ]= std::size_t( -1 );
           }

          to_left[  neighbor_right ] = alone_left;
          to_right[  alone_left ] = neighbor_right;
         }
       }

     }
   }
 }

#endif
