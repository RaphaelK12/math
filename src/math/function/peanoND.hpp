#ifndef math_function_peanoND
#define math_geometry_peanoND

 // ::math::function::peanoND

namespace math
 {
  namespace function
   {

    template < typename scalar_name, unsigned dimension_number, typename size_name =int >
     void peanoNd( std::array<scalar_name,dimension_number> & coord, scalar_name const& value, size_name iteration=16 )
      {
       int i, pos, _d;

       scalar_name add = scalar_name( 1 );
       scalar_name sub = scalar_name( 1 )/( 1 << dimension_number );
       scalar_name mul = 1 << dimension_number;

       for( i=0; i< dimension_number; ++i )
        coord[ _d ] = scalar_name( 1 )/( 1 << iteration );

      for( i=0; i < iteration; ++i )
       {
        pos = 0;
        add *= 0.5;

        do
         {
          if( value < sub )
           {
            _d = dimension_number;
            while( _d-- )
             if( pos & ( 1 << _d ) )
              coord[ _d ] += add;

            value *=  mul;
            break;
           }
          value -= sub; pos ++;
         }
        while( 0.0 < value );
       }
     }
   }
 }

#endif
