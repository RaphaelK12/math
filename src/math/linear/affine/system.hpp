#ifndef Dh_math_linear_affine_system
 #define Dh_math_linear_affine_system

// ::math::linear::affine::system<scalar_name,width_number,height_number>

// Extract base vectors from affine transformation

#include "./structure.hpp"
#include "../vector/structure.hpp"

#include "../matrix/structure.hpp"
#include "../matrix/system.hpp"


 namespace math
  {
   namespace linear
    {
     namespace affine
      {

       template< typename scalar_name >
        void system
         (
           ::math::linear::affine::structure<scalar_name, 1>                & affine
          ,::math::linear::vector::structure<scalar_name, 1>           const& vector
          ,::math::linear::vector::structure<scalar_name, 1>           const& x
         )
         {
          ::math::linear::matrix::system( affine.matrix(), x );
          affine.vector() = vector;
         }

       template< typename scalar_name >
        void system
         (
           ::math::linear::affine::structure<scalar_name, 2>                & affine
          ,::math::linear::vector::structure<scalar_name, 2>           const& vector
          ,::math::linear::vector::structure<scalar_name, 2>           const& x
          ,::math::linear::vector::structure<scalar_name, 2>           const& y
         )
         {
          ::math::linear::matrix::system( affine.matrix(), x, y );
          affine.vector() = vector;
         }

       template< typename scalar_name >
        void system
         (
           ::math::linear::affine::structure<scalar_name, 3>                 & affine
          ,::math::linear::vector::structure<scalar_name, 3>            const& vector
          ,::math::linear::vector::structure<scalar_name, 3>            const& x
          ,::math::linear::vector::structure<scalar_name, 3>            const& y
          ,::math::linear::vector::structure<scalar_name, 3>            const& z
         )
         {
          ::math::linear::matrix::system( affine.matrix(), x, y, z );
          affine.vector() = vector;
         }

       template< typename scalar_name >
        void system
         (
           ::math::linear::affine::structure<scalar_name, 4>                 & affine
          ,::math::linear::vector::structure<scalar_name, 4>            const& vector
          ,::math::linear::vector::structure<scalar_name, 4>            const& x
          ,::math::linear::vector::structure<scalar_name, 4>            const& y
          ,::math::linear::vector::structure<scalar_name, 4>            const& z
          ,::math::linear::vector::structure<scalar_name, 4>            const& t
         )
         {
          ::math::linear::matrix::system( affine.matrix(), x, y, z, t );
          affine.vector() = vector;
         }

      }
    }
  }

#endif
