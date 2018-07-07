#ifndef math_library_linear_algebra__vector_aritmetic_set_HPP_
 #define math_library_linear_algebra__vector_aritmetic_set_HPP_

 // ::math::linear::vector::set( result, value )



#include "./structure.hpp"





 namespace math
  {
   namespace linear
    {
     namespace vector
      {

       template< typename scalar_name, unsigned dimension_number, typename value_name >
        inline
        void
        set
         (
           ::math::linear::vector::structure< scalar_name, dimension_number >      & result_param
          ,                 value_name                           const& value_param
         )
         {
          scalar_name      * I_result = result_param.data()+ dimension_number;

          while( I_result != result_param.data() )
           {
            --I_result;
             *I_result = scalar_name( value_param );
           }
         }

       template< typename scalar_name, typename value_name >
        inline
        void
        set
         (
           ::math::linear::vector::structure< scalar_name, 2 >       & result_param
          ,            value_name                  const& value_param
         )
         {
          result_param[0] = value_param;
          result_param[1] = value_param;
         }

       template< typename scalar_name, typename value_name >
        inline
        void
        set
         (
           ::math::linear::vector::structure< scalar_name, 2 >       & result_param
          ,            value_name                  const& x_param
          ,            value_name                  const& y_param
         )
         {
          result_param[0] = x_param;
          result_param[1] = y_param;
         }

       template< typename scalar_name, typename value_name >
        inline
        void
        set
         (
           ::math::linear::vector::structure< scalar_name, 3 >       & result_param
          ,            value_name                  const& value_param
         )
         {
          result_param[0] = value_param;
          result_param[1] = value_param;
          result_param[2] = value_param;
         }

       template< typename scalar_name, typename value_name >
        inline
        void
        set
         (
           ::math::linear::vector::structure< scalar_name, 3 >       & result_param
          ,            value_name                  const& x_param
          ,            value_name                  const& y_param
          ,            value_name                  const& z_param
         )
         {
          result_param[0] = x_param;
          result_param[1] = y_param;
          result_param[2] = z_param;
         }


       template< typename scalar_name, typename value_name >
        inline
        void
        set
         (
           ::math::linear::vector::structure< scalar_name, 4 >       & result_param
          ,             value_name                 const& value_param
         )
         {
          result_param[0] = value_param;
          result_param[1] = value_param;
          result_param[2] = value_param;
          result_param[3] = value_param;
         }
         
       template< typename scalar_name, typename value_name >
        inline
        void
        set
         (
           ::math::linear::vector::structure< scalar_name, 4 >       & result_param
          ,            value_name                  const& x_param
          ,            value_name                  const& y_param
          ,            value_name                  const& z_param
          ,            value_name                  const& t_param
         )
         {
          result_param[0] = x_param;
          result_param[1] = y_param;
          result_param[2] = z_param;
          result_param[3] = t_param;
         }
         

     }
   }
 }

#endif