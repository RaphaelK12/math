#ifndef lib_math_camera_ha2d
#define lib_math_camera_ha2d

// ::math::geometry::projective::camera::ha2d( h_alpha, aspect )

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
    scalar_name
    ha2d
     (
       scalar_name const& h_alpha
      ,scalar_name const& aspect
     )
     {
      scalar_name h_scale = 2 * tan( h_alpha / 2 );
      scalar_name v_scale = h_scale / aspect;

      scalar_name diagonal = sqrt( h_scale * h_scale  +  v_scale * v_scale );

      return 2 * atan( diagonal / 2 );
     }

       }
     }
   }
 }

#endif
