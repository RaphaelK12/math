#ifndef Dh_math_linear_affine_set
#define Dh_math_linear_affine_set

 // ::math::linear::affine::set(a,o,x,y,z)

#include "../vector/vector.hpp"
#include "./structure.hpp"


 namespace math
  {
   namespace linear
    {
     namespace affine
      {

       // TODO template< typename scalar_name, unsigned dimension_number >
       // TODO  void set
       // TODO   (
       // TODO     ::math::linear::affine::structure<scalar_name,dimension_number,dimension_number>                            & result
       // TODO    ,std::array< ::math::linear::vector::structure<scalar_name,dimension_number>, dimension_number+1>      const & system
       // TODO   )
       // TODO   {
       // TODO    ::math::linear::matrix::set( result.matrix(), system );
       // TODO    result.vector() = system[0];
       // TODO   }

       template< typename scalar_name >
        void set
         (
           ::math::linear::affine::structure<scalar_name,2>          & result
          ,::math::linear::vector::structure<scalar_name,2>      const & o
          ,::math::linear::vector::structure<scalar_name,2>      const & x
          ,::math::linear::vector::structure<scalar_name,2>      const & y
         )
         {
          ::math::linear::matrix::init( result.matrix(), x, y );
          result.vector() = o;
         }

       template< typename scalar_name >
        void set
         (
           ::math::linear::affine::structure<scalar_name,3>          & result
          ,::math::linear::vector::structure<scalar_name,3>      const & o
          ,::math::linear::vector::structure<scalar_name,3>      const & x
          ,::math::linear::vector::structure<scalar_name,3>      const & y
          ,::math::linear::vector::structure<scalar_name,3>      const & z
         )
         {
          ::math::linear::matrix::init( result.matrix(), x, y, z );
          result.vector() = o;
         }

      }
    }
  }

#endif
