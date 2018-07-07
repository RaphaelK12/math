#ifndef math_geometry_homography_transform
#define math_geometry_homography_transform

 // ::math::linear::homography::transform( )

#include "../vector/vector.hpp"
#include "../matrix/matrix.hpp"

namespace math
 {
  namespace linear
   {
    namespace homography
     {

      template<  typename scalar_name,unsigned dimension_number >
       void transform
        (
          ::math::linear::vector::structure< scalar_name, dimension_number >                                   & result
         ,::math::linear::matrix::structure<scalar_name,dimension_number+1,dimension_number+1> const& matrix
         ,::math::linear::vector::structure< scalar_name, dimension_number >                              const& point
         )
        {
         scalar_type divisor  = matrix[2][0] * point[0] +  matrix[2][1] * point[1] + matrix[2][2];

         result[0] = ( matrix[0][0] * point[0] +  matrix[0][1] * point[1] + matrix[0][2])/divisor;
         result[1] = ( matrix[1][0] * point[0] +  matrix[1][1] * point[1] + matrix[1][2])/divisor;

         return ;
        }

     }
   }
 }

#endif
