#ifndef _math_polynomial_normaliza_HPP_
 #define _math_polynomial_normaliza_HPP_

// math::polynomial::normalize( coefficient, size, epsilon = 1e-6 )
// math::polynomial::normalize( coefficient, size, epsilon = 1e-6 )

#include <vector>

#include "./structure.hpp"

 namespace math
   {
    namespace polynomial
     {

      template< typename scalar_name >
       inline
       bool normalize( scalar_name* coefficient, std::size_t const& size, scalar_name const& epsilon = 1e-6 )
        {
         std::size_t  index;
         scalar_name  I_max= coefficient[0];

         for( index=0; index < size; index++ )
          {
           if( I_max < fabs( coefficient[index] ) )
            {
             I_max = coefficient[index];
            }
          }

         if( ( - epsilon < I_max ) && ( I_max < epsilon ) )
          {
           return false;
          }

         for( index=0; index < size; index++ )
          {
           coefficient[index] /= I_max;
          }

         return false;
        }

      template< typename scalar_name >
       inline
       bool normalize( ::math::polynomial::structure::dynamic< scalar_name > const&coefficient, scalar_name const& epsilon = 1e-6 )
        {
         return math::polynomial::normalize( coefficient.data(), coefficient.size(), epsilon );
        }

    }
  }
#endif
