#ifndef math_geometry_interval_confine_hpp_
 #define math_geometry_interval_confine_hpp_

// ::math::geometry::interval::confine( result, point, interval )
// ::math::geometry::interval::confine( result, interval )

#include "./structure.hpp"


 namespace math
  {
   namespace geometry
    {
     namespace interval
      {

       template< typename scalar_name, unsigned dimension_number >
        inline
        void
        confine
         (
           ::math::linear::vector::structure< scalar_name, dimension_number >           & result
          ,::math::linear::vector::structure< scalar_name, dimension_number >      const& point
          ,::math::geometry::interval::structure< scalar_name, dimension_number >  const& structure
         )
         {
          auto index = dimension_number;

          auto lo = structure[0];
          auto hi = structure[1];

          while( index-- )
           {
            auto const& v = point[index];
            if( v < lo[index] ){ result[index] = lo[index]; continue; } 
            if( hi[index] < v ){ result[index] = hi[index]; continue; } 
            result[index] = v;
           }
         }

       template< typename scalar_name, unsigned dimension_number >
        inline
        void
        confine
         (
           ::math::linear::vector::structure< scalar_name, dimension_number >           & result
          ,::math::geometry::interval::structure< scalar_name, dimension_number >  const& structure
         )
         {
          auto index = dimension_number;

          auto lo = structure[0];
          auto hi = structure[1];

          while( index-- )
           {
            auto const& v = result[index];
            if( v < lo[index] ){ result[index] = lo[index]; continue; } 
            if( hi[index] < v ){ result[index] = hi[index]; continue; } 
           }
         }

      }
    }
  }

#endif


