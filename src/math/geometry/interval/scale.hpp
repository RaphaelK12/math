#ifndef math_geometry_interval_scale_hpp_
 #define math_geometry_interval_scale_hpp_

// ::math::geometry::interval::scale( )

#include "./structure.hpp"


 namespace math
  {
   namespace geometry
    {
     namespace interval
      {

       template< typename scalar_name, unsigned dimension_number >
        inline
        bool
        scale
         (
                     ::math::geometry::interval::structure< scalar_name, dimension_number >               & P_struct
          ,typename  ::math::geometry::interval::structure< scalar_name, dimension_number >::T_point const& P_point
         )
         {
                       unsigned i = N_dimension;

          //while( i-- )
            //if( M1_hi[ i ] < M1_lo[ i ] ) std::swap( M1_hi[ i ], M1_lo[ i ] );

         }

      }
    }
  }

#endif


