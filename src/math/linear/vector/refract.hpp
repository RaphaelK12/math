#ifndef math_library_linear_algebra__vector_refract_HPP_
 #define math_library_linear_algebra__vector_refract_HPP_

/*refract( & result_param
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
        void
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
         }

      }
    }
  }

#endif
