#ifndef math_type_affine_invert
 #define math_type_affine_invert

 // ::math::linear::affine::invert<scalar_name,dimension_number>

#include "./structure.hpp"
#include "../matrix/invert.hpp"
#include "../matrix/transform.hpp"
#include "../vector/negate.hpp"

 namespace math
  {
   namespace linear
    {
     namespace affine
      {

       template< typename scalar_name, unsigned dimension_number >
        void invert
         (
           ::math::linear::affine::structure<scalar_name,dimension_number>      & result
          ,::math::linear::affine::structure<scalar_name,dimension_number> const& right
          ,scalar_name const& epsilon  = 1e-6
         )
         {
          ::math::linear::matrix::invert( result.matrix(), right.matrix() );
          ::math::linear::matrix::transform( result.vector(), result.matrix(), right.vector() );
          ::math::linear::vector::negate( result.vector() );
         }

      }
    }
  }

#endif