#ifndef math_function_peano2D
#define math_function_peano2D

#include <array>

 // ::math::function::pdf

namespace math
 {
  namespace function
   {

    template< typename scalar_name >
     inline scalar_name pdf( scalar_name const& x, scalar_name const& variance, scalar_name const& mean )
      {
       return exp(-(x-mean)*(x-mean)/( 2* variance) )/sqrt( 2* 3.1415926 * variance );
      }

    template< typename scalar_name >
     inline scalar_name pdf( scalar_name const& x, scalar_name const& variance )
      {
       return exp(-x*x/( 2* variance) )/sqrt( 2* 3.1415926 * variance );
      }


   }
 }

#endif



