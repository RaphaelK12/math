#ifndef math_linear_vector_init_HPP_
 #define math_linear_vector_init_HPP_

 // ::math::linear::vector::init( result, 0 )
 // ::math::linear::vector::init( result, 0, 1 )
 // ::math::linear::vector::init( result, 0, 1, 2 )
 // ::math::linear::vector::init( result, 0, 1, 2, 3 )



#include "./structure.hpp"




 namespace math
  {
   namespace linear
    {
     namespace vector
      {

       template< typename scalar_name, typename value_name >
        inline
          ::math::linear::vector::structure< scalar_name, 2 > &
        init
         (
            ::math::linear::vector::structure< scalar_name, 2 > & result
          , value_name const& x
          , value_name const& y
         )
         {
          result[0] = x;
          result[1] = y;
          return result;
         }

       template< typename scalar_name, typename value_name >
        inline
        ::math::linear::vector::structure< scalar_name, 3 > &
        init
         (
            ::math::linear::vector::structure< scalar_name, 3 > & result
          , value_name   const& x
          , value_name   const& y
          , value_name   const& z
         )
         {
          result[0] = x;
          result[1] = y;
          result[2] = z;
          return result;
         }


       template< typename scalar_name, typename value_name >
        inline
        ::math::linear::vector::structure< scalar_name, 4 > &
        init
         (
            ::math::linear::vector::structure< scalar_name, 4 > & result
          , value_name   const& x
          , value_name   const& y
          , value_name   const& z
          , value_name   const& t
         )
         {
          result[0] = x;
          result[1] = y;
          result[2] = z;
          result[3] = t;
          return result;
         }



     }
   }
 }

#endif