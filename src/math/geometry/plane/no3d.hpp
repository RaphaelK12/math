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

      template
       <
         typename scalar_name
       >
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
           typedef ::math::geometry::plane::parametric3d<scalar_name> parametric3d_type;

           no3d()
            {
            }

           no3d( point_type const& origin, point_type const& normal )
            :m_origin( origin )
            ,m_normal( normal )
            {
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

