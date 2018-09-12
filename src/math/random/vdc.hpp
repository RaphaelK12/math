#ifndef _DDMRM_math_random_VanDerCorput_HPP_
 #define _DDMRM_math_random_VanDerCorput_HPP_

 // ::math::random::VanDerCorput( index, base )
 // ::math::random::VanDerCorput( index ); base = 2;

 namespace math
  {
   namespace random
    {

     template< typename scalar_name, typename size_name = unsigned >
      inline scalar_name VanDerCorput( size_name index, size_name const& base )
       {
        scalar_name Ir_vdc = 0, I_denom = 1;
        while( index )
         {
          Ir_vdc += ( index % base) / ( I_denom *= base );
          index /= base; // note: conversion from 'double' to 'int'
         }
        return Ir_vdc;
       }

     template< typename scalar_name, typename size_name >
      inline scalar_name VanDerCorput( size_name index )
       {
        scalar_name Ir_vdc = 0, I_denom = 1;
        while( index )
         {
          Ir_vdc += ( index % 2 ) / ( I_denom *= 2 );
          index /= 2;
         }
        return Ir_vdc;
       }

    }
  }

#endif
