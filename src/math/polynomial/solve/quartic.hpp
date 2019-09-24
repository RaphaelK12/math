#ifndef math_polynomial_solve_quartic_HPP_
 #define math_polynomial_solve_quartic_HPP_

#include <array>

#include "./quadric.hpp"
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
          unsigned bi( scalar_name root[4], scalar_name const coefficient[3], scalar_name const& epsilon = 1e-12 )
           {
            unsigned count = 0;
            scalar_name r2[2];
            root[3]=root[2]=root[1]=root[0]=NAN;
            switch( math::polynomial::solve::quadric::full( r2, coefficient, epsilon ) )
             {
              case( 2 ):
               {
                if( r2[1] < -epsilon ) { goto case_1; }
                if( r2[1] <  epsilon ) {  root[count++] = 0; }
                if( epsilon < r2[1] )
                 {
                  root[count++] = - sqrt( r2[1] );
                  root[count++] = + sqrt( r2[1] );
                 }
               }// break for no one
              case( 1 ):
               {
                case_1:
                if( r2[0] < -epsilon ) { goto case_0; }
                if( r2[0] < epsilon ) {root[count++] = 0; }
                if( epsilon < r2[0] )
                 {
                  root[count++] = - sqrt( r2[0] );
                  root[count++] = + sqrt( r2[0] );
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
        unsigned depressed( scalar_name root[4], scalar_name const coefficient[3], scalar_name const& epsilon = 1e-12 )
         {  // [0] + [1] * x + [2] * x ^2 + 0.0. * x^3 +  1.0 * x^4
          scalar_name const& p = coefficient[2];
          scalar_name const& q = coefficient[1];
          scalar_name const& r = coefficient[0];

          if( ( -epsilon < q ) && ( q < epsilon ) )
           {
            scalar_name biC[3]={ r, p, 1 };
            return math::polynomial::solve::quartic::bi( root, biC, epsilon );
           }

          scalar_name resolventC[ 4 ]={ -q*q, 2*p*p-scalar_name(8)*r, scalar_name(8)*p, scalar_name(8) };
          scalar_name resultC[ 3 ];
          unsigned countC = ::math::polynomial::solve::cubic::full( resultC, resolventC, epsilon );
          if( 0 == countC )
           { // Impossible!!!
            return 0;
           }

          scalar_name const& m = resultC[countC-1];
          if( m < - epsilon  )
           {
            return 0;
           }

          if( m < epsilon  )
           {
            return 0;
           }

          unsigned count=0;

          scalar_name quadCa[2]={ scalar_name( p/2 + m - q/( 2 * sqrt( 2*m ) ) ), scalar_name(  sqrt( 2 * m ) ) }; count  = ::math::polynomial::solve::quadric::monic( root,       quadCa, epsilon );
          scalar_name quadCb[2]={ scalar_name( p/2 + m + q/( 2 * sqrt( 2*m ) ) ), scalar_name( -sqrt( 2 * m ) ) }; count += ::math::polynomial::solve::quadric::monic( root+count, quadCb, epsilon );

          switch( count )
           {
            case(4):
              if( root[1] < root[0] )std::swap( root[0], root[1] );
              if( root[2] < root[1] )std::swap( root[1], root[2] );
              if( root[3] < root[2] )std::swap( root[2], root[3] );
            case(3):
              if( root[1] < root[0] )std::swap( root[0], root[1] );
              if( root[2] < root[1] )std::swap( root[1], root[2] );
            case(2): if( root[1] < root[0] )std::swap( root[0], root[1] );
            case(1): break;
           }

          return count;
         }

       template
        <
          typename scalar_name
        >
        unsigned full( scalar_name root[4], scalar_name const coefficient[5], scalar_name const& epsilon = 1e-12 )
         {
          if( ( -epsilon < coefficient[4] ) && ( coefficient[4] < epsilon ) )
           {
            return math::polynomial::solve::cubic::full( root, coefficient, epsilon );
           }

          if( ( -epsilon < coefficient[0] ) && ( coefficient[0] < epsilon ) )
           {
            root[ 0 ] = 0;
            return 1 + ::math::polynomial::solve::cubic::full( root+1, coefficient+1, epsilon );
           }

          if(    ( ( -epsilon < coefficient[1] ) && ( coefficient[1] < epsilon ) )
              && ( ( -epsilon < coefficient[3] ) && ( coefficient[3] < epsilon ) )
            )
           {
            scalar_name c2[3]={coefficient[0], coefficient[2], coefficient[4] };
            return ::math::polynomial::solve::quartic::bi( root, c2, epsilon );
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
          switch( count = ::math::polynomial::solve::quartic::depressed( root, depressedC, epsilon ) )
           {
            case( 4 ): root[3] += substitution;
            case( 3 ): root[2] += substitution;
            case( 2 ): root[1] += substitution;
            case( 1 ): root[0] += substitution;
           }
          return count;
         }


       template
        <
          typename scalar_name
        >
        unsigned full( std::array<scalar_name,4> & root, std::array<scalar_name,5> const& coefficient, scalar_name const& epsilon = 1e-12 )
         {
          return ::math::polynomial::solve::quartic::full<scalar_name>( root.data(), coefficient.data(), epsilon );
         }

       template
        <
          typename scalar_name
        > // expect monic polynom
        unsigned ferrari( scalar_name root[4], scalar_name const coefficient[4], scalar_name const& epsilon = 1e-12 )
         {
          scalar_name const& B = coefficient[3];
          scalar_name const& C = coefficient[2];
          scalar_name const& D = coefficient[1];
          scalar_name const& E = coefficient[0];

          return 0;
         }

       template
        <
          typename scalar_name
        > // expect monic polynom
        unsigned shmakov( scalar_name root[4], scalar_name const coefficient[4], scalar_name const& epsilon = 1e-12 )
         {
          root[0] = root[1] = root[2] = root[3] = NAN;
          scalar_name const& A = coefficient[3];
          scalar_name const& B = coefficient[2];
          scalar_name const& C = coefficient[1];
          scalar_name const& D = coefficient[0];

          scalar_name y;
           {
            std::array<scalar_name,4> resolventC={ -A*A*D - C*C + 4*B*D, A * C - 4 * D, scalar_name(-1)*B, scalar_name(1) };
            std::array<scalar_name,3> resultC;
            unsigned countC = ::math::polynomial::solve::cubic::full( resultC.data(), resolventC.data(), epsilon );
            y = resultC[ 0 ];
            auto z = ::math::polynomial::evaluate( y, resolventC );
            y = y;
           }

          unsigned count=0;
          unsigned count_real=0;
          std::array<scalar_name,2> g;
          switch( ::math::polynomial::solve::quadric::monic( g.data(),  B-y, -A ) )
           {
            case(0) : return 0;
            case(1) : g[1] = g[0]; count = 2; count_real += 1; break;
            case(2) :              count = 2; count_real += 2; break;
           }

          std::array<scalar_name,2> h;
          switch( ::math::polynomial::solve::quadric::monic( h.data(),    D, -y ) )
           {
            case(0) : return 0;
            case(1) : h[1] = h[0]; count = 4; count_real +=1;  break;
            case(2) :              count = 4; count_real +=2;  break;
           }

          if( 4 != count )
           {
            return 0;
           }

          count = ::math::polynomial::solve::quadric::monic(  root,       h[0], g[0] );
          if( 2 == count_real )
           {
            return count;
           }

          count += ::math::polynomial::solve::quadric::monic( root+count, h[1], g[1] );

          switch( count )
           {
            case(4):
              if( root[1] < root[0] )std::swap( root[0], root[1] );
              if( root[2] < root[1] )std::swap( root[1], root[2] );
              if( root[3] < root[2] )std::swap( root[2], root[3] );
            case(3):
              if( root[1] < root[0] )std::swap( root[0], root[1] );
              if( root[2] < root[1] )std::swap( root[1], root[2] );
            case(2): if( root[1] < root[0] )std::swap( root[0], root[1] );
            case(1): break;
           }

          return count;
         }

       template
         <
         typename scalar_name
         >
         scalar_name depressing( std::array<scalar_name,5> & result, std::array<scalar_name,5> const coefficient, scalar_name const& epsilon = 1e-12 )
          {
           scalar_name shift = NAN;

           auto &A  = coefficient[4];
           auto &B  = coefficient[3];
           auto &C  = coefficient[2];
           auto &D  = coefficient[1];
           auto &E  = coefficient[0];

           if( ( -epsilon < shift ) && ( shift < epsilon ) ) return shift;

           shift =   -B/( 4 * A );
           result[4] = A;
           result[3] = 0;
           result[2] = -3 * B*B/( 8*A) + C;
           result[1] = B*B*B/( 8 * A*A ) +( - B*C/(2*A) ) + D ;
           result[0] = E + ( - B*D/( 4*A )) + B*B*C/( 16 *A*A ) +( - 3 *B*B*B*B/ ( 256*A*A*A ) );

           return -shift;
          }


        }
      }
    }
  }

#endif
