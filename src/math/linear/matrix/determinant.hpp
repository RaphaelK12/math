#ifndef Dh_math_linear_matrix_determinant
 #define Dh_math_linear_matrix_determinant

 // ::math::linear::matrix::determinant<scalar_name,width_number,height_number>

#include "./structure.hpp"


 namespace math
  {
   namespace linear
    {
     namespace matrix
      {

       template< typename scalar_name, unsigned width_number, unsigned height_number >
        scalar_name 
        determinant
         (
          ::math::linear::matrix::structure<scalar_name,width_number,height_number> const& m
         )
         {
          // TODO
         }

       template
        <
          typename scalar_name
        >
        scalar_name determinant
         (
          ::math::linear::matrix::structure<scalar_name,2,2> const& m
         )
         {
          return m[0][0]*m[1][1] - m[1][0]*m[0][1];
         }


       template
        <
          typename scalar_name
        >
        scalar_name determinant
         (
          ::math::linear::matrix::structure<scalar_name,3,3> const& m
         )
         {
          return ( m[0][0] * ( m[1][1] * m[2][2] -  m[1 ][2] * m[2][1] )
                  -m[0][1] * ( m[1][0] * m[2][2] -  m[1 ][2] * m[2][0] )
                  +m[0][2] * ( m[1][0] * m[2][1] -  m[1 ][1] * m[2][0] )
                  );
         }

       template
        <
          typename scalar_name
        >
        scalar_name determinant
         (
          ::math::linear::matrix::structure<scalar_name,4,4> const& m
         )
         {
          return  m[ 0][ 0 ]
            *(                                                  
              + m[ 1][ 1 ]*( m[ 2 ][ 2 ]*m[ 3 ][ 3 ]- m[ 2 ][ 3 ]*m[ 3 ][ 2 ] )
              - m[ 1][ 2 ]*( m[ 2 ][ 1 ]*m[ 3 ][ 3 ]- m[ 2 ][ 3 ]*m[ 3 ][ 1 ] )
              + m[ 1][ 3 ]*( m[ 2 ][ 1 ]*m[ 3 ][ 2 ]- m[ 2 ][ 2 ]*m[ 3 ][ 1 ] )
             )                                                         
         -m[ 0][ 1 ]                                                   
            *(                                                         
              + m[ 1][ 0 ]*( m[ 2 ][ 2 ]*m[ 3 ][ 3 ]- m[ 2 ][ 3 ]*m[ 3 ][ 2 ] )
              - m[ 1][ 2 ]*( m[ 2 ][ 0 ]*m[ 3 ][ 3 ]+ m[ 2 ][ 3 ]*m[ 3 ][ 0 ] )
              + m[ 1][ 3 ]*( m[ 2 ][ 0 ]*m[ 3 ][ 2 ]- m[ 2 ][ 2 ]*m[ 3 ][ 0 ] )
             )                                                      
           +m[ 0][ 2 ]                                            
            *(                                                      
              + m[ 1 ][ 0 ]*( m[ 2 ][ 1 ]*m[ 3 ][ 3 ]- m[ 2 ][ 3 ]*m[ 3 ][ 1 ] )
              - m[ 1 ][ 1 ]*( m[ 2 ][ 0 ]*m[ 3 ][ 3 ]+ m[ 2 ][ 3 ]*m[ 3 ][ 0 ] )
              + m[ 1 ][ 3 ]*( m[ 2 ][ 0 ]*m[ 3 ][ 1 ]- m[ 2 ][ 1 ]*m[ 3 ][ 0 ] )
             )                                                          
           -m[ 0][ 3 ]                                                  
            *(                                                          
              + m[ 1 ][ 0 ]*( m[ 2 ][ 1 ]*m[ 3 ][ 2 ]- m[ 2 ][ 2 ]*m[ 3 ][ 1 ] )
              - m[ 1 ][ 1 ]*( m[ 2 ][ 0 ]*m[ 3 ][ 2 ]+ m[ 2 ][ 2 ]*m[ 3 ][ 0 ] )
              + m[ 1 ][ 2 ]*( m[ 2 ][ 0 ]*m[ 3 ][ 1 ]- m[ 2 ][ 1 ]*m[ 3 ][ 0 ] )
             );
         }


      }
    }
  }

#endif
