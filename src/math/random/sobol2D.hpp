#ifndef _DDMRM_math_random_sobol2d_HPP_
 #define _DDMRM_math_random_sobol2d_HPP_

 namespace GS_DDMRM
  {
   namespace S_math
    {
     namespace S_random
      {
       class GC_sobol2D
        {
        public:
            typedef std::uint32_t T_uint32;
            typedef double T_scalar;

        public:
           T_uint32 getPos() { return M2_index; }

           GC_sobol2D();
           GC_sobol2D( T_uint32 seedX, T_uint32 seedY );

           void seed( T_uint32 s0, T_uint32 s1 );
           void next( T_scalar &x, T_scalar &y );

        private:
          // state data
          T_uint32 M2_index, d0, d1;

          // direction table
          static std::array< T_uint32, 33 > M2s_cache;

          static void Fs_init();

          void updateState();
        };

      }
    }
  }

#endif
