#ifndef math_geometry_interval_scale_hpp_
 #define math_geometry_interval_scale_hpp_

// ::math::geometry::interval::inflate( )

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
        inflate
         (
           ::math::geometry::interval::structure< scalar_name, dimension_number >       & result
          ,::math::linear::vector::structure< scalar_name, dimension_number >      const& pivot
          ,::math::linear::vector::structure< scalar_name, dimension_number >      const& scale
          ,::math::geometry::interval::structure< scalar_name, dimension_number >  const& model
         )
         {
          auto index = dimension_number;

          while( index-- )
           {
            result[1][index] = scale[index]*(model[1][index] - pivot[index] ) + pivot[index];
            result[0][index] = scale[index]*(model[0][index] - pivot[index] ) + pivot[index];
           }

         }

      }
    }
  }

#endif


