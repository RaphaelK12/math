#ifndef lib_math_camera_hv2d
#define lib_math_camera_hv2d

// ::math::geometry::projective::camera::hv2d( h_alpha, v_alpha )


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
    hv2d
     (
       scalar_name const& h_alpha
      ,scalar_name const& v_alpha
     )
     {
      scalar_name h_scale = 2 * tan( h_alpha / 2 );
      scalar_name v_scale = 2 * tan( v_alpha / 2 );

      scalar_name diagonal = sqrt( h_scale* h_scale + v_scale * v_scale );

      return 2 * atan( diagonal / 2 );
     }

       }
     }
   }
 }

#endif
