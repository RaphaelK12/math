#ifndef math_geometry_projective_camera_epi
#define math_geometry_projective_camera_epi

// ::math::geometry::projective::camera::epiline<scalar>
// ::math::geometry::projective::camera::epi( line, uv, camera )

#include "../../../linear/vector/cross.hpp"
#include "../../../linear/vector/make.hpp"
#include "../../../geometry/plane/intersect.hpp"


namespace math
 {
  namespace geometry
   {
    namespace projective
     {
      namespace camera
       {

        template < typename scalar_name >
         class epiline
          {
           public:
             typedef scalar_name   scalar_type;
             typedef ::math::geometry::direction::parametric<scalar_name, 2>    line2D_type;
             typedef ::math::geometry::direction::parametric<scalar_name, 3>    line3D_type;

             typedef ::math::linear::vector::structure< scalar_name , 2 >      point2D_type, uv_type;
             typedef ::math::linear::vector::structure< scalar_name , 3 >      point3D_type;
             typedef ::math::geometry::projective::camera::mobile< scalar_name >   camera_type;

             typedef ::math::geometry::plane::no3d<scalar_name> no3d_type;

             epiline()
              {
               m_leftIP =  no3d_type { {0,1,0}, { 0, 1, 0 } };
               m_ePlane.origin( ) = {0,0,0};
              }

           public:

             bool process( line2D_type & epiL, line2D_type & epiR, uv_type const& uv, camera_type const& camera )
              { //!< Compute epiline on both camera
                m_t = point3D_type{ camera.to_world()[3] };
                m_leftE3D.origin() = { uv[0], 1, uv[1] };
               ::math::linear::vector::cross( m_ePlane.normal(), m_t, m_leftE3D.origin() );

               ::math::geometry::plane::intersect( m_leftE3D, m_leftIP, m_ePlane );
               ::math::linear::vector::load( epiL.origin(),    m_leftE3D.origin()[0],    m_leftE3D.origin()[2] );
               ::math::linear::vector::load( epiL.direction(), m_leftE3D.direction()[0], m_leftE3D.direction()[2] );

               ::math::linear::vector::load( m_rightIP.normal(), camera.to_world()[1][0], camera.to_world()[1][1], camera.to_world()[1][2] );
               ::math::linear::vector::addition( m_rightIP.origin(), m_t, m_rightIP.normal() );

               ::math::geometry::plane::intersect( m_rightE3D, m_rightIP, m_ePlane );
               ::math::linear::affine::transform( m_rightLocal,  camera.to_local(), m_rightE3D );
               ::math::linear::vector::load( epiR.origin(),     m_rightLocal.origin()[0],    m_rightLocal.origin()[2] );
               ::math::linear::vector::load( epiR.direction(),  m_rightLocal.direction()[0], m_rightLocal.direction()[2] );
               return true;
              }

             bool processL( line2D_type & epiL, uv_type const& uv, camera_type const& camera )
              {
               m_t = point3D_type{ camera.to_world()[3] };
               m_leftE3D.origin() = { uv[0], 1, uv[1] };
               ::math::linear::vector::cross( m_ePlane.normal(), m_t, m_leftE3D.origin() );

               ::math::linear::vector::cross( m_leftE3D.direction(), m_ePlane.normal(), m_leftIP.normal() );

               ::math::linear::vector::load( epiL.origin(),    m_leftE3D.origin()[0],    m_leftE3D.origin()[2] );
               ::math::linear::vector::load( epiL.direction(), m_leftE3D.direction()[0], m_leftE3D.direction()[2] );

               return true;
              }

             bool processR( line2D_type & epiR, uv_type const& uv, camera_type const& camera )
              {
               m_t = point3D_type{ camera.to_world()[3] };
               m_leftE3D.origin() = { uv[0], 1, uv[1] };
               ::math::linear::vector::cross( m_ePlane.normal(), m_t, m_leftE3D.origin() );

               ::math::linear::vector::load( m_rightIP.normal(), camera.to_world()[1][0], camera.to_world()[1][1], camera.to_world()[1][2] );
               ::math::linear::vector::addition( m_rightIP.origin(), m_t, m_rightIP.normal() );

               ::math::geometry::plane::intersect( m_rightE3D, m_rightIP, m_ePlane );
               ::math::linear::affine::transform( m_rightLocal,  camera.to_local(), m_rightE3D );
               ::math::linear::vector::load( epiR.origin(),     m_rightLocal.origin()[0],    m_rightLocal.origin()[2] );
               ::math::linear::vector::load( epiR.direction(),  m_rightLocal.direction()[0], m_rightLocal.direction()[2] );

               return true;
              }

           public:
             /*static*/ no3d_type  m_leftIP;
             no3d_type             m_rightIP;
             no3d_type    m_ePlane;

             point3D_type m_t;

             line3D_type m_leftE3D;
             line3D_type m_rightE3D, m_rightLocal;
          };

        template < typename scalar_name >
         void
         epi   //!< Compute epiline on both camera
          (
            ::math::geometry::direction::parametric<scalar_name, 2>               & epiL
           ,::math::geometry::direction::parametric<scalar_name, 2>               & epiR
           ,::math::linear::vector::structure< scalar_name , 2 >             const& uv
           ,::math::geometry::projective::camera::mobile< scalar_name >      const& camera
          )
          {
           ::math::geometry::projective::camera::epiline<scalar_name> epiline;
           epiline.process( epiL, epiR, uv, camera );
          }

        template < typename scalar_name >
         void
         epiL     //!< Compute epiline on left camera
          (
            ::math::geometry::direction::parametric<scalar_name, 2>               & epiL
           ,::math::linear::vector::structure< scalar_name , 2 >             const& uv
           ,::math::geometry::projective::camera::mobile< scalar_name >      const& camera
          )
          {
           ::math::geometry::projective::camera::epiline<scalar_name> epiline;
           epiline.processL( epiL, uv, camera );
          }

        template < typename scalar_name >
         void
         epiR   //!< Compute epiline on right camera
          (
            ::math::geometry::direction::parametric<scalar_name, 2>               & epiR
           ,::math::linear::vector::structure< scalar_name , 2 >             const& uv
           ,::math::geometry::projective::camera::mobile< scalar_name >      const& camera
          )
          {
           ::math::geometry::projective::camera::epiline<scalar_name> epiline;
           epiline.processR( epiR, uv, camera );
          }

       }
     }
   }
 }

#endif
