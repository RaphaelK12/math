#ifndef math_type_matrix_transpose
 #define math_type_matrix_transpose

 // ::math::linear::matrix::transpose<scalar_name,dimension_number>(a,b)
 // ::math::linear::matrix::transpose<scalar_name,dimension_number>(a)

#include "./structure.hpp"





 namespace math
  {
   namespace linear
    {
     namespace matrix
      {

       template< typename scalar_name, unsigned dimension_number>
        void transpose
         (
           ::math::linear::matrix::structure<scalar_name,dimension_number,dimension_number>      & result
          ,::math::linear::matrix::structure<scalar_name,dimension_number,dimension_number> const& m
         )
         {
          for( unsigned i=0; i< dimension_number; i++ )
           for( unsigned j=0; j< dimension_number; j++ )
            {
             result[i][j] = m[j][i];
            }
         }

       template< typename scalar_name, unsigned dimension_number>
        void transpose
         (
          ::math::linear::matrix::structure<scalar_name,dimension_number,dimension_number> & m
         )
         {
          for( unsigned i=0; i< dimension_number; i++ )
           for( unsigned j=0; j< dimension_number; j++ )
            {
             std::swap<scalar_name>( m[i][j], m[j][i] );
            }
         }

      }
    }
  }

#endif
