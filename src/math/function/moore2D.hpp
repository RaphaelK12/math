#ifndef math_function_moore2D
#define math_function_moore2D

#include <array>

 // ::math::function::moore2D

namespace math
 {
  namespace function
   {

    template< typename scalar_name >
     inline void moore2D( scalar_name & x, scalar_name &y, scalar_name P_value, int iterations = 16 )
      {

      }

    template < typename scalar_name, typename size_name=int >
     void moore2D( std::array<scalar_name, 2 > & coord, scalar_name const& value, size_name iterations = 16 )
      {
       ::math::function::moore2D( coord[0], coord[1], value, iterations );
      }

   }
 }

#endif



