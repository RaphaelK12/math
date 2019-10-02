#ifndef math_geometry_plane_fit3D
#define math_geometry_plane_fit3D

// ::math::geometry::plane::fit3D<double>::process( abc, cloud )

#include <vector>
#include "../../linear/vector/vector.hpp"
#include "./no3d.hpp"


namespace math
 {
  namespace geometry
   {
    namespace plane
     {

      template
       <
        typename scalar_name = double
       >
       struct fit3D
        {
         public:

           typedef scalar_name scalar_type;
           typedef ::math::linear::vector::point<scalar_type,3>    point_type;
           typedef ::math::geometry::plane::no3d<scalar_type>      plane_type;

           typedef std::vector< point_type > cloud_type;

           static bool process( plane_type & plane, cloud_type const& cloud, scalar_type const& epsilon = 1e-12 )
            {
             if( cloud.size() < 3 )
              {
               return false;
              }

             point_type center={0,0,0};

             scalar_type XX = 0;
             scalar_type XY = 0;
             scalar_type XZ = 0;
             scalar_type YY = 0;
             scalar_type YZ = 0;
             scalar_type ZZ = 0;

             for( auto const& point: cloud )
              {
               XX += point[0]*point[0];
               XY += point[0]*point[1];
               XZ += point[0]*point[2];
               YY += point[1]*point[1];
               YZ += point[1]*point[2];
               ZZ += point[2]*point[2];
               center[0] += point[0]; center[1] += point[1]; center[2] += point[2];
              }

             scalar_type const Dx = YY * ZZ - YZ*YZ;
             scalar_type const Dy = XX * XX - XZ*XZ;
             scalar_type const Dz = XX * YY - XY*XY;

             scalar_type const Dmax = std::max( std::max( fabs(Dx), fabs(Dy) ), fabs(Dz) );
             if( Dmax < epsilon )
              {
               return false;
              }
              
             point_type normal;

             if( fabs(Dx) == Dmax )
              {
               normal[0] = Dx;
               normal[1] = XZ*YZ - XY*ZZ;
               normal[2] = XY*YZ - XZ*YY;
              }

             if( fabs(Dy) == Dmax )
              {
               normal[0] = XZ*YZ - XY*ZZ;
               normal[1] = Dy;
               normal[2] = XY*XZ - YZ*XX;
              }

             if( fabs(Dz) == Dmax )
              {
               normal[0] = XY*YZ - XZ*YY;
               normal[1] = XY*XZ - YZ*XX;
               normal[2] = Dz;
              }

            ::math::linear::vector::scale( plane.origin(), scalar_type(1)/scalar_type(cloud.size()), center );
             plane.normal() = normal;

             return true;
            }

       };

      template
       <
        typename scalar_name = double
       >
       bool fit
        (
         ::math::geometry::plane::no3d<scalar_name>                         & abcd
         , std::vector< ::math::linear::vector::point<scalar_name,3> > const& cloud
        )
        {
          return ::math::geometry::plane::fit3D<scalar_name>::process( abcd, cloud );
        }

     }
   }
 }

#endif

