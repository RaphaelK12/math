#ifndef math_type_affine_transform
 #define math_type_affine_transform

 // ::math::linear::affine::transform<scalar_name,dimension_number>

#include "../vector/structure.hpp"
#include "./structure.hpp"

 namespace math
  {
   namespace linear
    {
     namespace affine
      {

       template< typename scalar_name, unsigned dimension_number >
        void transform
         (
           ::math::linear::vector::structure<scalar_name,dimension_number>                 & result
          ,::math::linear::affine::structure<scalar_name,dimension_number> const& left
          ,::math::linear::vector::structure<scalar_name,dimension_number>            const& right
         )
         {
          ::math::linear::matrix::transform( result, left.matrix(), right );
          ::math::linear::vector::addition( result, left.vector() );
         }

       template< typename scalar_name, unsigned dimension_number >
        void transform
         (
           ::math::linear::vector::structure<scalar_name,dimension_number>                 & result
          ,::math::linear::affine::structure<scalar_name,dimension_number> const& left
         )
         {
          ::math::linear::affine::transform<scalar_name,dimension_number>( result, left, ::math::linear::vector::structure<scalar_name,dimension_number>( result ) );
         }
      }
    }
  }

#endif