#ifndef _DDMRM_math_random_VanDerCorput_HPP_
 #define _DDMRM_math_random_VanDerCorput_HPP_

 // ::math::random::VanDerCorput<scalar_name>( index, base )
 // ::math::random::VanDerCorput<scalar_name>( index ); base = 2;
 // ::math::random::vdc<scalar_name, size_name = unsigned, size_name base_size = 2>{}

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

     template< typename scalar_name, typename size_name, size_name base_size = 2 >
      inline scalar_name VanDerCorput( size_name index )
       {
        scalar_name Ir_vdc = 0, I_denom = 1;
        while( index )
         {
          Ir_vdc += ( index % base_size ) / ( I_denom *= base_size );
          index /= base_size;
         }
        return Ir_vdc;
       }

     template< typename scalar_name, typename size_name = unsigned, size_name base_size = 2 >
      class vdc
       {
        public:
          typedef scalar_name scalar_type;
          typedef size_name   size_type;

        public:
          vdc():M_index(0){}

        public:
          scalar_type next()
           {
            return ::math::random::VanDerCorput<scalar_type,size_type, base_size>( M_index++ );
           }

         scalar_type operator()(){ return this->next(); }
       private:
         size_type M_index;
       };


    }
  }

#endif
