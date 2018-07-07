#ifndef math_type_affine_NaN
 #define math_type_affine_NaN

 // ::math::linear::affine::NaN<scalar_name,width_number,height_number>

#include <limits>

#include "./structure.hpp"
#include "../matrix/NaN.hpp"
#include "../vector/set.hpp"

 namespace math
  {
   namespace linear
    {
     namespace affine
      {

       template< typename scalar_name, unsigned dimension_number>
        void NaN( ::math::linear::affine::structure<scalar_name,dimension_number> & a )
         {
          ::math::linear::matrix::NaN( a.matrix() );
          ::math::linear::vector::set<scalar_name>( a.vector(), std::numeric_limits<scalar_name>::quiet_NaN() );
         }

      }
    }
  }

#endif
