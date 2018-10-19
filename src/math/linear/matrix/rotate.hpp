#ifndef math_linear_matrix_rotate
 #define math_linear_matrix_rotate

// math::linear::matrix::rotate

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
          rotate
           (
             ::math::linear::matrix::structure<scalar_name,2,2>      & rotate
            ,scalar_name                                        const& P_angle
           )
           {
            rotate[0 ][ 0 ] = cos( P_angle ); rotate[ 0 ][ 1 ] = -sin( P_angle );
            rotate[1 ][ 0 ] = sin( P_angle ); rotate[ 1 ][ 1 ] =  cos( P_angle );
           }

         template< typename scalar_name>
          inline
          bool
          rotate
           (
             ::math::linear::matrix::structure<scalar_name, 3, 3 >          &   rotate
            ,::math::linear::vector::structure< scalar_name, 3 >       const& direction
            ,                                   scalar_name            const& angle
           )
           {
            scalar_name ca, sa, jmca, vx2, vy2, vz2, vxvy, vxvz, vyvz;

            vx2 = direction[0] * direction[0];
            vy2 = direction[1] * direction[1];
            vz2 = direction[2] * direction[2];

            scalar_name I_len = std::sqrt( vx2 + vy2 + vz2 );
            if( scalar_name(0) == I_len  )  
             {
              return false;
             }

            ::math::linear::vector::structure< scalar_name, 3 > I_dir( direction );
            ::math::linear::vector::scale( I_dir,  scalar_name(1)/I_len );

            ca = cos ( angle );
            sa = sin ( angle );
            jmca = 1 - ca;

            vxvy = I_dir[0] * I_dir[1];
            vxvz = I_dir[0] * I_dir[2];
            vyvz = I_dir[1] * I_dir[2];

            rotate[ 0 ][ 0 ] = vx2  + ( 1   -  vx2 ) * ca;
            rotate[ 0 ][ 1 ] = vxvy * jmca  -  I_dir[2] * sa;
            rotate[ 0 ][ 2 ] = vxvz * jmca  +  I_dir[1] * sa;
            rotate[ 1 ][ 0 ] = vxvy * jmca  +  I_dir[2] * sa;
            rotate[ 1 ][ 1 ] = vy2  +  ( 1  -  vy2 ) * ca;
            rotate[ 1 ][ 2 ] = vyvz * jmca  -  I_dir[0] * sa;
            rotate[ 2 ][ 0 ] = vxvz * jmca  -  I_dir[1] * sa;
            rotate[ 2 ][ 1 ] = vyvz * jmca  +  I_dir[0] * sa;
            rotate[ 2 ][ 2 ] = vz2  +  ( 1  -  vz2 ) * ca;

            return  true;
           }

     }
   }
 }

#endif