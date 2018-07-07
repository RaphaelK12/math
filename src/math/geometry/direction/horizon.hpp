#ifndef math_geometry_direction_horizon
#define math_geometry_direction_horizon

 // ::math::geometry::direction::horizon::process( 00, 01, 11, 10 )

#include "../../linear/vector/structure.hpp"
#include "../../linear/vector/cross.hpp"
#include "./abc.hpp"


namespace math
 {
  namespace geometry
   {
    namespace direction
     {

      template< typename scalar_name = double >
       struct horizon
        {
         public:
           typedef scalar_name scalar_type;

           typedef ::math::linear::vector::point< scalar_type, 2 >           point_type;
           typedef ::math::linear::vector::point< scalar_type, 3 >     homogeneous_type;
           typedef ::math::geometry::direction::ABC2D<scalar_name>            line_type;

           /*
             a3 -l23 --a2 (up)
             |         |
            l30(left) l12(right)
             |         |
             a0--l01---a1 (down)
           */
           void process
            (
              point_type   const & a0 //!< (0,0) point
             ,point_type   const & a1 //!< (1,0) point
             ,point_type   const & a2 //!< (1,1) point
             ,point_type   const & a3 //!< (0,1) point
            )
            {
             ::math::linear::vector::cross( m_l01, homogeneous_type{ a0[0], a0[1], 1 }, homogeneous_type{ a1[0], a1[1], 1 } );
             ::math::linear::vector::cross( m_l12, homogeneous_type{ a1[0], a1[1], 1 }, homogeneous_type{ a2[0], a2[1], 1 } );
             ::math::linear::vector::cross( m_l23, homogeneous_type{ a2[0], a2[1], 1 }, homogeneous_type{ a3[0], a3[1], 1 } );
             ::math::linear::vector::cross( m_l30, homogeneous_type{ a3[0], a3[1], 1 }, homogeneous_type{ a0[0], a0[1], 1 } );

             ::math::linear::vector::cross( m_p30_12, m_l30, m_l12 );
             ::math::linear::vector::cross( m_p01_23, m_l01, m_l23 );

             ::math::linear::vector::cross( m_line, m_p30_12, m_p01_23 );
            }

           /*
             a3 -l23 --a2 (up)
             |         |
            l30(left) l12(right)
             |         |
             a0--l01---a1 (down)
           */
           void process
            (
              line_type   const & left     //!< sdasd
             ,line_type   const & right    //!< sdasd
             ,line_type   const & down     //!< sdasd
             ,line_type   const & up       //!< sdasd
            )
            {
             ::math::linear::vector::cross( m_p30_12, homogeneous_type{ left[0] , left[1], left[2] }, homogeneous_type{ right[0] , right[1], right[2] } );
             ::math::linear::vector::cross( m_p01_23, homogeneous_type{ down[0] , down[1], down[2] }, homogeneous_type{    up[0] ,    up[1],    up[2] } );

             ::math::linear::vector::cross( m_line, m_p30_12, m_p01_23 );
            }

         public:
           homogeneous_type const& line()const  { return m_line; }
           homogeneous_type const& first()const { return m_p30_12; }
           homogeneous_type const& second()const{ return m_p01_23; }

         private:
           homogeneous_type   m_line, m_l01, m_l12, m_l23, m_l30;
           homogeneous_type   m_p30_12, m_p01_23;
        };

     }
   }
 }

#endif


