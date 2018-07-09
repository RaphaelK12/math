#ifndef math_geometry_projective_plane
#define math_geometry_projective_plane

// ::math::geometry::projective::plane( no3d, left, right, down, up )
// ::math::geometry::projective::plane( no3d, a0, a1, a2 , a3 )
// ::math::geometry::projective::plane( parametric, no3d, x, y )


#include "../../linear/vector/structure.hpp"
#include "../direction/abc.hpp"
#include "../direction/horizon.hpp"
#include "../direction/intersect.hpp"

#include "../plane/no3d.hpp"
#include "../plane/parametric3d.hpp"




namespace math
 {
  namespace geometry
   {
    namespace projective
     {

      template<  typename scalar_name >
       void plane  // Assumed pinhole camera z-up, x, - right, y -strait ahead, project on to plane Z0X ( 0*x + 1*y + 0*z=0 )
        (
          ::math::geometry::plane::no3d<scalar_name>           & no3d
         ,::math::geometry::direction::ABC2D<scalar_name> const& left
         ,::math::geometry::direction::ABC2D<scalar_name> const& right
         ,::math::geometry::direction::ABC2D<scalar_name> const& down
         ,::math::geometry::direction::ABC2D<scalar_name> const& up
        )
        {
         {
          ::math::geometry::direction::horizon<scalar_name> vanish;
          vanish.process( left.normalize(), right.normalize(), down.normalize(), up.normalize() );

          ::math::geometry::direction::ABC2D<scalar_name> horizon( vanish.line() );

          no3d.normal()[0] =-horizon.A();
          no3d.normal()[1] =-horizon.C();
          no3d.normal()[2] =-horizon.B();
          ::math::linear::vector::length<scalar_name>( no3d.normal(), scalar_name(1) );
         }

         ::math::linear::vector::point<scalar_name, 2> origin;
         ::math::geometry::direction::intersect( origin, left, down );

         no3d.origin() = { origin[0], scalar_name( 1 ), origin[1] };
        }

      template<  typename scalar_name >
       void plane // Assumed pinhole camera z-up, x, - right, y -strait ahead, project on to plane Z0X ( 0*x + 1*y + 0*z=0 )
        (
          ::math::geometry::plane::no3d<scalar_name>         & no3d
         ,::math::linear::vector::point<scalar_name, 2> const& a0
         ,::math::linear::vector::point<scalar_name, 2> const& a1
         ,::math::linear::vector::point<scalar_name, 2> const& a2
         ,::math::linear::vector::point<scalar_name, 2> const& a3
        )
        {
         {
          ::math::geometry::direction::horizon<scalar_name> vanish;
          vanish.process( a0, a1, a2, a3 );
          ::math::geometry::direction::ABC2D<scalar_name> horizon( vanish.line() );

          no3d.normal()[0] = -horizon.A();
          no3d.normal()[1] = -horizon.C();
          no3d.normal()[2] = -horizon.B();
          ::math::linear::vector::length<scalar_name>( no3d.normal(), scalar_name(1) );
         }
         no3d.origin()[0] = a0[0];
         no3d.origin()[1] = scalar_name(1);
         no3d.origin()[2] = a0[1];
        }

      template<  typename scalar_name >
       void plane // Assumed pinhole camera z-up, x, - right, y -strait ahead, project on to plane Z0X ( 0*x + 1*y + 0*z=0 )
        (
          ::math::geometry::plane::parametric3d<scalar_name>       & parametric
         ,::math::geometry::plane::no3d<scalar_name>          const& no3d
         ,::math::linear::vector::point<scalar_name, 2>       const& x
         ,::math::linear::vector::point<scalar_name, 2>       const& y
        )
        {
         typedef ::math::geometry::direction::parametric<scalar_name, 3 > line3D_type;
         typedef ::math::linear::vector::point<scalar_name, 3>           point3D_type;

         parametric.origin() = no3d.origin();

         ::math::geometry::plane::intersect( parametric.x(), no3d, line3D_type( point3D_type{0,0,0}, point3D_type{ x[0], scalar_name(1), x[1] } ) );
         ::math::geometry::plane::intersect( parametric.y(), no3d, line3D_type( point3D_type{0,0,0}, point3D_type{ y[0], scalar_name(1), y[1] } ) );

         ::math::linear::vector::subtraction( parametric.x(), parametric.origin() );
         ::math::linear::vector::subtraction( parametric.y(), parametric.origin() );
        }

      template<  typename scalar_name >
       void plane // Assumed pinhole camera z-up, x, - right, y -strait ahead, project on to plane Z0X ( 0*x + 1*y + 0*z=0 )
        (
          ::math::geometry::plane::no3d<scalar_name>            & no3d
         ,::math::geometry::direction::ABC2D<scalar_name> const& horizon
        )
        {
         no3d.normal()[0] = -horizon.A();
         no3d.normal()[1] = -horizon.C();
         no3d.normal()[2] = -horizon.B();
         ::math::linear::vector::length<scalar_name>( no3d.normal(), scalar_name(1) );

         no3d.origin()[0] = 0;
         no3d.origin()[1] = 0;
         no3d.origin()[2] = 0;
        }

     }
   }
 }

#endif

