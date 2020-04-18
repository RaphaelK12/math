#ifndef math_geometry_interval_size_hpp_
 #define math_geometry_interval_size_hpp_
 
// ::math::geometry::interval::size( )

#include "./structure.hpp"
#include "../../linear/vector/addition.hpp"
#include "../../linear/vector/scale.hpp"



 namespace math
  {
   namespace geometry
    {
     namespace interval
      {

       template< typename scalar_name, unsigned dimension_number >
        inline
        void
        size
         (
          typename ::math::geometry::interval::structure< scalar_name, dimension_number >::point_type     & point
          ,        ::math::geometry::interval::structure< scalar_name, dimension_number >            const& instance
         )
         {
          ::math::linear::vector::subtraction( point, instance[1], instance[0] );
         }
      }
    }
  }

#endif