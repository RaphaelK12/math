#ifndef math_library_linear_algebra__vector_aritmetic_make_HPP_
 #define math_library_linear_algebra__vector_aritmetic_make_HPP_

 // ::math::linear::vector::make( result, left, right )
 // ::math::linear::vector::make( result, left, right )
 // ::math::linear::vector::make( result, left, right )



#include "./structure.hpp"





 namespace math
  {
   namespace linear
    {
     namespace vector
      {

       template< typename scalar_name, unsigned dimension_number, typename value_name >
        inline
        ::math::linear::vector::structure< scalar_name, dimension_number >
        make
         (
           value_name                          const& left_param
         )
         {
          ::math::linear::vector::structure< scalar_name, dimension_number >       result;

          scalar_name      * I_result = result.data()+ dimension_number;

          while( I_result != result.data() )
           {
            --I_result;
             *I_result = scalar_name( left_param );
           }
          return result;
         }

       template< typename scalar_name, typename value_name >
        inline
        ::math::linear::vector::structure< scalar_name, 2 >
        make
         (
            value_name const& x
          , value_name const& y
         )
         {
          ::math::linear::vector::structure< scalar_name, 2 >       result;
          result[0] = x;
          result[1] = y;
          return result;
         }

       template< typename scalar_name, typename value_name >
        inline
        ::math::linear::vector::structure< scalar_name, 3 >
        make
         (
            value_name   const& x
          , value_name   const& y
          , value_name   const& z
         )
         {
          ::math::linear::vector::structure< scalar_name, 3 >       result;
          result[0] = x;
          result[1] = y;
          result[2] = z;
          return result;
         }

       template< typename scalar_name, typename value_name >
        inline
        ::math::linear::vector::structure< scalar_name, 2 >
        make
         (
           ::math::linear::vector::structure< scalar_name, 2 >      & result_param
          ,              value_name                 const& right_param
         )
         {
          result_param[0] = right_param;
          result_param[1] = right_param;
          return result_param;
         }

       template< typename scalar_name, typename value_name >
        inline
        ::math::linear::vector::structure< scalar_name, 3 >
        make
         (
           ::math::linear::vector::structure< scalar_name, 3 >      & result_param
          ,              value_name                 const& right_param
         )
         {
          result_param[0] = right_param;
          result_param[1] = right_param;
          result_param[2] = right_param;
          return result_param;
         }

       template< typename scalar_name, typename value_name >
        inline
        ::math::linear::vector::structure< scalar_name, 4 >
        make
         (
           ::math::linear::vector::structure< scalar_name, 4 >      & result_param
          ,                value_name               const& right_param
         )
         {
          result_param[0] = right_param;
          result_param[1] = right_param;
          result_param[2] = right_param;
          result_param[3] = right_param;
          return result_param;
         }

     }
   }
 }

#endif