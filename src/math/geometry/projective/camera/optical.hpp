#ifndef math_geometry_projective_camera_optical
#define math_geometry_projective_camera_optical

// ::math::geometry::projective::camera::optical<scalar_name, size_name, integer_name>

#include <cmath>
#include <tuple>

#include "../../../linear/vector/vector.hpp"
#include "../../../geometry/interval/interval.hpp"

#include "./d2hv.hpp"
#include "./ha2d.hpp"
#include "./ha2v.hpp"
#include "./va2d.hpp"
#include "./va2h.hpp"

namespace math
 {
  namespace geometry
   {
    namespace projective
     {
      namespace camera
       {

        template
         <
           typename  scalar_name
          ,typename    size_name = std::size_t
         >
         class optical
          {
           public:
             typedef scalar_name     scalar_type;
             typedef size_name         size_type;

             typedef ::math::linear::vector::structure< scalar_type , 2 >          uv_type;
             typedef ::math::linear::vector::structure< size_type   , 2 >  resolution_type;

             typedef ::math::geometry::interval::structure<scalar_name,2>      window_type;

             template< typename number_name >
              using vector_type = ::math::linear::vector::structure< number_name, 2 >;

             explicit optical( scalar_type const& DFoV = 2*std::atan( std::sqrt(2) ) )
              :m_resolution{ 1, 1 }
              ,m_pixelAR( 1 )
              {
               this->diagonalFV( DFoV );
              }

             optical( size_type const& width, size_type const& height, scalar_type const& DFoV = 2*std::atan( std::sqrt(2) ), scalar_type const& pAR = 1 )
              :m_resolution{ width, height }
              ,m_pixelAR( pAR )
              {
               this->diagonalFV( DFoV );
              }

             optical( resolution_type const& resolution, scalar_type const& DFoV = 2*std::atan( std::sqrt(2) ), scalar_type const& pAR = 1 )
              :m_resolution{ resolution }
              ,m_pixelAR( pAR )
              {
               this->diagonalFV( DFoV );
              }

             //!!! Qube camera([-1,-1]x[1,1]) to screen(pixel)
             template< typename number_name >
              vector_type< number_name > xy( uv_type const& uv )const
               {
                vector_type< number_name > xy;

                size_type max = std::max<size_type>( m_resolution[0], m_resolution[1] );
                size_type min = std::min<size_type>( m_resolution[0], m_resolution[1] );

                scalar_type x = uv[0];
                scalar_type y = uv[1];

                x  /= tan( m_maxFV / 2 );
                y  /= tan( m_maxFV / 2 );

                x  += scalar_type(1);
                y  += scalar_type(1);

                x  *= max;
                y  *= max;

                x  -= max - m_resolution[0];
                y  -= max - m_resolution[1];

                x  /= scalar_type(2);
                y  /= scalar_type(2);

              //x  = x;
                y  = m_resolution[1] - y ;

              //x *= scalar_type(1);
                y *= m_pixelAR;

                xy[0] = number_name( x );
                xy[1] = number_name( y );

                //xy[0] = number_name(                   ( ( uv[0]/tan( m_maxFV / 2 ) + scalar_type(1) )*max - ( max - m_resolution[0]) ) / scalar_type(2) );
                //xy[1] = number_name( m_resolution[1] - ( ( uv[1]/tan( m_maxFV / 2 ) + scalar_type(1) )*max - ( max - m_resolution[1]) ) / scalar_type(2) );

                return xy;
               }

              //!!! Screen(pixel) to qube camera([-1,-1]x[1,1])
              template< typename number_name >
               uv_type uv( vector_type< number_name > const& xy )const
                {
                 uv_type result;
                 scalar_type max = scalar_type( std::max<size_type>( m_resolution[0], m_resolution[1] ) );
                 scalar_type min = scalar_type( std::min<size_type>( m_resolution[0], m_resolution[1] ) );

                 scalar_type & u = result[0];
                 scalar_type & v = result[1];

                 u = scalar_type( xy[0] );
                 v = scalar_type( xy[1] );

               //u /= scalar_type(1);
                 v /= m_pixelAR ;

               //u = u;
                 v = m_resolution[1] - v;

                 u *= scalar_type(2);
                 v *= scalar_type(2);

                 u += max-m_resolution[0];
                 v += max-m_resolution[1];

                 u /= max;
                 v /= max;

                 u -= scalar_type(1);
                 v -= scalar_type(1);

                 u *= tan( m_maxFV / 2 );
                 v *= tan( m_maxFV / 2 );

                 //result[0] = scalar_type( ( scalar_type(2)*(                  xy[0] ) + (max-m_resolution[0]) ) / max - scalar_type(1) );
                 //result[1] = scalar_type( ( scalar_type(2)*( m_resolution[1]- xy[1] ) + (max-m_resolution[1]) ) / max - scalar_type(1) );
                 //result[0] *= tan( m_maxFV / 2 );
                 //result[1] *= tan( m_maxFV / 2 );

                 return result;
                }

           public:
             scalar_type const& diagonalFV()const
              {
               return this->m_diagonalFV;
              }
             void diagonalFV( scalar_type const& DFoV )
              {
               m_diagonalFV = DFoV;
               std::tie( this->m_horizontalFV, this->m_verticalFV ) = ::math::geometry::projective::camera::d2hv<scalar_type>( DFoV, scalar_type( this->m_resolution[0] ), scalar_type( this->m_resolution[1] ) ) ;
               m_maxFV = std::max( this->m_horizontalFV, this->m_verticalFV );
              }
           private:
             scalar_type     m_diagonalFV;

           public:
             scalar_type const& horizontalFV()const{ return this->m_horizontalFV; }
             void horizontalFV( scalar_type const& fv )
              {
               m_horizontalFV = fv;
               m_diagonalFV = ::math::geometry::projective::camera::ha2d<scalar_type>( m_horizontalFV, m_resolution[0]/(scalar_type)m_resolution[1] );
               m_verticalFV = ::math::geometry::projective::camera::ha2v<scalar_type>( m_horizontalFV, m_resolution[0]/(scalar_type)m_resolution[1] );
               m_maxFV = std::max( m_horizontalFV, m_verticalFV );
              }
           private:
             scalar_type     m_horizontalFV;

           public:
             scalar_type const& verticalFV()const{ return m_verticalFV; }
             void verticalFV( scalar_type const& fv )
              {
               m_verticalFV = fv;
               m_diagonalFV = ::math::geometry::projective::camera::va2d<scalar_type>( m_verticalFV, m_resolution[0]/(scalar_type)m_resolution[1] );
               m_verticalFV = ::math::geometry::projective::camera::va2h<scalar_type>( m_verticalFV, m_resolution[0]/(scalar_type)m_resolution[1] );
               m_maxFV = std::max( m_horizontalFV, m_verticalFV );
              }
           private:
             scalar_type     m_verticalFV;

           private:
             scalar_type     m_maxFV;

           public:
             window_type window()const
              {
               window_type result;
               result[1][0] = tan( this->horizontalFV() / scalar_type(2) );  result[0][0] = -result[1][0];
               result[1][1] = tan( this->verticalFV() / scalar_type(2) );    result[0][1] = -result[1][1];
               return result;
              }
           public:
             resolution_type const& resolution()const{ return m_resolution; }
             void resolution( size_type const& width, size_type const& height )
              {
               this->resolution( resolution_type{ width, height } );
              }

             void resolution( resolution_type const& resolution )
              {
               this->m_resolution = resolution;
               this->diagonalFV( m_diagonalFV );
              }
           private:
             resolution_type m_resolution;

           public:
             scalar_type const& pixelAR()const{ return m_pixelAR; }
             void pixelAR( scalar_type const& pAR )
              {
               m_pixelAR = pAR;
              }
           private:
             scalar_type     m_pixelAR;
          };

       }
     }
   }
 }

#endif
