#ifndef math_function_clamper
#define math_function_clamper

 // ::math::function::ramp
 // ::math::function::saw
 // ::math::function::wave
 // ::math::function::to_one

namespace math
 {
  namespace function
   {

     template< typename scalar_name >      //_____/-----
      inline
      scalar_name
      ramp
       (
         scalar_name const& value
        ,scalar_name const& lower = scalar_name( 0 )
        ,scalar_name const& higher = scalar_name( 1 )
       )
       {
        return ( (value) < lower ? lower : ( higher < (value) ? higher : (value) ) ) ;
       }


     template< typename scalar_name  >   // ////
      inline
      scalar_name
      saw
       (
        scalar_name  const& value,
        scalar_name  const& lower  = scalar_name ( 0 ),
        scalar_name  const& higher = scalar_name ( 1 )
       )
       {
        return ( lower < value? (         scalar_name(  ::fmod( value - lower,  higher - lower ) ) + lower ):
                               (  higher - scalar_name( ::fmod( lower  - value, higher - lower ) )        )  );
       }

     template< typename scalar_name  >   // /\/\/\/\/
      inline
      scalar_name
      wave
       (
         scalar_name  const& value
        ,scalar_name  const& lower     = scalar_name ( 0 )
        ,scalar_name  const& higher    = scalar_name ( 1 )
       )
       {
        scalar_name  Ir_result;
        scalar_name  I_size =  higher - lower;

        if( lower < value )
         {
          Ir_result = scalar_name( ::fmod( value - lower,  2 * I_size ) );
         }
        else
         {
          Ir_result = scalar_name(  ::fmod( lower - value, 2 * I_size ) );
         }

        if( I_size < Ir_result )
         Ir_result =  - Ir_result + 2 * I_size;

        Ir_result += lower;
        return Ir_result;
       }

     template< typename scalar_name >
      inline
      scalar_name
      to_one
       (
         scalar_name  const& value                //!< what  goes to [0,1]
        ,scalar_name  const& P_left               //!< left  side of interval
        ,scalar_name  const& P_right              //!< right side of interval
       )
       {
        return ( value - P_left ) / ( P_right - P_left );
       }

   }
 }

#endif
