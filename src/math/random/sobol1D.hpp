#ifndef _DDMRM_math_random_sobol1d_HPP_
 #define _DDMRM_math_random_sobol1d_HPP_

#include <cstdint>

 namespace math
  {
   namespace random
    {

       class Sobol1D
        {
         public:
           typedef std::uint32_t    size_type;
           typedef double         scalar_type;

         public:
           Sobol1D()
            {
             seed( 0 );
            }

           Sobol1D( size_type const& seedX )
            {
             seed( seedX );
            }

           void seed( size_type const& s0 )
            {
             d0 = s0;
             M2_index  = 0;
            }

           size_type position()
            {
             return M2_index;
            }

           scalar_type next()
            {
             size_type Is_max = 0xFFFFFF;
             scalar_type Ir_value = ( d0 >> 8) * ( 1.0/ Is_max );
             updateState();
             return Ir_value;
           }

         private:
         // state data
          size_type M2_index, d0;

          void updateState()
           {
             // = Integer.numberOfTrailingZeros(~M2_index);
             size_type c = 0;
             {
              uint32_t num = M2_index;
              while( 1 == ( num & 1 ) )
              {
               c++;
               num >>= 1;
              }
           }

           d0 ^= ( 0x80000000 ) >> c;
           ++M2_index;
          }

         public:

       };

    }
  }

#endif