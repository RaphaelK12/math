#ifndef math_function_pdf
#define math_function_pdf

#include <array>

 // ::math::function::pdf

namespace math
 {
  namespace function
   {

    template< typename scalar_name >
     inline scalar_name pdf( scalar_name const& x, scalar_name const& variance, scalar_name const& mean )
      { // Probability density function
       return exp(-(x-mean)*(x-mean)/( 2* variance) )/sqrt( 2* 3.1415926 * variance );
      }

    template< typename scalar_name >
     inline scalar_name pdf( scalar_name const& x, scalar_name const& variance )
      { // Probability density function
       return exp(-x*x/( 2* variance) )/sqrt( 2* 3.1415926 * variance );
      }


   }
 }

#endif



