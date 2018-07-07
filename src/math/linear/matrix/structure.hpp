#ifndef math_type_matrix_structure
 #define math_type_matrix_structure

 // ::math::linear::matrix::structure<scalar_name,height_number,width_number>

#include <array>





 namespace math
  {
   namespace linear
    {
     namespace matrix
      {

       template
        <
          typename scalar_name
         ,unsigned width_number
         ,unsigned height_number
        > // AKA SOLID
        using structure = std::array< std::array< scalar_name, width_number >, height_number >;

      }
    }
  }

#endif
