#ifndef Dh_math_geometry_homography_transform
#define Dh_math_geometry_homography_transform

 // ::math::linear::homography::transform( )

#include "../vector/vector.hpp"
#include "../matrix/matrix.hpp"

namespace math
 {
  namespace linear
   {
    namespace homography
     {

      template<  typename scalar_name >
       void transform
        (
          ::math::linear::vector::structure<      scalar_name, 2 >           & result
         ,::math::linear::homography::structure<  scalar_name, 3 >      const& matrix
         ,::math::linear::vector::structure<      scalar_name, 2 >      const& point
         )
        {
         scalar_name divisor  = matrix[2][0] * point[0] +  matrix[2][1] * point[1] + matrix[2][2];

         result[0] = ( matrix[0][0] * point[0] +  matrix[0][1] * point[1] + matrix[0][2])/divisor;
         result[1] = ( matrix[1][0] * point[0] +  matrix[1][1] * point[1] + matrix[1][2])/divisor;

         return ;
        }

      template<  typename scalar_name >
       void transform
        (
          ::math::linear::vector::structure<      scalar_name, 2 >           & result
         ,::math::linear::homography::structure<  scalar_name, 3 >      const& matrix
         )
        {
         ::math::linear::vector::structure<      scalar_name, 2 >           tmp;

         ::math::lnear::homography::transform( tmp, matrix, result );

         result = tmp;
         return ;
        }


      template<  typename scalar_name >
       void transform
        (
          ::math::linear::vector::structure<      scalar_name, 3 >           & result
         ,::math::linear::homography::structure<  scalar_name, 4 >      const& matrix
         ,::math::linear::vector::structure<      scalar_name, 3 >      const& point
         )
        {
         scalar_name divisor  =   matrix[2][0] * point[0]
                               +  matrix[2][1] * point[1]
                               +  matrix[2][2] * point[2]
                               +  matrix[2][3];

         result[0] = ( matrix[0][0] * point[0] +  matrix[0][1] * point[1] + matrix[0][2])/divisor;
         result[1] = ( matrix[1][0] * point[0] +  matrix[1][1] * point[1] + matrix[1][2])/divisor;
         result[2] = ( matrix[2][0] * point[0] +  matrix[2][1] * point[1] + matrix[2][2])/divisor;

         return ;
        }

      template<  typename scalar_name >
       void transform
        (
          ::math::linear::vector::structure<      scalar_name, 3 >           & result
         ,::math::linear::homography::structure<  scalar_name, 4 >      const& matrix
         )
        {
         ::math::linear::vector::structure<      scalar_name, 3 >           tmp;

         ::math::linear::homography::transform( tmp, matrix, result );

         result = tmp;
         return ;
        }


     }
   }
 }

#endif
