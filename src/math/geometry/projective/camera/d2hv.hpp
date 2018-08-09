#ifndef math_geometry_projective_camera_d2hv
#define math_geometry_projective_camera_d2hv

// ::math::geometry::projective::camera::d2hv( alpha, h_scale, v_scale )

//#include <utility>

namespace math
 {
  namespace geometry
   {
    namespace projective
     {
      namespace camera
       {

   template < typename scalar_name >
    std::pair<scalar_name,scalar_name>
    d2hv
     (
       scalar_name const& alpha
      ,scalar_name const& h_scale
      ,scalar_name const& v_scale
     )
     {
      scalar_name diagonal = sqrt( h_scale* h_scale + v_scale * v_scale );
      scalar_name focus = (diagonal/2) / tan( alpha / 2 ) ;

      scalar_name h_alpha = 2 * atan( (h_scale/2) / focus );
      scalar_name v_alpha = 2 * atan( (v_scale/2) / focus );
      return std::make_pair( h_alpha, v_alpha );
     }

       }
     }
   }
 }

#endif
