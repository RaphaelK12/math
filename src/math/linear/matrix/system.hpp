#ifndef Dh_math_linear_matrix_set
#define Dh_math_linear_matrix_set

 // ::math::linear::matrix::system(m,x,y)
 // ::math::linear::matrix::system(m,x,y,z)
 // ::math::linear::matrix::system(m,x,y,z,t)

#include "../vector/vector.hpp"
#include "./structure.hpp"


 namespace math
  {
   namespace linear
    {
     namespace matrix
      {

       template< typename scalar_name >
        void system
         (
           ::math::linear::matrix::structure<scalar_name,2,2>          & result
          ,::math::linear::vector::structure<scalar_name,2>      const & x
          ,::math::linear::vector::structure<scalar_name,2>      const & y
         )
         {
          result[0][0] = x[0]; result[0][1] = y[0];
          result[1][0] = x[1]; result[1][1] = y[1];
         }

       template< typename scalar_name >
        void system
         (
           ::math::linear::matrix::structure<scalar_name,3,3>          & result
          ,::math::linear::vector::structure<scalar_name,3>      const & x
          ,::math::linear::vector::structure<scalar_name,3>      const & y
          ,::math::linear::vector::structure<scalar_name,3>      const & z
         )
         {
          result[0][0] = x[0]; result[0][1] = y[0]; result[0][2] = z[0];
          result[1][0] = x[1]; result[1][1] = y[1]; result[1][2] = z[1];
          result[2][0] = x[2]; result[2][1] = y[2]; result[2][2] = z[2];
         }

       template< typename scalar_name >
        void system
         (
           ::math::linear::matrix::structure<scalar_name,4,4>          & result
          ,::math::linear::vector::structure<scalar_name,4>      const & x
          ,::math::linear::vector::structure<scalar_name,4>      const & y
          ,::math::linear::vector::structure<scalar_name,4>      const & z
          ,::math::linear::vector::structure<scalar_name,4>      const & t
         )
         {
          result[0][0] = x[0]; result[0][1] = y[0]; result[0][2] = z[0]; result[0][3] = t[0];
          result[1][0] = x[1]; result[1][1] = y[1]; result[1][2] = z[1]; result[1][3] = t[1];
          result[2][0] = x[2]; result[2][1] = y[2]; result[2][2] = z[2]; result[2][3] = t[2];
          result[3][0] = x[3]; result[3][1] = y[3]; result[3][2] = z[3]; result[3][3] = t[3];
         }


      }
    }
  }

#endif
