#ifndef math_geometry_plane_no3d
#define math_geometry_plane_no3d

// ::math::geometry::plane::no3d<scalar_name>

#include "../../linear/vector/structure.hpp"



namespace math
 {
  namespace geometry
   {
    namespace plane
     {

      template < typename scalar_name >
       class ABCD3D;

      template< typename scalar_name >
        class no3d;

      template < typename scalar_name >
       class parametric3d;

      template
       <
         typename scalar_name = double
       >
       class no3d // normal _dot_ ( point - normal ) = 0
        {
         public:

           typedef scalar_name scalar_type;
           typedef ::math::linear::vector::point<scalar_name,3>  point_type;

           typedef ::math::geometry::plane::ABCD3D<scalar_name>              ABCD3D_type;
           typedef ::math::geometry::plane::no3d<scalar_name>                  no3d_type, this_type;
           typedef ::math::geometry::plane::parametric3d<scalar_name>  parametric3d_type;

        public:
           no3d()
            {
            }

           no3d( point_type const& origin, point_type const& normal )
            :m_origin( origin )
            ,m_normal( normal )
            {
            }

        public:
           explicit no3d( ABCD3D_type const& abcd )
            {
             *this = abcd;
            }

           explicit no3d( parametric3d_type const& parametric )
            {
             *this = parametric;
            }

        public:
          no3d & operator=( parametric3d_type const& parametric )
           {
            this->m_origin = parametric.origin();

            ::math::linear::vector::cross( this->m_normal, parametric.x(), parametric.y() );
            ::math::linear::vector::length<scalar_type,3>( this->m_normal, 1 );

            return *this;
           }

          no3d & operator=( ABCD3D_type const& abcd )
           {
            ::math::linear::vector::load( this->m_normal, abcd.A(), abcd.B(), abcd.C() );

            scalar_type dot= ::math::linear::vector::dot( this->m_normal, this->m_normal ) ;

            scalar_type lambda = -abcd.D()/ dot;

            ::math::linear::vector::scale( this->m_origin, lambda, this->m_normal );
            return *this;
           }

        public:
          point_type const& origin()const
           {
            return m_origin;
           }
          point_type & origin()
           {
            return m_origin;
           }
        private:
          point_type m_origin;

        public:
          point_type const& normal()const
           {
            return m_normal;
           }
          point_type & normal()
           {
            return m_normal;
           }
        private:
          point_type m_normal;
        };

     }
   }
 }

#endif

