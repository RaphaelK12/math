#ifndef Dh_math_geometry_plane_make2x2line
 #define Dh_math_geometry_plane_make2x2line
// ::math::type::plane::make2x2line<scalar_name>

#include "../../linear/linear.hpp"

#include "./plane.hpp"

#include "../../geometry/intersect/PL3D.hpp"
#include "../../geometry/intersect/LL2D.hpp"
#include "../../geometry/vanish.hpp"

namespace math
 {
  namespace type
   {
    namespace plane
     {

      template< typename scalar_name >
       struct make2x2line
       {
        public:
         typedef scalar_name scalar_type;

         typedef ::math::geometry::plane::parametric3d<scalar_name> parametric3d_type;
         typedef ::math::geometry::plane::no3d <scalar_name>        no3d_type;

         typedef std::pair< no3d_type, parametric3d_type > return_type;

         typedef ::math::geometry::vanish<scalar_name> vanish_type;

         typedef ::math::linear::vector::scalar<scalar_name, 3>        point3D_type;

         typedef ::math::geometry::direction::ABC2D<scalar_name> line2D_type;
         typedef ::math::geometry::direction::parametric<scalar_name, 3 > line3D_type;

         typedef ::math::geometry::intersect::LL2D< scalar_name > intersectLL2D_type;
         typedef ::math::geometry::intersect::PL2D<scalar_name>        intersectPL3D_type;


          static
          return_type
          calc
           (
            line2D_type const& left
           ,line2D_type const& right
           ,line2D_type const& down
           ,line2D_type const& up
           ,scalar_type const& unit
           )
           {
            point3D_type normal;
            {
             vanish_type vanish;
             vanish.calc( left.normlize(), right.normlize(), down.normlize(), up.normlize() );

             line2D_type horizon( vanish.line() );

             normal[0] = -horizon.A();
             normal[1] = -horizon.C();
             normal[2] = -horizon.B();
             ::math::linear::linear::length<scalar_name>( normal, 1 );
            }

            return_type result;

            scalar_name distance = 1;

            no3d_type & no3d = result.first;
            {
             no3d.normal() = normal;
             {
              typename intersectLL2D_type::point_type a00;
              intersectLL2D_type::process( a00, left, down );

              no3d.origin() = { a00[0], distance , a00[1] };
             }
            }

            parametric3d_type &  parametric = result.second;
            {
             parametric.origin() = no3d.origin();
             typename intersectLL2D_type::point_type a01; intersectLL2D_type::process( a01, right, down  );
             typename intersectLL2D_type::point_type a10; intersectLL2D_type::process( a10, left, up );

             intersectPL3D_type::process( parametric.x(), no3d,  line3D_type( point3D_type{0,0,0}, point3D_type{ a01[0], distance, a01[1] } ) ) ;
             intersectPL3D_type::process( parametric.y(), no3d,  line3D_type( point3D_type{0,0,0}, point3D_type{ a10[0], distance, a10[1] } ) ) ;

             ::math::linear::linear::subtraction( parametric.x() , parametric.origin() );
             ::math::linear::linear::subtraction( parametric.y() , parametric.origin() );
            }

            auto meter = ::math::linear::linear::length( parametric.x() );
            ::math::linear::linear::scale<scalar_type>( parametric.x(),      unit * scalar_type(1) / meter );
            ::math::linear::linear::scale<scalar_type>( parametric.y() ,     unit * scalar_type(1) / meter );
            ::math::linear::linear::scale<scalar_type>( parametric.origin(), unit * scalar_type(1) / meter );
            ::math::linear::linear::scale<scalar_type>(       no3d.origin(), unit * scalar_type(1) / meter );
            ::math::linear::linear::scale<scalar_type>(       no3d.normal(), unit * scalar_type(1) / meter );

            return result;
           }

       };

     }
   }
 }

#endif

