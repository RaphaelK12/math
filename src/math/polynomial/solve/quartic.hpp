#ifndef math_polynomial_solve_quartic_HPP_
 #define math_polynomial_solve_quartic_HPP_

#include <array>

#include "./cubic.hpp"
#include "../evaluate.hpp"

 // ::math::polynomial::solve::quartic::bi<scalar_name>( zero, coefficient, epsilon = 1e-6 )
 // ::math::polynomial::solve::quartic::depressed<scalar_name>( zero, coefficient, epsilon = 1e-6 )
 // ::math::polynomial::solve::quartic::full<scalar_name>( zero, coefficient, epsilon = 1e-6 )


 namespace math
  {
   namespace polynomial
    {
     namespace solve
      {
       namespace quartic
        {

       template
        <
          typename scalar_name
        >
        unsigned bi( scalar_name result[4], scalar_name const coefficient[3], scalar_name const& epsilon = 1e-12 )
         {
          unsigned count = 0;
          scalar_name r2[2];

          switch( math::polynomial::solve::quadric::full( r2, coefficient, epsilon ) )
           {
            case( 2 ):
             {
              if( r2[1] < -epsilon ) { goto case_1; }
              if( r2[1] <  epsilon ) {  result[count++] = 0; }
              if( epsilon < r2[1] )
               {
                result[count++] = - sqrt( r2[1] );
                result[count++] = + sqrt( r2[1] );
               }
             }// break for no one
            case( 1 ):
             {
              case_1:
              if( r2[0] < -epsilon ) { goto case_0; }
              if( r2[0] < epsilon ) {result[count++] = 0; }
              if( epsilon < r2[0] )
               {
                result[count++] = - sqrt( r2[0] );
                result[count++] = + sqrt( r2[0] );
               }
             }// break for no one
            case( 0 ): case_0: ;
           }
          return count;
         }

       template
        <
          typename scalar_name
        >
        unsigned depressed( scalar_name result[4], scalar_name const coefficient[3], scalar_name const& epsilon = 1e-12 )
         {
          if( ( -epsilon < coefficient[1] ) && ( coefficient[1] < epsilon ) )
           {
            scalar_name biC[3]={ coefficient[0], coefficient[2], 1 };
            return math::polynomial::solve::quartic::bi( result, biC, epsilon );
           }

          scalar_name const& p = coefficient[2];
          scalar_name const& q = coefficient[1];
          scalar_name const& r = coefficient[0];

          scalar_name resolventC[ 4 ]={ -q*q, 2*p*p-8*r, 8*p, 8 };
          scalar_name resultC[ 3 ];
          unsigned countC = ::math::polynomial::solve::cubic::full( resultC, resolventC, epsilon );
          if( 0 == countC )
           { // Impossible!!!
            return 0;
           }

          scalar_name const& m = resultC[countC-1];
          if( m < epsilon  )
           {// TODO M is zero or negative
            return 0;
           }

          unsigned count=0;

          scalar_name quadCa[3]={ p/2 + m - q/( 2 * sqrt( 2*m ) ),  sqrt( 2 * m ), scalar_name(1) }; count  = ::math::polynomial::solve::quadric::full( result,       quadCa, epsilon );
          scalar_name quadCb[3]={ p/2 + m + q/( 2 * sqrt( 2*m ) ), -sqrt( 2 * m ), scalar_name(1) }; count += ::math::polynomial::solve::quadric::full( result+count, quadCb, epsilon );

          std::array<scalar_name,5> depressedCf={ r, q, p, 0, 1 };
          ::math::polynomial::evaluate( result[0], depressedCf );

          return count;
         }

       template
        <
          typename scalar_name
        >
        unsigned full( scalar_name result[4], scalar_name const coefficient[5], scalar_name const& epsilon = 1e-12 )
         {
          if( ( -epsilon < coefficient[4] ) && ( coefficient[4] < epsilon ) )
           {
            return math::polynomial::solve::cubic::full( result, coefficient, epsilon );
           }

          if( ( -epsilon < coefficient[0] ) && ( coefficient[0] < epsilon ) )
           {
            result[ 0 ] = 0;
            return 1 + ::math::polynomial::solve::cubic::full( result+1, coefficient+1, epsilon );
           }

          if(    ( ( -epsilon < coefficient[1] ) && ( coefficient[1] < epsilon ) )
              && ( ( -epsilon < coefficient[3] ) && ( coefficient[3] < epsilon ) )
            )
           {
            scalar_name c2[3]={coefficient[0], coefficient[2], coefficient[4] };
            return ::math::polynomial::solve::quartic::bi( result, c2, epsilon );
           }

          scalar_name const& a4 = coefficient[4];
          scalar_name const& a3 = coefficient[3];
          scalar_name const& a2 = coefficient[2];
          scalar_name const& a1 = coefficient[1];
          scalar_name const& a0 = coefficient[0];

          scalar_name p = ( 8*a2*a4-3*a3*a3)/( 8*a4*a4  );
          scalar_name q = (a3*a3*a3 - 4*a2*a3*a4+8*a1*a4*a4)/(8*a4*a4*a4 );
          scalar_name r = (-3*a3*a3*a3*a3 +256*a0*a4*a4*a4 - 64*a1*a3*a4*a4 + 16*a2*a3*a3*a4)/(256*a4*a4*a4*a4);
          scalar_name depressedC[3]={ r, q, p };

          scalar_name substitution = -a3/(4*a4);
          unsigned count;
          switch( count = ::math::polynomial::solve::quartic::depressed( result, depressedC, epsilon ) )
           {
            case( 4 ): result[3] += substitution;
            case( 3 ): result[2] += substitution;
            case( 2 ): result[1] += substitution;
            case( 1 ): result[0] += substitution;
           }
          return count;
         }


       template
        <
          typename scalar_name
        >
        unsigned full( std::array<scalar_name,4> & result, std::array<scalar_name,5> const& coefficient, scalar_name const& epsilon = 1e-12 )
         {
          return ::math::polynomial::solve::quartic::full<scalar_name>( zero.data(), coefficient.data(), epsilon );
         }

        }
      }
    }
  }

#endif
