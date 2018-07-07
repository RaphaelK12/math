#ifndef lib_math_camera_va2h
#define lib_math_camera_va2h

// ::math::geometry::projective::camera::va2h( h_alpha, aspect )

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
    va2h
     (
       scalar_name const& h_alpha
      ,scalar_name const& aspect
     )
     {
      scalar_name v_scale = 2 * tan( v_alpha / 2 );
      scalar_name h_scale = v_scale * aspect;

      return 2 * atan( h_scale / 2 );
     }

       }
     }
   }
 }

#endif
