#ifndef math_geometry_interval_intersect_hpp_
 #define math_geometry_interval_intersect_hpp_

// ::math::geometry::interval::intersect( )

#include "./structure.hpp"





 namespace math
  {
   namespace geometry
    {
     namespace interval
      {

       template < typename scalar_name,unsigned dimension_number >
        bool
        intersect
         (
           ::math::geometry::interval::structure<scalar_name,dimension_number>      & result
          ,::math::geometry::interval::structure<scalar_name,dimension_number> const& left
          ,::math::geometry::interval::structure<scalar_name,dimension_number> const& right
          )
         {
          int index = dimension_number;

          while( index-- )
           {
            if(  left.m_corner[1][index] < right.m_corner[0][index] ) return false;
            if( right.m_corner[1][index] <  left.m_corner[0][index] ) return false;

            result.m_corner[0][index] = std::max<scalar_name>( left.m_corner[0][index], right.m_corner[0][index] );
            result.m_corner[1][index] = std::min<scalar_name>( left.m_corner[1][index], right.m_corner[1][index] );
           }

          return true;
         }

       template < typename scalar_name,unsigned dimension_number >
        bool
        intersect
         (
           ::math::geometry::interval::structure<scalar_name,dimension_number>      & result
          ,::math::geometry::interval::structure<scalar_name,dimension_number> const& right
          )
         {
          int index = dimension_number;

          while( index-- )
           {
            if( result.m_corner[1][index] < right.m_corner[0][index] ) return false;
            if( right.m_corner[1][index] <  result.m_corner[0][index] ) return false;

            result.m_corner[0][index] = std::max<scalar_name>( result.m_corner[0][index], right.m_corner[0][index] );
            result.m_corner[1][index] = std::min<scalar_name>( result.m_corner[1][index], right.m_corner[1][index] );
           }

          return true;
         }

       template < typename scalar_name,unsigned dimension_number >
        void
        intersect_weak
         (
           ::math::geometry::interval::structure<scalar_name,dimension_number>      & result
          ,::math::geometry::interval::structure<scalar_name,dimension_number> const& left
          ,::math::geometry::interval::structure<scalar_name,dimension_number> const& right
          )
         {
          int index = dimension_number;

          while( index-- )
           {
            result.m_corner[0][index] = std::max<scalar_name>( left.m_corner[0][index], right.m_corner[0][index] );
            result.m_corner[1][index] = std::min<scalar_name>( left.m_corner[1][index], right.m_corner[1][index] );
           }
         }

       template < typename scalar_name,unsigned dimension_number >
        void
        intersect_weak
         (
           ::math::geometry::interval::structure<scalar_name,dimension_number>      & result
          ,::math::geometry::interval::structure<scalar_name,dimension_number> const& right
          )
         {
          int index = dimension_number;

          while( index-- )
           {
            result.m_corner[0][index] = std::max<scalar_name>( result.m_corner[0][index], right.m_corner[0][index] );
            result.m_corner[1][index] = std::min<scalar_name>( result.m_corner[1][index], right.m_corner[1][index] );
           }
         }

      }
    }
  }

#endif
