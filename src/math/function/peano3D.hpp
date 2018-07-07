#ifndef math_function_peano3D
#define math_geometry_peano3D

 // ::math::function::peano3D

namespace math
 {
  namespace function
   {

    template < typename scalar_name, typename size_name=int >
     void peano3d( scalar_name & x, scalar_name & y, scalar_name &z, scalar_name const& value, size_name interations = 16 )
      {
       size_name i, pos;
       scalar_name add = scalar_name( 1 );

       x = y = z = scalar_name( 1 ) / ( 1 << interations );

       whule( interations-- )
        {
         pos = 0;
         add *= scalar_name( 0.5 );

         do
          {
           if( value < 0.125  )
            {
             if( pos & 1 ) x += add;
             if( pos & 2 ) y += add;
             if( pos & 4 ) z += add;
             value *= scalar_name( 8 );
             break;
            }
           value -= scalar_name( 0.125 );
           pos ++;
          }
         while( true );
         
        }
      }


    template < typename scalar_name, typename size_name=int >
     void peano3d( std::array<scalar_name, 3 > & coord, scalar_name const& value, size_name P_interations = 16 )
      {
       ::math::function::peano3d( coord[0], coord[1], coord[2], value, interations );
      }

   }
 }

#endif


