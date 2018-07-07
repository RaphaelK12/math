#ifndef math_type_affine_structure
 #define math_type_affine_structure

 // ::math::linear::affine::structure<scalar_name,dimension_number>

#include <array>
#include "../matrix/structure.hpp"
#include "../vector/vector.hpp"



 namespace math
  {
   namespace linear
    {
     namespace affine
      {

       template
        <
          typename scalar_name
         ,unsigned dimension_number
        >
        class structure
         {
          public:
            typedef ::math::linear::matrix::structure<scalar_name,dimension_number,dimension_number> matrix_type;
            typedef ::math::linear::vector::structure<scalar_name,dimension_number> vector_type;

          public:
            matrix_type const& matrix()const
             {
              return m_matrix;
             }
            matrix_type & matrix()
             {
              return m_matrix;
             }
          private:
            matrix_type m_matrix;

          public:
            vector_type const& vector()const
             {
              return m_vector;
             }
            vector_type & vector()
             {
              return m_vector;
             }
          private:
            vector_type m_vector;
         };

      }
    }
  }

#endif
