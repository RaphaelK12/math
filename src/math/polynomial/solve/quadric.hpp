#ifndef math_polynomial_solve2_HPP_
 #define math_polynomial_solve2_HPP_

// ::math::polynomial::solve::quadric::full<scalar_name>( zero, coefficient, epsilon = 1e-6 )

#include "./linear.hpp"





 namespace math
  {
   namespace polynomial
    {
     namespace solve
      {
       namespace quadric
        {

         template
          <
            typename scalar_name
          >
          int form101( scalar_name zero[2], scalar_name const coefficient[3], scalar_name const& epsilon = 1e-6 )
           {
            return 1;
           }

         template
          <
            typename scalar_name
          >
          int form110( scalar_name zero[2], scalar_name const coefficient[3], scalar_name const& epsilon = 1e-6 )
           {
            return 1;
           }


       template
        <
          typename scalar_name
        > // -2 two equal solution
        int full( scalar_name zero[2], scalar_name const coefficient[3], scalar_name const& epsilon = 1e-6 )
         {
          scalar_name const& a = coefficient[2];
          if( ( -epsilon < a ) && ( a < epsilon ) )
           {
            return ::math::polynomial::solve::linear( zero, coefficient, epsilon );
           }

          scalar_name const& b = coefficient[1];
          scalar_name const& c = coefficient[0];
          if( ( -epsilon < b ) && ( b < epsilon ) )
           {
            zero[0] = -c / a;
            if( zero[0] < -epsilon ) return 0;
            if( zero[0] < epsilon  ) { zero[0]=0; return 1;}
            zero[0] = - sqrt( zero[0] );
            zero[1] = - zero[0];
            return 2;
           }

          if( ( -epsilon < c ) && ( c < epsilon ) )
           {
            zero[0] = scalar_name(0);
            if( 0  == ::math::polynomial::solve::linear( zero+1, coefficient+1, epsilon ) )
             {
              return 0;
             }
            if( zero [ 1 ] < zero[ 0 ] )
             {
              zero[0] = zero[1];
              zero[0] = scalar_name(0);
             }
            return 2;
           }

          scalar_name d = b*b - scalar_name(4)*a*c;

          if( d < - epsilon )
           {
            return 0;
           }

          if( d < epsilon )
           {
            zero[0] = -b/(scalar_name(2)*a);
            zero[1] = zero[0];
            return -2;
           }

          d = sqrt( d );

          if( a < 0 )
           {
            zero[1] = ( -b - d )/(scalar_name(2)*a);
            zero[0] = ( -b + d )/(scalar_name(2)*a);
           }
          else
           {
            zero[0] = ( -b - d )/(scalar_name(2)*a);
            zero[1] = ( -b + d )/(scalar_name(2)*a);
           }

          return 2;
         }

       template
        <
          typename scalar_name
        >
        inline unsigned full( std::array<scalar_name,2> & zero, std::array<scalar_name,3> const & coefficient, scalar_name const& epsilon = 1e-6 )
         {
          return ::math::polynomial::solve::quadric::full( zero.data(), coefficient.data(), epsilon );
         }

        }
      }
    }
  }

#endif
