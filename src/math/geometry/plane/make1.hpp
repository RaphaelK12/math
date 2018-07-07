#ifndef math_type_plane_make2x2point
#define math_type_plane_make2x2point
// ::math::type::plane::make2x2point<scalar_name>

#include "../../linear/linear.hpp"

#include "../../geometry/intersect/PL3D.hpp"
#include "../../geometry/intersect/LL2D.hpp"
#include "../../geometry/vanish.hpp"

#include "./plane.hpp"

namespace math
 {
  namespace type
   {
    namespace plane
     {

      template< typename scalar_name >
       struct make2x2point
       {
        public:
          typedef scalar_name scalar_type;

          typedef ::math::type::plane::parametric3d<scalar_name> parametric3d_type;
          typedef ::math::type::plane::no3d <scalar_name>        no3d_type;

          typedef std::pair< no3d_type, parametric3d_type > return_type;

          typedef ::math::geometry::vanish<scalar_name> vanish_type;

          typedef ::math::type::vektor<scalar_name, 2>        point2D_type;
          typedef ::math::type::vektor<scalar_name, 3>        point3D_type;
          
          typedef ::math::type::direction::ABC2D<scalar_name> line2D_type;
          typedef ::math::type::direction::parametric<scalar_name, 3 > line3D_type;


          typedef ::math::geometry::intersect::LL2D< scalar_name > intersectLL2D_type;
          typedef ::math::geometry::intersect::PL2D<scalar_name>   intersectPL3D_type;
        public:
          static
          return_type
          calc
           (
             point2D_type const& a0
            ,point2D_type const& a1
            ,point2D_type const& a2
            ,point2D_type const& a3
            ,scalar_type const& unit
           )
           {
            return_type result;

            no3d_type & no3d = result.first;
            {
             vanish_type vanish;
             vanish.calc( a0, a1, a2, a3 );
             line2D_type horizon( vanish.line() );

             auto D = sqrt( horizon.A() * horizon.A() + horizon.m_B*horizon.m_B + horizon.m_C*horizon.m_C );
             no3d.normal()[0] = -horizon.A() / D;
             no3d.normal()[1] = -horizon.C() / D;
             no3d.normal()[2] = -horizon.B() / D;

             no3d.origin()[0] = a0[0];
             no3d.origin()[1] = 1;
             no3d.origin()[2] = a0[1];
            }

            parametric3d_type &  parametric = result.second;
            {
             parametric.origin() = no3d.origin();
             intersectPL3D_type::process( parametric.x(), no3d,  line3D_type( point3D_type{0,0,0}, point3D_type{ a1[0], 1, a1[1] } ) ) ;
             intersectPL3D_type::process( parametric.y(), no3d,  line3D_type( point3D_type{0,0,0}, point3D_type{ a3[0], 1, a3[1] } ) ) ;

             ::math::linear::operation::subtraction( parametric.x() , parametric.origin() );
             ::math::linear::operation::subtraction( parametric.y() , parametric.origin() );
            }

            auto meter = ::math::linear::operation::length( parametric.x() );
            ::math::linear::operation::scale<scalar_type>( parametric.x(),      unit * scalar_type(1) / meter );
            ::math::linear::operation::scale<scalar_type>( parametric.y() ,     unit * scalar_type(1) / meter );
            ::math::linear::operation::scale<scalar_type>( parametric.origin(), unit * scalar_type(1) / meter );
            ::math::linear::operation::scale<scalar_type>(       no3d.origin(), unit * scalar_type(1) / meter );
            ::math::linear::operation::scale<scalar_type>(       no3d.normal(), unit * scalar_type(1) / meter );

            //auto dot = ::math::linear::operation::dot( parametric.x() , parametric.y() );

            return result;
           }

       };

     }
   }
 }

#endif

