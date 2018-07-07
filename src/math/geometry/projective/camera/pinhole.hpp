#ifndef lib_math_camera_pinhole
#define lib_math_camera_pinhole
 // ::math::geometry::projective::camera::pinhole< scalar >

#include "math/linear/vector/structure.hpp"

/*
          ^
          |   -.
          Z   /|
          |  Y
          | /
----------------X------>
          |
          |
*/

namespace math
 {
  namespace geometry
   {
    namespace projective
     {
      namespace camera
       {

        template< typename scalar_name >
         class pinhole
          {
           public:
             typedef scalar_name  scalar_type;
        
             typedef ::math::linear::vector::point< scalar_type , 2 >        uv_type;
             typedef ::math::linear::vector::point< scalar_type , 3 >   point3d_type;
        
             pinhole()
              {
              }
        
             //uv_type project( point3d_type const& point3d )
             // {
             //  return uv_type{ point3d[0] / point3d[1], point3d[2] / point3d[1] };
             // }
        
             static uv_type project( point3d_type const& point3d )
              {
               return uv_type{ point3d[0] / point3d[1], point3d[2] / point3d[1] };
              }
        
          };

       }
     }
   }
 }

#endif
