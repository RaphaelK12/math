#ifndef Dh_math_geometry_circle_construct
 #define Dh_math_geometry_circle_construct

// ::math::geometry::circle::construct<scalar_name>( first, second, third )

#include  "./simple.hpp"
#include  "../direction/bisector.hpp"
#include  "../direction/intersect.hpp"
#include  "../../linear/vector/distance.hpp"

 namespace math
  {
   namespace geometry
    {
     namespace circle
      {

       template
        <
          typename scalar_name
        >
        bool construct
         (
           ::math::geometry::circle::simple<scalar_name,2>          & result
          ,::math::linear::vector::point<scalar_name,2>        const& first
          ,::math::linear::vector::point<scalar_name,2>        const& second
          ,::math::linear::vector::point<scalar_name,2>        const& third
         )
         {
          auto bisector_first = ::math::geometry::direction::bisector( first, second );
          auto bisector_secnd = ::math::geometry::direction::bisector( first, third );
          auto bisector_third = ::math::geometry::direction::bisector( second, third );

          ::math::linear::vector::point<  scalar_name, 2 > center;
          if( false == ::math::geometry::direction::intersect( center, bisector_first, bisector_third ) )
           {
            return false;
           }

           auto radius = ::math::linear::vector::distance( center, first );
           result = ::math::geometry::circle::simple<scalar_name,2>{ center, radius };
           return true;
         }



      }
    }
  }

#endif
