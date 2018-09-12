#ifndef math_geometry_interval_extend_hpp_
 #define math_geometry_interval_extend_hpp_
 
// ::math::geometry::interval::extend( )

#include "./structure.hpp"

#include "../../linear/vector/max.hpp"
#include "../../linear/vector/min.hpp"

 namespace math
  {
   namespace geometry
    {
     namespace interval
      {

       template
        <
          typename scalar_name
         ,unsigned dimension_number
        >
       void extend
        (
                   ::math::geometry::interval::structure<scalar_name,dimension_number>                  & interval
         ,typename ::math::geometry::interval::structure<scalar_name,dimension_number>::point_type const& point
        )
        {
         auto max = point;
         ::math::linear::vector::max( max, max, interval[0] );
         ::math::linear::vector::max( max, max, interval[1] );
         auto min = point;
         ::math::linear::vector::min( min, min, interval[0] );
         ::math::linear::vector::min( min, min, interval[1] );

         interval[0] = min;
         interval[1] = max;
        }

       template
        <
          typename scalar_name
         ,unsigned dimension_number
        >
       void extend
        (
          ::math::geometry::interval::structure<scalar_name,dimension_number>      & result
         ,::math::geometry::interval::structure<scalar_name,dimension_number> const& other
        )
        {
         ::math::geometry::interval::extend( result, other[0] );
         ::math::geometry::interval::extend( result, other[1] );
        }

      }
    }
  }

#endif