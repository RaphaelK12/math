#ifndef math_geometry_interval_translate_hpp_
 #define math_geometry_interval_translate_hpp_

// ::math::geometry::interval::translate( )

#include "./structure.hpp"

#include "../../linear/vector/addition.hpp"



 namespace math
  {
   namespace geometry
    {
     namespace interval
      {

       template< typename scalar_name, unsigned dimension_number >
        inline
        void
        translate
         (
                     ::math::geometry::interval::structure< scalar_name, dimension_number >                  & instance
          ,typename  ::math::geometry::interval::structure< scalar_name, dimension_number >::point_type const& point
         )
         {
          ::math::linear::vector::addition( instance[0], point );
          ::math::linear::vector::addition( instance[1], point );
         }

      }
    }
  }

#endif