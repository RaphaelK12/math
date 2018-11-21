#ifndef math_geometry_interval_scale_hpp_
 #define math_geometry_interval_scale_hpp_

// ::math::geometry::interval::scale( )

#include "../../linear/vector/scale.hpp"
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
           ::math::geometry::interval::structure< scalar_name, dimension_number >       & result
           ::math::linear::vector::structure< scalar_name, dimension_number >      const& pivot
          ,::math::linear::vector::structure< scalar_name, dimension_number >      const& scale
           ::math::geometry::interval::structure< scalar_name, dimension_number >  const& model
         )
         {
          // unsigned i = N_dimension;

          // TODO while( i-- )
            //if( [ i ] < [ i ] ) std::swap( [ i ], [ i ] );

         }

      }
    }
  }

#endif


