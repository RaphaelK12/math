#ifndef math_function_peano2D
#define math_geometry_peano2D

 // ::math::function::peano2D

namespace math
 {
  namespace function
   {

    template< typename scalar_name >
     inline void peano2D( scalar_name & x, scalar_name &y, scalar_name P_value, int P_interations = 16 )
      {
       scalar_name add = scalar_name( 1 );

       x = y = scalar_name( 1 ) / ( 1 << P_interations );

       while( P_interations-- )
        {
         add *= scalar_name( 0.5 );
         if( P_value < scalar_name( 0.25 )  )    /*1*/
          {
           //x += scalar_name( 0 );
           //y += scalar_name( 0 );
           P_value *= scalar_name( 4 );
           continue;
          }

         if( P_value < scalar_name( 0.5 ) )      /*2*/
          {
           x += add;
           //y += scalar_name( 0 );

           P_value = ( P_value-scalar_name( 0.25 ) ) * scalar_name( 4 );
           continue;
          }

         if( P_value < scalar_name( 0.75 ) )        /*3*/
          {
           //x += scalar_name( 0 );
           y += add;
           P_value = (P_value- scalar_name( 0.5 ) )* scalar_name( 4 );
           continue;
          }

         x += add;        /*4*/
         y += add;
         P_value = ( P_value - scalar_name( 0.75 ) ) * scalar_name( 4 );
         continue;
        }
      }

    template < typename scalar_name, typename size_name=int >
     void peano2d( std::array<scalar_name, 2 > & coord, scalar_name const& value, size_name P_interations = 16 )
      {
       ::math::function::peano3d( coord[0], coord[1], value, interations );
      }


   }
 }

#endif



