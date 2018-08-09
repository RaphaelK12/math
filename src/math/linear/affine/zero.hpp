#ifndef Dh_math_linear_affine_zero
 #define Dh_math_linear_affine_zero

 // ::math::linear::affine::zero<scalar_name,width_number,height_number>

#include "./structure.hpp"
#include "../matrix/zero.hpp"
#include "../vector/set.hpp"


 namespace math
  {
   namespace linear
    {
     namespace affine
      {

       template< typename scalar_name, unsigned dimension_number>
        void zero( ::math::linear::affine::structure<scalar_name,dimension_number> & a )
         {
          ::math::linear::matrix::zero( a.matrix() );
          ::math::linear::vector::set<scalar_name>( a.vector(), 0 );
         }

      }
    }
  }

#endif
