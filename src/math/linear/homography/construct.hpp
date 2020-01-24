#ifndef math_geometry_homography_construct
#define math_geometry_homography_construct

 // ::math::linear::homography::construct( )

#include "../vector/vector.hpp"
#include "../matrix/invert.hpp"
#include "../matrix/transform.hpp"
#include "./structure.hpp"


namespace math
 {
  namespace linear
   {
    namespace homography
     {

      template<  typename scalar_name >
       void construct
        (
           ::math::linear::homography::structure<scalar_name,3> & result
          ,::math::linear::vector::structure< scalar_name, 2 >    const& a0, ::math::linear::vector::structure< scalar_name, 2 >    const& b0
          ,::math::linear::vector::structure< scalar_name, 2 >    const& a1, ::math::linear::vector::structure< scalar_name, 2 >    const& b1
          ,::math::linear::vector::structure< scalar_name, 2 >    const& a2, ::math::linear::vector::structure< scalar_name, 2 >    const& b2
          ,::math::linear::vector::structure< scalar_name, 2 >    const& a3, ::math::linear::vector::structure< scalar_name, 2 >    const& b3
        )
        {
         ::math::linear::matrix::structure< scalar_name, 8, 8 > m;

         m[0][0] = a0[0]; m[0][1] = a0[1]; m[0][2] = 1;  m[0][3] =     0; m[0][4] =     0; m[0][5] = 0;  m[0][6] = -a0[0]*b0[0]; m[0][7] = -a0[1]*b0[0];
         m[1][0] =     0; m[1][1] =     0; m[1][2] = 0;  m[1][3] = a0[0]; m[1][4] = a0[1]; m[1][5] = 1;  m[1][6] = -a0[0]*b0[1]; m[1][7] = -a0[1]*b0[1];

         m[2][0] = a1[0]; m[2][1] = a1[1]; m[2][2] = 1;  m[2][3] =     0; m[2][4] =     0; m[2][5] = 0;  m[2][6] = -a1[0]*b1[0]; m[2][7] = -a1[1]*b1[0];
         m[3][0] =     0; m[3][1] =     0; m[3][2] = 0;  m[3][3] = a1[0]; m[3][4] = a1[1]; m[3][5] = 1;  m[3][6] = -a1[0]*b1[1]; m[3][7] = -a1[1]*b1[1];

         m[4][0] = a2[0]; m[4][1] = a2[1]; m[4][2] = 1;  m[4][3] =     0; m[4][4] =     0; m[4][5] = 0;  m[4][6] = -a2[0]*b2[0]; m[4][7] = -a2[1]*b2[0];
         m[5][0] =     0; m[5][1] =     0; m[5][2] = 0;  m[5][3] = a2[0]; m[5][4] = a2[1]; m[5][5] = 1;  m[5][6] = -a2[0]*b2[1]; m[5][7] = -a2[1]*b2[1];

         m[6][0] = a3[0]; m[6][1] = a3[1]; m[6][2] = 1;  m[6][3] =     0; m[6][4] =     0; m[6][5] = 0;  m[6][6] = -a3[0]*b3[0]; m[6][7] = -a3[1]*b3[0];
         m[7][0] =     0; m[7][1] =     0; m[7][2] = 0;  m[7][3] = a3[0]; m[7][4] = a3[1]; m[7][5] = 1;  m[7][6] = -a3[0]*b3[1]; m[7][7] = -a3[1]*b3[1];

         ::math::linear::matrix::structure<scalar_name,8,8> i;
         ::math::linear::matrix::invert( i, m );

         ::math::linear::vector::structure< scalar_name, 8 > coefficient;
         ::math::linear::vector::structure< scalar_name, 8 > free;
         free[0]=  b0[0];
         free[1]=  b0[1];
         free[2]=  b1[0];
         free[3]=  b1[1];
         free[4]=  b2[0];
         free[5]=  b2[1];
         free[6]=  b3[0];
         free[7]=  b3[1];

         ::math::linear::matrix::transform( coefficient, i, free );

         result[0][0] = coefficient[0];
         result[0][1] = coefficient[1];
         result[0][2] = coefficient[2];
         result[1][0] = coefficient[3];
         result[1][1] = coefficient[4];
         result[1][2] = coefficient[5];
         result[2][0] = coefficient[6];
         result[2][1] = coefficient[7];
         result[2][2] = 1;

         return ;
        }

      template<  typename scalar_name >
       void construct
        (
           ::math::linear::homography::structure<scalar_name,3> & result
          ,::math::linear::vector::structure< scalar_name, 2 >    const& b0 //!< ( 0,0 ) -> b0
          ,::math::linear::vector::structure< scalar_name, 2 >    const& b1 //!< ( 1,0 ) -> b1
          ,::math::linear::vector::structure< scalar_name, 2 >    const& b2 //!< ( 0,1 ) -> b2
          ,::math::linear::vector::structure< scalar_name, 2 >    const& b3 //!< ( 1,1 ) -> b3
        )
        {
         ::math::linear::matrix::structure< scalar_name, 8, 8 > m;

         m[0][0] =     0; m[0][1] =     0; m[0][2] = 1;  m[0][3] =     0; m[0][4] =     0; m[0][5] = 0;  m[0][6] = -    0*b0[0]; m[0][7] = -    0*b0[0];
         m[1][0] =     0; m[1][1] =     0; m[1][2] = 0;  m[1][3] =     0; m[1][4] =     0; m[1][5] = 1;  m[1][6] = -    0*b0[1]; m[1][7] = -    0*b0[1];

         m[2][0] =     1; m[2][1] =     0; m[2][2] = 1;  m[2][3] =     0; m[2][4] =     0; m[2][5] = 0;  m[2][6] = -    1*b1[0]; m[2][7] = -    0*b1[0];
         m[3][0] =     0; m[3][1] =     0; m[3][2] = 0;  m[3][3] =     1; m[3][4] =     0; m[3][5] = 1;  m[3][6] = -    1*b1[1]; m[3][7] = -    0*b1[1];

         m[4][0] =     0; m[4][1] =     1; m[4][2] = 1;  m[4][3] =     0; m[4][4] =     0; m[4][5] = 0;  m[4][6] = -    0*b2[0]; m[4][7] = -    1*b2[0];
         m[5][0] =     0; m[5][1] =     0; m[5][2] = 0;  m[5][3] =     0; m[5][4] =     1; m[5][5] = 1;  m[5][6] = -    0*b2[1]; m[5][7] = -    1*b2[1];

         m[6][0] =     1; m[6][1] =     1; m[6][2] = 1;  m[6][3] =     0; m[6][4] =     0; m[6][5] = 0;  m[6][6] = -    1*b3[0]; m[6][7] = -    1*b3[0];
         m[7][0] =     0; m[7][1] =     0; m[7][2] = 0;  m[7][3] =     1; m[7][4] =     1; m[7][5] = 1;  m[7][6] = -    1*b3[1]; m[7][7] = -    1*b3[1];

         ::math::linear::matrix::structure<scalar_name,8,8> i;
         ::math::linear::matrix::invert( i, m );

         ::math::linear::vector::structure< scalar_name, 8 > coefficient;
         ::math::linear::vector::structure< scalar_name, 8 > free;
         free[0]=  b0[0];
         free[1]=  b0[1];
         free[2]=  b1[0];
         free[3]=  b1[1];
         free[4]=  b2[0];
         free[5]=  b2[1];
         free[6]=  b3[0];
         free[7]=  b3[1];

         ::math::linear::matrix::transform( coefficient, i, free );

         result[0][0] = coefficient[0];
         result[0][1] = coefficient[1];
         result[0][2] = coefficient[2];
         result[1][0] = coefficient[3];
         result[1][1] = coefficient[4];
         result[1][2] = coefficient[5];
         result[2][0] = coefficient[6];
         result[2][1] = coefficient[7];
         result[2][2] = 1;

         return ;
        }
      template<  typename scalar_name >
       void construct
        (
           ::math::linear::homography::structure<scalar_name,3> & result
          ,::math::linear::vector::structure< scalar_name, 2 >    const& b3 //!< ( 1,1 ) -> b3
        )
        {
         ::math::linear::matrix::structure< scalar_name, 8, 8 > m;

         m[0][0] =     0; m[0][1] =     0; m[0][2] = 1;  m[0][3] =     0; m[0][4] =     0; m[0][5] = 0;  m[0][6] = -    0*0; m[0][7] = -    0*0;
         m[1][0] =     0; m[1][1] =     0; m[1][2] = 0;  m[1][3] =     0; m[1][4] =     0; m[1][5] = 1;  m[1][6] = -    0*0; m[1][7] = -    0*0;

         m[2][0] =     1; m[2][1] =     0; m[2][2] = 1;  m[2][3] =     0; m[2][4] =     0; m[2][5] = 0;  m[2][6] = -    1*1; m[2][7] = -    0*1;
         m[3][0] =     0; m[3][1] =     0; m[3][2] = 0;  m[3][3] =     1; m[3][4] =     0; m[3][5] = 1;  m[3][6] = -    1*0; m[3][7] = -    0*0;

         m[4][0] =     0; m[4][1] =     1; m[4][2] = 1;  m[4][3] =     0; m[4][4] =     0; m[4][5] = 0;  m[4][6] = -    0*0; m[4][7] = -    1*0;
         m[5][0] =     0; m[5][1] =     0; m[5][2] = 0;  m[5][3] =     0; m[5][4] =     1; m[5][5] = 1;  m[5][6] = -    0*1; m[5][7] = -    1*1;

         m[6][0] =     1; m[6][1] =     1; m[6][2] = 1;  m[6][3] =     0; m[6][4] =     0; m[6][5] = 0;  m[6][6] = -    1*b3[0]; m[6][7] = -    1*b3[0];
         m[7][0] =     0; m[7][1] =     0; m[7][2] = 0;  m[7][3] =     1; m[7][4] =     1; m[7][5] = 1;  m[7][6] = -    1*b3[1]; m[7][7] = -    1*b3[1];

         ::math::linear::matrix::structure<scalar_name,8,8> i;
         ::math::linear::matrix::invert( i, m );

         ::math::linear::vector::structure< scalar_name, 8 > coefficient;
         ::math::linear::vector::structure< scalar_name, 8 > free;
         free[0]=  0;
         free[1]=  0;
         free[2]=  1;
         free[3]=  0;
         free[4]=  0;
         free[5]=  1;
         free[6]=  b3[0];
         free[7]=  b3[1];

         ::math::linear::matrix::transform( coefficient, i, free );

         result[0][0] = coefficient[0];
         result[0][1] = coefficient[1];
         result[0][2] = coefficient[2];
         result[1][0] = coefficient[3];
         result[1][1] = coefficient[4];
         result[1][2] = coefficient[5];
         result[2][0] = coefficient[6];
         result[2][1] = coefficient[7];
         result[2][2] = 1;

         return ;
        }

     }
   }
 }

#endif
