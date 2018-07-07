#ifndef math_geometry_interval_structure_hpp_
 #define math_geometry_interval_structure_hpp_

// ::math::geometry::interval::structure<scalar_name,dimension_number>

#include <array>

#include "../../linear/vector/structure.hpp"



 namespace math
  {
   namespace geometry
    {
     namespace interval
      {

       template
        <
          typename scalar_name
         ,unsigned dimension_number
        >
       struct structure
        {
         public:
           typedef ::math::linear::vector::point<scalar_name, dimension_number > point_type;

           structure() {}
           structure( point_type const& first, point_type const& second ):m_corner{ first, second }{}

           point_type const& operator[]( unsigned const index )const{ return m_corner[index]; }
           point_type      & operator[]( unsigned const index )     { return m_corner[index]; }

           point_type const& corner( unsigned const index )const{ return m_corner[index]; }
           point_type      & corner( unsigned const index )     { return m_corner[index]; }

         public:
           point_type m_corner[2];
        };

      }
    }
  }

#endif
