#ifndef Dh_math_linear_affine_construct
 #define Dh_math_linear_affine_construct

 // ::math::linear::affine::construct<scalar_name,dimension_number>

#include "./transform.hpp"
#include "./structure.hpp"
#include "./system.hpp"
#include "./invert.hpp"
#include "./compose.hpp"




 namespace math
  {
   namespace linear
    {
     namespace affine
      {

       template< typename scalar_name, unsigned dimension_number >
        void construct
         (
           ::math::linear::affine::structure<scalar_name,dimension_number>      & transformation
          ,::math::linear::affine::structure<scalar_name,dimension_number> const& world
          ,::math::linear::affine::structure<scalar_name,dimension_number> const& local
         )
         {
          // TODO local = transformation( world );
         }

       template< typename scalar_name >
        void construct
         (
           ::math::linear::affine::structure<scalar_name,2>                   & result
          ,std::array< ::math::linear::vector::point<scalar_name,2>, 3 > const& target
          ,std::array< ::math::linear::vector::point<scalar_name,2>, 3 > const& source
         )
         {
          ::math::linear::affine::structure<scalar_name,2> fs, t0, tt;

          ::math::linear::affine::system( t0, source[0], source[1], source[2] );
          ::math::linear::affine::invert( fs, t0 );

          ::math::linear::affine::system( tt, target[0], target[1], target[2] );

          ::math::linear::affine::compose( result, tt, fs );
         }

       template< typename scalar_name >
        void construct
         (
           ::math::linear::affine::structure<scalar_name,3>                   & result
          ,std::array< ::math::linear::vector::point<scalar_name,3>, 4 > const& target
          ,std::array< ::math::linear::vector::point<scalar_name,3>, 4 > const& source
         )
         {
          ::math::linear::affine::structure<scalar_name,3> fs, t0, tt;

          ::math::linear::affine::system( t0, source[0], source[1], source[2], source[3] );
          ::math::linear::affine::invert( fs, t0 );

          ::math::linear::affine::system( tt, target[0], target[1], target[2], target[3] );

          ::math::linear::affine::compose( result, tt, fs );
         }

       template< typename scalar_name >
        void construct
         (
           ::math::linear::affine::structure<scalar_name,4>                   & result
          ,std::array< ::math::linear::vector::point<scalar_name,4>, 5 > const& target
          ,std::array< ::math::linear::vector::point<scalar_name,4>, 5 > const& source
         )
         {
          ::math::linear::affine::structure<scalar_name,4> fs, t0, tt;

          ::math::linear::affine::system( t0, source[0], source[1], source[2], source[3], source[4] );
          ::math::linear::affine::invert( fs, t0 );

          ::math::linear::affine::system( tt, target[0], target[1], target[2], target[3], target[4] );

          ::math::linear::affine::compose( result, tt, fs );
         }



      }
    }
  }

#endif