#ifndef math_library_linear_algebra__vector_aritmetic_fill_HPP_
 #define math_library_linear_algebra__vector_aritmetic_fill_HPP_

 // ::math::linear::vector::fill( value )
 // ::math::linear::vector::fill( result, value )



#include "./structure.hpp"







 namespace math
  {
   namespace linear
    {
     namespace vector
      {

       template< typename scalar_name, unsigned dimension_number, typename value_name >
        inline
        ::math::linear::vector::structure< scalar_name, dimension_number > &
        fill
         (
           ::math::linear::vector::structure< scalar_name, dimension_number >      & result_param
          ,                              value_name                           const& value_param
         )
         {
          scalar_name      * I_result = result_param.data() + dimension_number;

          while( I_result != result_param.data() )
           {
            --I_result;
             *I_result = scalar_name( value_param );
           }
          return result_param;
         }

       template< typename scalar_name, unsigned dimension_number, typename value_name >
        inline
        ::math::linear::vector::structure< scalar_name, dimension_number >
        fill
         (
                            value_name                           const& value_param
         )
         {
          ::math::linear::vector::structure< scalar_name, dimension_number >    result_param;
          scalar_name      * I_result = result_param.data() + dimension_number;

          while( I_result != result_param.data() )
           {
            --I_result;
             *I_result = scalar_name( value_param );
           }
          return result_param;
         }


       template< typename scalar_name, typename value_name >
        inline
        ::math::linear::vector::structure< scalar_name, 2 > &
        fill
         (
           ::math::linear::vector::structure< scalar_name, 2 >       & result_param
          ,            value_name                  const& value_param
         )
         {
          result_param[0] = value_param;
          result_param[1] = value_param;
          return result_param;
         }

       template< typename scalar_name, typename value_name >
        inline
        ::math::linear::vector::structure< scalar_name, 3 > &
        fill
         (
           ::math::linear::vector::structure< scalar_name, 3 >       & result_param
          ,            value_name                  const& value_param
         )
         {
          result_param[0] = value_param;
          result_param[1] = value_param;
          result_param[2] = value_param;
          return result_param;
         }

       template< typename scalar_name, typename value_name >
        inline
        ::math::linear::vector::structure< scalar_name, 3 >
        fill
         (
                       value_name                  const& value_param
         )
         {
           ::math::linear::vector::structure< scalar_name, 3 >      result_param;
          result_param[0] = value_param;
          result_param[1] = value_param;
          result_param[2] = value_param;
          return result_param;
         }


       template< typename scalar_name, typename value_name >
        inline
        ::math::linear::vector::structure< scalar_name, 4 > &
        fill
         (
           ::math::linear::vector::structure< scalar_name, 4 >       & result_param
          ,             value_name                 const& value_param
         )
         {
          result_param[0] = value_param;
          result_param[1] = value_param;
          result_param[2] = value_param;
          result_param[3] = value_param;
          return result_param;
         }

     }
   }
 }

#endif