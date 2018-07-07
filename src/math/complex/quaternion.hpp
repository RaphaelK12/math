#ifndef Dh_math_complex_quaternion_HPP_
 #define Dh_math_complex_quaternion_HPP_

 // ::math::complex::quaternion::structure<scalar_name,dimension_number>

#include <array>


 namespace math
  {
   namespace complex
    {
     namespace quaternion
      {

       template
        <
          typename scalar_name
        >
         using structure = std::array< scalar_name, 4 >;

      }
    }
  }

#endif
