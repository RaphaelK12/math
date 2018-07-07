#ifndef math_type_affine_init
 #define math_type_affine_init

 // ::math::linear::affine::init<scalar_name,width_number,height_number>

#include "./structure.hpp"
#include "../matrix/set.hpp"


 namespace math
  {
   namespace linear
    {
     namespace affine
      {

       template< typename scalar_name >
        void init
         (
           ::math::linear::affine::structure<scalar_name,2>      & affine
          ,::math::linear::vector::structure<scalar_name, 3>           const& vector
          ,::math::linear::vector::structure<scalar_name, 3>           const& x
          ,::math::linear::vector::structure<scalar_name, 3>           const& y
         )
         {
          ::math::linear::matrix::set( affine.matrix(), x, y );
          affine.vector() = vector;
         }

       template< typename scalar_name >
        void init
         (
           ::math::linear::affine::structure<scalar_name,3>       & affine
          ,::math::linear::vector::structure<scalar_name, 3>            const& vector
          ,::math::linear::vector::structure<scalar_name, 3>            const& x
          ,::math::linear::vector::structure<scalar_name, 3>            const& y
          ,::math::linear::vector::structure<scalar_name, 3>            const& z
         )
         {
          ::math::linear::matrix::set( affine.matrix(), x, y, z );
          affine.vector() = vector;
         }

       template< typename scalar_name >
        void init
         (
           ::math::linear::affine::structure<scalar_name,4>       & affine
          ,::math::linear::vector::structure<scalar_name, 4>            const& vector
          ,::math::linear::vector::structure<scalar_name, 4>            const& x
          ,::math::linear::vector::structure<scalar_name, 4>            const& y
          ,::math::linear::vector::structure<scalar_name, 4>            const& z
          ,::math::linear::vector::structure<scalar_name, 4>            const& t
         )
         {
          ::math::linear::matrix::set( affine.matrix(), x, y, z, t );

          affine.vector() = vector;
         }


      }
    }
  }

#endif
