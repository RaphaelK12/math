#ifndef Dh_math_linear_homography_structure
 #define Dh_math_linear_homography_structure

 // ::math::linear::homography::structure<scalar_name,dimension_number>

#include "../matrix/matrix.hpp"



 namespace math
  {
   namespace linear
    {
     namespace homography
      {

       template
        <
          typename scalar_name
         ,unsigned dimension_number
        > // Currently limited to square matrix
         using structure = ::math::linear::matrix::structure< scalar_name, dimension_number, dimension_number >;

      }
    }
  }

#endif
