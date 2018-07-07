#ifndef math_linear_matrix_rotate
 #define math_linear_matrix_rotate

#include "../vector/structure.hpp"
#include "./structure.hpp"


 namespace math
  {
   namespace linear
    {
     namespace matrix
      {

         template< typename scalar_name>
          inline
          void
          GF_rotate
           (
             ::math::linear::matrix::structure<scalar_name,2,2>      & P_rotate
            ,scalar_name                               const& P_angle
           )
           {
            P_rotate[0 ][ 0 ] = cos( P_angle ); P_rotate[ 0 ][ 1 ] = -sin( P_angle );
            P_rotate[1 ][ 0 ] = sin( P_angle ); P_rotate[ 1 ][ 1 ] =  cos( P_angle );
           }

         template< typename scalar_name>
          inline
          bool
          GF_rotate
           (
             ::math::linear::matrix::structure<scalar_name, 3, 3 >          & P_rotate
            ,::math::linear::vector::structure< scalar_name, 3 >       const& P_direction
            ,                                   scalar_name            const& P_angle
           )
           {
            scalar_name ca, sa, jmca, vx2, vy2, vz2, vxvy, vxvz, vyvz;

            vx2 = P_direction[0] * P_direction[0];
            vy2 = P_direction[1] * P_direction[1];
            vz2 = P_direction[2] * P_direction[2];

            scalar_name I_len = std::sqrt( vx2 + vy2 + vz2 );
            if( scalar_name(0) == I_len )  return false;
            ::math::linear::vector::structure< scalar_name, 3 > I_dir( P_direction );

            I_dir /= I_len;

            ca = cos ( P_angle );
            sa = sin ( P_angle );
            jmca = 1 - ca;

            vxvy = P_direction[0] * P_direction[1];
            vxvz = P_direction[0] * P_direction[2];
            vyvz = P_direction[1] * P_direction[2];

            P_rotate[ 0 ][ 0 ] = vx2  + ( 1   -  vx2 ) * ca;
            P_rotate[ 0 ][ 1 ] = vxvy * jmca  -  P_direction[2] * sa;
            P_rotate[ 0 ][ 2 ] = vxvz * jmca  +  P_direction[1] * sa;
            P_rotate[ 1 ][ 0 ] = vxvy * jmca  +  P_direction[2] * sa;
            P_rotate[ 1 ][ 1 ] = vy2  +  ( 1  -  vy2 ) * ca;
            P_rotate[ 1 ][ 2 ] = vyvz * jmca  -  P_direction[0] * sa;
            P_rotate[ 2 ][ 0 ] = vxvz * jmca  -  P_direction[1] * sa;
            P_rotate[ 2 ][ 1 ] = vyvz * jmca  +  P_direction[0] * sa;
            P_rotate[ 2 ][ 2 ] = vz2  +  ( 1  -  vz2 ) * ca;

            return  true;
           }

     }
   }
 }

#endif