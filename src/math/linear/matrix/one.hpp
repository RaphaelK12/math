#ifndef Dh_math_linear_matrix_one
 #define Dh_math_linear_matrix_one

 // ::math::linear::matrix::one<scalar_name,width_number,height_number>

#include "./structure.hpp"





 namespace math
  {
   namespace linear
    {
     namespace matrix
      {

       template< typename scalar_name, unsigned width_number, unsigned height_number >
        void one( ::math::linear::matrix::structure<scalar_name,width_number,height_number> & m )
         {

          for( unsigned i=0; i< height_number; i++ )
           for( unsigned j=0; j< width_number; j++ )
            {
             m[i][j] = scalar_name( 0 );
             if( i == j ) m[i][j] = scalar_name( 1 );
            }

         }
         
       template< typename scalar_name, unsigned width_number, unsigned height_number >
        void id( ::math::linear::matrix::structure<scalar_name,width_number,height_number> & m )
         {
          ::math::linear::matrix::one( m );
         }

      }
    }
  }

#endif
