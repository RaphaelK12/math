#ifndef Dh_DDMRM_math_polynomial_optimize_HPP_
 #define Dh_DDMRM_math_polynomial_optimize_HPP_
 
 #include "simple.hpp"

 namespace S_DDMRM
  {
   namespace S_math
    {
     namespace S_polynomial
      {
        template< typename N_value >
         inline      
         bool 
         GF_optimize
          (
            GC_simple<N_value>     * P_simple
           ,N_value           const& P_epsilon = N_value( 0 )
         )
         {
          typedef           GC_simple<N_value>  Tf_simple;
                 
                   typename Tf_simple::T_size  I_index;       
                 
          for( I_index=0; I_index <= P_simple->F_degree(); I_index++ )       
           {
            if( fabs( (*P_simple)[I_index] ) < P_epsilon )        
             (*P_simple)[I_index] = N_value(0);
           }        
                 
          return true;                
         }
   
      }
    }
  }

#endif
