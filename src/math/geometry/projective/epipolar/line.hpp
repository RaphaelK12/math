#ifndef math_geometry_projective_camera_epi
#define math_geometry_projective_camera_epi

// ::math::geometry::projective::epipolar::line<scalar>
// ::math::geometry::projective::epipolar::line( line, uv, camera )

#include "../../../linear/vector/cross.hpp"
#include "../../../linear/vector/make.hpp"
#include "../../../geometry/plane/intersect.hpp"
#include "../camera/mobile.hpp"


namespace math
 {
  namespace geometry
   {
    namespace projective
     {
      namespace epipolar
       {

        template < typename scalar_name >
         class line
          {
           public:
             typedef scalar_name   scalar_type;
             typedef ::math::geometry::direction::parametric<scalar_name, 2>    line2D_type;
             typedef ::math::geometry::direction::parametric<scalar_name, 3>    line3D_type;

             typedef ::math::linear::vector::structure< scalar_name , 2 >      point2D_type, uv_type;
             typedef ::math::linear::vector::structure< scalar_name , 3 >      point3D_type;
             typedef ::math::geometry::projective::camera::mobile< scalar_name >   camera_type;

             typedef ::math::geometry::plane::no3d<scalar_name> no3d_type;
             typedef ::math::geometry::plane::parametric3d<scalar_name> parametric3D_type;
             typedef ::math::geometry::plane::three<scalar_name> three_type;

             line()
              {
              }

           public:

             bool process( line2D_type & epiL, line2D_type & epiR, uv_type const& uv, camera_type const& camera_right )
              { //!< Compute line on both camera
               ::math::linear::vector::load( m_leftEye, 0,0,0 );
               m_rightEye = camera_right.to_world().vector();

               m_leftWorld.origin() = { uv[0], 1, uv[1] };

               m_ePlane = three_type{ m_leftEye, m_rightEye, m_leftWorld.origin() };
               ::math::linear::vector::load( m_leftIP.normal(), 0, 1, 0 );
               ::math::linear::vector::load( m_leftIP.origin(), 0, 1, 0 ); 

               ::math::geometry::plane::intersect( m_leftWorld, m_leftIP, m_ePlane );
                m_leftLocal = m_leftWorld;
               ::math::linear::vector::load( epiL.origin(),    m_leftLocal.origin()[0],    m_leftLocal.origin()[2] );
               ::math::linear::vector::load( epiL.direction(), m_leftLocal.direction()[0], m_leftLocal.direction()[2] );

               ::math::linear::vector::load( m_rightIP.normal(), camera_right.to_world()[0][1], camera_right.to_world()[1][1], camera_right.to_world()[2][1] );
               ::math::linear::vector::addition( m_rightIP.origin(), m_rightEye, m_rightIP.normal() ); 
               ::math::geometry::plane::intersect( m_rightWorld, m_rightIP, m_ePlane );
               ::math::linear::affine::transform( m_rightLocal,  camera_right.to_local(), m_rightWorld );
               ::math::linear::vector::load( epiR.origin(),     m_rightLocal.origin()[0],    m_rightLocal.origin()[2] );
               ::math::linear::vector::load( epiR.direction(),  m_rightLocal.direction()[0], m_rightLocal.direction()[2] );

               return true;
              }

             bool process( line2D_type & epiL, line2D_type & epiR, uv_type const& uv_left, camera_type const& camera_left, camera_type const& camera_right )
              { //!< Compute line on both camera. TODO Not optimal!! Academically correct.
               m_leftEye  = camera_left.to_world().vector();
               m_rightEye = camera_right.to_world().vector();

               m_leftWorld.origin() = { uv_left[0], 1, uv_left[1] };
               ::math::linear::affine::transform( m_leftWorld.origin(), camera_left.to_world() );

               m_ePlane = three_type{ m_leftEye, m_rightEye, m_leftWorld.origin() };

               ::math::linear::vector::load(     m_leftIP.normal(), camera_left.to_world()[0][1], camera_left.to_world()[1][1], camera_left.to_world()[2][1] );
               ::math::linear::vector::addition( m_leftIP.origin(), m_leftEye, m_leftIP.normal() ); 
               ::math::geometry::plane::intersect( m_leftWorld, m_leftIP, m_ePlane );
               ::math::linear::affine::transform( m_leftLocal,  camera_left.to_local(), m_leftWorld );
               ::math::linear::vector::load( epiL.origin(),    m_leftLocal.origin()[0],    m_leftLocal.origin()[2] );
               ::math::linear::vector::load( epiL.direction(), m_leftLocal.direction()[0], m_leftLocal.direction()[2] );

               ::math::linear::vector::load(     m_rightIP.normal(), camera_right.to_world()[0][1], camera_right.to_world()[1][1], camera_right.to_world()[2][1] );
               ::math::linear::vector::addition( m_rightIP.origin(), m_rightEye, m_rightIP.normal() ); 
               ::math::geometry::plane::intersect( m_rightWorld, m_rightIP, m_ePlane );
               ::math::linear::affine::transform( m_rightLocal,  camera_right.to_local(), m_rightWorld );
               ::math::linear::vector::load( epiR.origin(),     m_rightLocal.origin()[0],    m_rightLocal.origin()[2] );
               ::math::linear::vector::load( epiR.direction(),  m_rightLocal.direction()[0], m_rightLocal.direction()[2] );

               return true;
              }

             bool processL( line2D_type & epiL, uv_type const& uv_left, camera_type const& camera_left, camera_type const& camera_right )
              {
               m_leftEye  = camera_left.to_world().vector();
               m_rightEye = camera_right.to_world().vector();

               m_leftWorld.origin() = { uv_left[0], 1, uv_left[1] };
               ::math::linear::affine::transform( m_leftWorld.origin(), camera_left.to_world() );

               m_ePlane = three_type{ m_leftEye, m_rightEye, m_leftWorld.origin() };

               ::math::linear::vector::load( m_leftIP.normal(), camera_left.to_world()[0][1], camera_left.to_world()[1][1], camera_left.to_world()[2][1] );
               ::math::linear::vector::addition( m_leftIP.origin(), m_leftEye, m_leftIP.normal() ); 

               ::math::geometry::plane::intersect( m_leftWorld, m_leftIP, m_ePlane );
               ::math::linear::affine::transform( m_leftLocal,  camera_left.to_local(), m_leftWorld );
               ::math::linear::vector::load( epiL.origin(),    m_leftLocal.origin()[0],    m_leftLocal.origin()[2] );
               ::math::linear::vector::load( epiL.direction(), m_leftLocal.direction()[0], m_leftLocal.direction()[2] );

               return true;
              }

             bool processR( line2D_type & epiR, uv_type const& uv_left, camera_type const& camera_left, camera_type const& camera_right )
              {
               m_leftEye  = camera_left.to_world().vector();
               m_rightEye = camera_right.to_world().vector();

               m_leftWorld.origin() = { uv_left[0], 1, uv_left[1] };
               ::math::linear::affine::transform( m_leftWorld.origin(), camera_left.to_world() );

               m_ePlane = three_type{ m_leftEye, m_rightEye, m_leftWorld.origin() };

               ::math::linear::vector::load( m_rightIP.normal(), camera_right.to_world()[0][1], camera_right.to_world()[1][1], camera_right.to_world()[2][1] );
               ::math::linear::vector::addition( m_rightIP.origin(), m_rightEye, m_rightIP.normal() ); 
               ::math::geometry::plane::intersect( m_rightWorld, m_rightIP, m_ePlane );
               ::math::linear::affine::transform( m_rightLocal,  camera_right.to_local(), m_rightWorld );
               ::math::linear::vector::load( epiR.origin(),     m_rightLocal.origin()[0],    m_rightLocal.origin()[2] );
               ::math::linear::vector::load( epiR.direction(),  m_rightLocal.direction()[0], m_rightLocal.direction()[2] );

               return true;
              }

             bool adjust(  line2D_type & epi, camera_type const& camera )
              {
               auto window = camera.optical().window();
               std::tuple< unsigned, scalar_name, unsigned, scalar_name > result;
               if( false == ::math::geometry::interval::intersect( result, window, epi ) )
                {
                 return false;
                }
               ::math::linear::vector::combine( epi.origin(),  epi.origin(), std::get<1>(result), epi.direction() );
               ::math::linear::vector::length( epi.direction(), std::get<3>(result) - std::get<1>(result) );
               return true;
              }

           public:
             no3d_type  m_leftIP;   //!< Left Image plane
             no3d_type  m_rightIP;  //!< Right Image plane
             no3d_type  m_ePlane;   //!< Epipolar plane

             point3D_type m_rightEye;
             point3D_type m_leftEye;

             line3D_type m_leftWorld,  m_leftLocal;  //!< left  epipolar direction in world space and in local space
             line3D_type m_rightWorld, m_rightLocal; //!< right epipolar direction in world space and in local space
          };

        template < typename scalar_name >
         void
         lineALL   //!< Compute line on both camera
          (
            ::math::geometry::direction::parametric<scalar_name, 2>               & epiL
           ,::math::geometry::direction::parametric<scalar_name, 2>               & epiR
           ,::math::linear::vector::structure< scalar_name , 2 >             const& uv_left
           ,::math::geometry::projective::camera::mobile< scalar_name >      const& camera_right
          )
          {
           ::math::geometry::projective::epipolar::line<scalar_name> line;
           line.process( epiL, epiR, uv_left, camera_right );
          }

        template < typename scalar_name >
         void
         lineALL   //!< Compute line on both camera
          (
            ::math::geometry::direction::parametric<scalar_name, 2>               & epiL
           ,::math::geometry::direction::parametric<scalar_name, 2>               & epiR
           ,::math::linear::vector::structure< scalar_name , 2 >             const& uv_left
           ,::math::geometry::projective::camera::mobile< scalar_name >      const& camera_left
           ,::math::geometry::projective::camera::mobile< scalar_name >      const& camera_right
          )
          {
           ::math::geometry::projective::epipolar::line<scalar_name> line;
           line.process( epiL, epiR, uv_left, camera_right );
          }


        template < typename scalar_name >
         void
         lineL     //!< Compute line on left camera
          (
            ::math::geometry::direction::parametric<scalar_name, 2>               & epiL
           ,::math::linear::vector::structure< scalar_name , 2 >             const& uv_left
           ,::math::geometry::projective::camera::mobile< scalar_name >      const& camera_right
          )
          {
           ::math::geometry::projective::epipolar::line<scalar_name> line;
           line.processL( epiL, uv_left, camera_right );
          }

        template < typename scalar_name >
         void
         lineR   //!< Compute line on right camera
          (
            ::math::geometry::direction::parametric<scalar_name, 2>               & epiR
           ,::math::linear::vector::structure< scalar_name , 2 >             const& uv_left
           ,::math::geometry::projective::camera::mobile< scalar_name >      const& camera_right
          )
          {
           ::math::geometry::projective::epipolar::line<scalar_name> line;
           line.processR( epiR, uv_left, camera_right );
          }

       }
     }
   }
 }

#endif
