#ifndef math_library_linear_algebra__vector_refract_HPP_
 #define math_library_linear_algebra__vector_refract_HPP_

/* ::math::linear::vector::refract( & result_param
          , ray_param
          , normal_param
          ,scalar_name  const& air_param
          ,scalar_name  const& watter_param
         )*/



#include "./structure.hpp"





 namespace math
  {
   namespace linear
    {
     namespace vector
      {

       template< typename scalar_name, unsigned dimension_number >
        inline
        bool
        refract
         (
           ::math::linear::vector::structure< scalar_name, dimension_number >      & result_param
          ,::math::linear::vector::structure< scalar_name, dimension_number > const& ray_param
          ,::math::linear::vector::structure< scalar_name, dimension_number > const& normal_param
          ,scalar_name  const& air_param
          ,scalar_name  const& watter_param
         )
         {
          result_param = ray_param;

          scalar_name r = air_param/watter_param;
          scalar_name c = -::math::linear::vector::dot( ray_param, normal_param );

          scalar_name d = scalar_name(1)-r*r*(scalar_name(1)-c*c);
          if( d < 0 )
           {
            return false;
           }
          result_param = r * ray_param + ( r*c - sqrt( d )  ) * normal_param;
          return true;
         }

      }
    }
  }

#endif
