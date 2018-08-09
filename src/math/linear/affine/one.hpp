#ifndef Dh_math_linear_affine_one
 #define Dh_math_linear_affine_one

 // ::math::linear::affine::one<scalar_name,width_number,height_number>

#include "./structure.hpp"
#include "../matrix/one.hpp"
#include "../vector/set.hpp"


 namespace math
  {
   namespace linear
    {
     namespace affine
      {

       template< typename scalar_name, unsigned dimension_number>
        void one( ::math::linear::affine::structure<scalar_name,dimension_number> & a )
         {
          ::math::linear::matrix::one( a.matrix() );
          ::math::linear::vector::set<scalar_name>( a.vector(), 0 );
         }

      }
    }
  }

#endif
