#ifndef math_polynomial_solve_cubic_HPP_
 #define math_polynomial_solve_cubic_HPP_

 // ::math::polynomial::solve::cubic<scalar_name>( result, coefficient, epsilon = 1e-6 )

#include <cmath>
#include "./quadric.hpp"
#include "../../geometry/deg2rad.hpp"



 namespace math
  {
   namespace polynomial
    {
     namespace solve
      {
       namespace cubic
        {

         /*
         - 2 - first two solutions are equal
         - 3 - all solutions are equal
         */
         template
          <
            typename scalar_name
          > // copy paste from gsl_poly_solve_cubic
          int full( scalar_name result[3], scalar_name const coefficient[4], scalar_name const& epsilon = 1e-12 )
           {
            if( ( -epsilon < coefficient[3] ) && ( coefficient[3] < epsilon ) )
             {
              return ::math::polynomial::solve::quadric::full( result, coefficient, epsilon );
             }

            if( ( -epsilon < coefficient[0] ) && ( coefficient[0] < epsilon ) )
             {
              scalar_name r2[2];
              switch( ::math::polynomial::solve::quadric::full( r2, coefficient+1, epsilon ) )
               {
                case( 0 ):
                  {
                   result[0] = 0; result[1] = result[2] = NAN;
                   return 1;
                  }
                case( 1 ):
                 {
                  result[0] = std::min<scalar_name>( 0, r2[0] );
                  result[1] = std::max<scalar_name>( 0, r2[0] );
                  result[2] = NAN;
                  return 2;
                 }

                case( 2 ):
                 {
                  result[0] = 0;
                  result[1] = r2[0];
                  result[2] = r2[1];
                  if( result[1] < result[0]){ std::swap( result[1] , result[0] ); }
                  if( result[2] < result[1]){ std::swap( result[2] , result[1] ); }
                  if( result[1] < result[0]){ std::swap( result[1] , result[0] ); }
                  return 3;
                 }
               }
              result[0] = result[1] = result[2] = NAN;
              return 0;
             }

            scalar_name a = coefficient[2] /coefficient[3];
            scalar_name b = coefficient[1] /coefficient[3];
            scalar_name c = coefficient[0] /coefficient[3];

            scalar_name q = (a * a - 3 * b);
            scalar_name r = (2 * a * a * a - 9 * a * b + 27 * c);

            scalar_name Q = q / 9;
            scalar_name R = r / 54;

            scalar_name Q3 = Q * Q * Q;
            scalar_name R2 = R * R;

            scalar_name CR2 = 729 * r * r;
            scalar_name CQ3 = 2916 * q * q * q;

            if (R == 0 && Q == 0)
             {
              result[0] = - a / scalar_name(3);
              result[1] = result[0];
              result[2] = result[0];
              result[1] =result[2] = result[3] = NAN;
              return 1;
             }
            else if( fabs( CR2 - CQ3 ) < epsilon )
             {
              scalar_name sqrtQ = sqrt (Q);

              if (R > 0)
               {
                result[0] = -scalar_name(2) * sqrtQ  - a / scalar_name(3);
                result[1] = sqrtQ - a / scalar_name(3);
                result[2] = result[1];
                result[2] = NAN;
                return 2;
               }
              else
               {
                result[0] =   - sqrtQ - a / scalar_name(3);
                result[1] = 2 * sqrtQ - a / scalar_name(3);
                result[2] = NAN;
                return 2;
               }
             }
            else if (R2 < Q3)
             {
              scalar_name sgnR = scalar_name(R >= 0 ? 1 : -1);
              scalar_name ratio = sgnR * sqrt (R2 / Q3);
              scalar_name theta = acos (ratio);
              scalar_name norm = -scalar_name(2) * sqrt (Q);
              result[0] =scalar_name( norm * cos (theta / 3) - a / 3 );
              result[1] =scalar_name( norm * cos ((theta + ::math::geometry::deg2rad( 360.0 ) ) / scalar_name(3)) - a / scalar_name(3) );
              result[2] =scalar_name( norm * cos ((theta - ::math::geometry::deg2rad( 360.0 ) ) / scalar_name(3)) - a / scalar_name(3) );

              /* Sort result[x] into increasing order */

              if( result[1] < result[0] )
               {
                std::swap( result[0], result[1] );
               }

              if( result[2] < result[1] )
               {
                std::swap( result[1], result[2] );

                if (result[0] > result[1] )
                 {
                  std::swap( result[0], result[1] );
                 }
               }

              return 3;
             }
            else
             {
              scalar_name sgnR = scalar_name(R >= 0 ? 1 : -1);
              scalar_name A = -sgnR * pow (fabs (R) + sqrt (R2 - Q3), scalar_name(1)/scalar_name(3));
              scalar_name B = Q / A ;
              result[0] = A + B - a / scalar_name(3);
              result[1] = result[2] = NAN;
              return 1;
             }
          }

         template
          <
            typename scalar_name
          >
          int full( std::array<scalar_name,3> & result, std::array<scalar_name,4> const coefficient, scalar_name const& epsilon = 1e-12 )
           {
            return ::math::polynomial::solve::cubic::full<scalar_name>( result.data(), coefficient.data(), epsilon );
           }

         template
          <
            typename scalar_name
          >    //    [0] + [1] *x + [2] * x^2+ [3] * x^3  = 0
           scalar_name depressing( std::array<scalar_name,4> & result, std::array<scalar_name,4> const coefficient, scalar_name const& epsilon = 1e-12 )
           {
            scalar_name shift = NAN;

            auto &A  = coefficient[3];
            auto &B  = coefficient[2];
            auto &C  = coefficient[1];
            auto &D  = coefficient[0];

            if( ( -epsilon < shift ) && ( shift < epsilon ) ) return shift;

            shift =   -B/( 3 * A );
                       result[3] = coefficient[3];
                       result[2] = 0;
            auto &p  = result[1];
            auto &q  = result[0];

            p = C + B * shift ;
            q = D + (scalar_name(2)/scalar_name(3))* B*shift*shift   + C * shift ;

            return -shift;
           }

      //   template
      //    <
      //      typename scalar_name
      //    >
      //    int depressed( std::array<scalar_name,3> & result, std::array<scalar_name,2> const coefficient, scalar_name const& epsilon = 1e-12 )
      //     { // todo
      //      int type = 0;
      //      auto const& q = coefficient[0];
      //      auto const& p = coefficient[1];
      //      auto const& a = coefficient[2];
      //
      //      scalar_name d = pow(q/scalar_name(2),2) + cbr(p/scalar_name(3),3);
      //
      //      if( epsilon < d )
      //       {
      //        d = sqrt( d );
      //        result[0] = cbrt( -q/scalar_name(2) - d ) + cbrt( -q/scalar_name(2) + d );
      //        return 1;
      //       }
      //
      //      if( d < epsilon )
      //       {
      //
      //        return 3;
      //       }
      //
      //
      //       {
      //        result[0] = cbrt( -q/scalar_name(2) ) + cbrt( -q/scalar_name(2) );
      //        result[1] = -result[0];
      //
      //        return 2;
      //       }
      //
      //      return 0;
      //     }
      //
      //
        }
      }
    }
  }

#endif
