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

             point_type C={0,0,0};

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
               C[0] += point[0]; C[1] += point[1]; C[2] += point[2];
              }

             XX /= cloud.size();
             XY /= cloud.size();
             XZ /= cloud.size();
             YY /= cloud.size();
             YZ /= cloud.size();
             ZZ /= cloud.size();
             C[0] /= cloud.size(); C[1] /= cloud.size(); C[2] /= cloud.size();

             scalar_type const& X = C[0];
             scalar_type const& Y = C[1];
             scalar_type const& Z = C[2];

             //::math::linear::matrix::structure<scalar_type,3,3> CV;
             //CV[0][0] = XX;    CV[1][0] = XY;  CV[2][0] = XZ;
             //CV[0][1] = XY;    CV[1][1] = YY;  CV[2][1] = YZ;
             //CV[0][2] = XZ;    CV[1][2] = YZ;  CV[2][2] = ZZ;
             //scalar_type detCV = ::math::linear::matrix::determinant( CV );

             ::math::linear::matrix::structure<scalar_type,3,3> Mz, Miz;
             Mz[0][0] = XX;    Mz[1][0] = XY;    Mz[2][0] = X;
             Mz[0][1] = XY;    Mz[1][1] = YY;    Mz[2][1] = Y;
             Mz[0][2] = X;     Mz[1][2] = Y;     Mz[2][2] = 1;
             scalar_type detZ = ::math::linear::matrix::determinant( Mz );

             ::math::linear::matrix::structure<scalar_type,3,3> Mx, Mix;
             Mx[0][0] = YY;    Mx[1][0] = YZ;    Mx[2][0] = Y;
             Mx[0][1] = YZ;    Mx[1][1] = ZZ;    Mx[2][1] = Z;
             Mx[0][2] = Y;     Mx[1][2] =  Z;    Mx[2][2] = 1;
             scalar_type detX = ::math::linear::matrix::determinant( Mx );

             ::math::linear::matrix::structure<scalar_type,3,3> My, Miy;
             My[0][0] = XX;    My[1][0] = XZ;    My[2][0] = X;
             My[0][1] = XZ;    My[1][1] = ZZ;    My[2][1] = Z;
             My[0][2] = X;     My[1][2] =  Z;    My[2][2] = 1;
             scalar_type detY = ::math::linear::matrix::determinant( My );

             scalar_type const Dmax = std::max( std::max( fabs(detX), fabs(detY) ), fabs(detZ) );
             if( Dmax < epsilon )
              {
               return false;
              }

             point_type normal;

             if( fabs(detX) == Dmax )
              {
               ::math::linear::matrix::invert( Mix, Mx );
               point_type free={ X, XY, XZ };
               point_type tmp;
               ::math::linear::matrix::transform( tmp, Mix, free );
               normal[0] = 1;
               normal[1] = +tmp[1];
               normal[2] = -tmp[2];
             }

             if( fabs(detY) == Dmax )
              {
               ::math::linear::matrix::invert( Miy, My );
               point_type free={ XY, Y, YZ };
               point_type tmp;
               ::math::linear::matrix::transform( tmp, Miy, free );
               normal[0] = +tmp[0];
               normal[1] = 1;
               normal[2] = -tmp[2];
             }

             if( fabs(detZ) == Dmax )
              {
               ::math::linear::matrix::invert( Miz, Mz );
               point_type free={ XZ, YZ, Z };
               point_type tmp;
               ::math::linear::matrix::transform( tmp, Miz, free );
               normal[0] = -tmp[0];
               normal[1] = -tmp[1];
               normal[2] = 1;
             }

            ::math::linear::vector::scale( plane.origin(), scalar_type(1)/scalar_type(cloud.size()), C );
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

