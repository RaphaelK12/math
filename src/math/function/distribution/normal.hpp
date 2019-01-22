#ifndef math_function_distribution_normal
#define math_function_distribution_normal

// ::math::function::distribution::normal
// ::math::function::distribution::normal_invert
// ::math::function::distribution::normal_PDF

#include <array>
#include "../../constants.hpp"


namespace math
 {
  namespace function
   {
    namespace distribution
     {

      template< typename scalar_name >
       inline scalar_name normal
        (
          scalar_name const& x
         ,scalar_name const& standard_deviation_param
         ,scalar_name const& mean_param  = scalar_name(0)
         )
        {
         scalar_name const & inv2sqrtPHI = math::constants::PHI_invSQRT2;

         scalar_name e  =  (x - mean_param)/standard_deviation_param;
                     e *= e;

         scalar_name e_coef  = standard_deviation_param * inv2sqrtPHI;

         scalar_name result    = exp( - e / scalar_name(2) ) / e_coef;

         return result;
        }

      template< typename scalar_name >
       inline scalar_name normal
        (
          scalar_name const& x
         )
        {
         scalar_name const & inv2sqrtPHI = math::constants::PHI_invSQRT2;

         scalar_name result = exp( - (x*x) / scalar_name(2) ) / inv2sqrtPHI;

         return result;
        }


      template< typename scalar_name >
       inline scalar_name normal_invert
        (
          scalar_name const& y
         ,scalar_name const& standard_deviation_param
         ,scalar_name const& mean_param = scalar_name(0)
         )
        {
         scalar_name const & inv2sqrtPHI = math::constants::PHI_invSQRT2;

         scalar_name x;
         x = y * standard_deviation_param * inv2sqrtPHI;
         x = - log( x ) * 2 * standard_deviation_param * standard_deviation_param;
         x = sqrt( x ) + mean_param;

         return x;
        }

      template< typename scalar_name >
       inline scalar_name normal_cumulative
        (
          scalar_name   x
         ,scalar_name const& standard_deviation_param = scalar_name(1)
         )
        { // TODO: This is wrong
         scalar_name const b0 =  0.2316419;
         scalar_name const b1 =  0.319381530;
         scalar_name const b2 = -0.356563782;
         scalar_name const b3 =  1.781477937;
         scalar_name const b4 = -1.821255978;
         scalar_name const b5 =  1.330274429;

         bool sign = true;
         if( x < 0 )
          {
           sign = false;
           x = -x;
          }

         scalar_name t = scalar_name(1)/( 1 + b0 * x );

         scalar_name poly = t*( b1 + t*( b2 + t*( b3 + t*( b4 + t*b5)))); 

         scalar_name phi = ::math::function::distribution::normal<scalar_name>(x,standard_deviation_param);

         scalar_name up   = 1;
         scalar_name down = -(2*3.141592653589 - 1);

         scalar_name result = ( sign ? (1 - phi * poly): ( phi * poly + down ) );

         result  =  (result - down)/( up - down );
         return result;
        }

     }
   }
 }

#endif
