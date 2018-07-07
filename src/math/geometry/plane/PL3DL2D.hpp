#ifndef math_geometry_intersect_PL3DL2D
#define math_geometry_intersect_PL3DL2D

// ::math::geometry::plane::intersect( point, no3d, parametric, epsilon )

// ::math::geometry::plane::PL3DL2D<scalar_name>::process

#include "../../linear/vector/structure.hpp"
#include "../direction/parametric.hpp"

#include "./no3d.hpp"
#include "./parametric3d.hpp"



namespace math
 {
  namespace geometry
   {
    namespace plane
     {

      template<  typename scalar_name >
       struct PL3DL2D
        {
         public:
           typedef scalar_name scalar_type;

           typedef ::math::linear::vector::point<scalar_type,3>             point_type;
           typedef ::math::geometry::plane::no3d <scalar_type>              no3d_type;

           typedef ::math::geometry::direction::parametric<scalar_name, 3 > line_type;

           static bool process
            (
              point_type         & point
             ,scalar_type        & lambda
             ,no3d_type    const & plane
             ,line_type    const & line
             ,scalar_type  const & epsilon = 1e-6
            )
            {
             scalar_type dot_down = ::math::linear::vector::dot( line.direction(), plane.normal() );

             if( fabs( dot_down ) < epsilon )
              {
               return false;
              }

             point_type t;

             ::math::linear::vector::subtraction( t, plane.origin(),line.origin() );
             scalar_type dot_up = ::math::linear::vector::dot( t, plane.normal() );

             //point = line.origin() + ( dot_up / dot_down ) * line.direction();
             lambda = dot_up / dot_down;
             line.point( point, lambda );
             return true;
            }

        };

      template<  typename scalar_name >
       bool intersect
        (
          ::math::linear::vector::point<scalar_name,3>                     & point
         ,::math::geometry::plane::no3d <scalar_name>                const & plane
         ,::math::geometry::direction::parametric<scalar_name, 3 >   const & line
         ,scalar_name                                                const & epsilon = 1e-6
        )
        {
         scalar_name  lambda;
         return ::math::geometry::plane::PL3DL2D<scalar_name>::process( point, lambda, plane, line, epsilon );
        }

      template<  typename scalar_name >
       bool intersect
        (
          ::math::linear::vector::point<scalar_name,3>                     & point
         ,scalar_name                                                      & lambda
         ,::math::geometry::plane::no3d <scalar_name>                const & plane
         ,::math::geometry::direction::parametric<scalar_name, 3 >   const & line
         ,scalar_name                                                const & epsilon = 1e-6
        )
        {
         return ::math::geometry::plane::PL3DL2D<scalar_name>::process( point, lambda, plane, line, epsilon );
        }

     }
   }
 }

#endif

