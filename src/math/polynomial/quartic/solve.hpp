#ifndef math_polynomial_quartic_solve_HPP_
 #define math_polynomial_quartic_solve_HPP_

#include <array>

#include "../quadric/solve.hpp"
#include "../cubic/solve.hpp"
#include "../evaluate.hpp"

 // ::math::polynomial::quartic::solve::bi<scalar_name>( zero, coefficient, epsilon = 1e-6 )
 // ::math::polynomial::quartic::solve::depressed<scalar_name>( zero, coefficient, epsilon = 1e-6 )
 // ::math::polynomial::quartic::solve::general<scalar_name>( zero, coefficient, epsilon = 1e-6 )


 namespace math
  {
   namespace polynomial
    {
     namespace quartic 
      {
       namespace solve
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
            switch( math::polynomial::quadric::solve::general( r2, coefficient, epsilon ) )
             {
              case( 2 ):
               {
                if( r2[1] < -epsilon ) { goto case_1; }
                if( r2[1] < +epsilon ) { root[count++] = 0; goto case_1; }
              //if( epsilon < r2[1] )
                 {
                  root[count++] = - sqrt( r2[1] );
                  root[count++] = + sqrt( r2[1] );
                 }
               }// break for no one
              case( 1 ):
               {
                case_1:
                if( r2[0] < -epsilon ) { goto case_0; }
                if( r2[0] < +epsilon ) { root[count++] = 0; goto case_0; }
              //if( epsilon < r2[0] )
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
        unsigned ferrari( scalar_name root[4], scalar_name const coefficient[5], scalar_name const& epsilon = 1e-12 )
         {  // [0] + [1] * x + [2] * x ^2 + 0.0. * x^3 +  1.0 * x^4
          scalar_name const& p = coefficient[2];
          scalar_name const& q = coefficient[1];
          scalar_name const& r = coefficient[0];

          if( q * q < epsilon )
           {
            scalar_name biC[3]={ r, p, 1 };
            return math::polynomial::quartic::solve::bi( root, biC, epsilon );
           }

          scalar_name resolventC[ 4 ]={ -q*q, 2*p*p-scalar_name(8)*r, scalar_name(8)*p, scalar_name(8) };
          scalar_name resultC[ 3 ];
          unsigned countC = ::math::polynomial::cubic::solve::general( resultC, resolventC, epsilon );
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
            scalar_name biC[3]={ r, p, 1 };
            return math::polynomial::quartic::solve::bi( root, biC, epsilon );
           }

          unsigned count=0;

          scalar_name quadCa[2]={ scalar_name( p/2 + m - q/( 2 * sqrt( 2*m ) ) ), scalar_name( +sqrt( 2 * m ) ) }; count += ::math::polynomial::quadric::solve::monic( root+count, quadCa, epsilon );
          scalar_name quadCb[2]={ scalar_name( p/2 + m + q/( 2 * sqrt( 2*m ) ) ), scalar_name( -sqrt( 2 * m ) ) }; count += ::math::polynomial::quadric::solve::monic( root+count, quadCb, epsilon );

          return count;
         }

       template
        <
        typename scalar_name
        >   // Monic adn depressed
        unsigned descartes( scalar_name root[4], scalar_name const coefficient[5], scalar_name const& epsilon = 1e-12 )
         {    // [0] + [1] * x + [2] * x ^2 + 0 * x^3 + 1 * x^4. Monic and depressed !!!
          root[3]=root[2]=root[1]=root[0]=NAN;

         scalar_name const& p = coefficient[2];
         scalar_name const& q = coefficient[1];
         scalar_name const& r = coefficient[0];

         scalar_name Q = q * q;
         if( q * q < epsilon)
          {
           scalar_name biC[3]={ r, p, 1 };
           return math::polynomial::quartic::solve::bi( root, biC, epsilon );
          }

          scalar_name D = p*p - 4 * r;
          scalar_name resolventC[ 4 ]={ - Q, D, scalar_name(2)*p, scalar_name(1) };
          scalar_name resultC[ 3 ];
          unsigned countC = ::math::polynomial::cubic::solve::general( resultC, resolventC, epsilon );
          if( 0 == countC )
           { // Impossible!!!
            return 0;
           }

          scalar_name const& U = resultC[countC-1];
          if( U < - epsilon  )
           {
            return 0;
           }

          scalar_name u, s, t, v;

          unsigned count=0;
          if( U < epsilon  )
           {               // bi( root+count,{ tv, t+v, 1 }, epsilon )
            u = 0;
            s = 0;

            if( D < -epsilon )
             {
              return 0;
             }

            if( D < epsilon )
             {
              t = p / 2;

              count += ::math::polynomial::quadric::solve::trivial( root+count, t, epsilon );
              return count;
             }

            t = ( p - sqrt( D ) ) / 2;
            v = ( p + sqrt( D ) ) / 2;

            count += ::math::polynomial::quadric::solve::trivial( root+count, t, epsilon );
            count += ::math::polynomial::quadric::solve::trivial( root+count, v, epsilon );
            return count;
           }
          else
           {
            u = sqrt( U );
            s = -u;
            t = ( p + U + q/u )/2;
            v = ( p + U - q/u )/2;
            scalar_name quadCa[2]={ t, s }; count += ::math::polynomial::quadric::solve::monic( root+count, quadCa, epsilon );
            scalar_name quadCb[2]={ v, u }; count += ::math::polynomial::quadric::solve::monic( root+count, quadCb, epsilon );
           }

          return count;
         }

       template
        <
          typename scalar_name
        > // expect monic polynom
        unsigned shmakov( scalar_name root[4], scalar_name const coefficient[5], scalar_name const& epsilon = 1e-12 )
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
            unsigned countC = ::math::polynomial::cubic::solve::general( resultC.data(), resolventC.data(), epsilon );
            y = resultC[ 0 ];
           }

          unsigned count=0;
          unsigned count_real=0;
          std::array<scalar_name,2> g;
          switch( ::math::polynomial::quadric::solve::monic( g.data(),  B-y, -A, epsilon ) )
           {
            case(0) : return 0;
            case(1) : g[1] = g[0]; count = 2; count_real += 1; break;
            case(2) :              count = 2; count_real += 2; break;
           }

          std::array<scalar_name,2> h;
          switch( ::math::polynomial::quadric::solve::monic( h.data(),    D, -y, epsilon ) )
           {
            case(0) : return 0;
            case(1) : h[1] = h[0]; count = 4; count_real +=1;  break;
            case(2) :              count = 4; count_real +=2;  break;
           }

          if( 4 != count )
           {
            return 0;
           }

          count = ::math::polynomial::quadric::solve::monic(  root,       h[0], g[0] );
          if( 2 == count_real )
           {
            return count;
           }

          count += ::math::polynomial::quadric::solve::monic( root+count, h[1], g[1] );

          return count;
         }

       template
        <
          typename scalar_name
        >
        unsigned general( scalar_name root[4], scalar_name const coefficient[5], scalar_name const& epsilon = 1e-12 )
         {
          if( ( -epsilon < coefficient[4] ) && ( coefficient[4] < epsilon ) )
           {
            return math::polynomial::cubic::solve::general( root, coefficient, epsilon );
           }

          if( ( -epsilon < coefficient[0] ) && ( coefficient[0] < epsilon ) )
           {
            root[ 0 ] = 0;
            return 1 + ::math::polynomial::cubic::solve::general( root+1, coefficient+1, epsilon );
           }

          if(    ( ( -epsilon < coefficient[1] ) && ( coefficient[1] < epsilon ) )
              && ( ( -epsilon < coefficient[3] ) && ( coefficient[3] < epsilon ) )
            )
           {
            scalar_name c2[3]={coefficient[0], coefficient[2], coefficient[4] };
            return ::math::polynomial::quartic::solve::bi( root, c2, epsilon );
           }


          // scalar_name shift = ::math::polynomial::quartic::depressing( depressedC, coefficient, epsilon );
          // scalar_name shift = ::math::polynomial::quartic::monic( depressedC, depressedC, epsilon );
          scalar_name const& a4 = coefficient[4];
          scalar_name const& a3 = coefficient[3];
          scalar_name const& a2 = coefficient[2];
          scalar_name const& a1 = coefficient[1];
          scalar_name const& a0 = coefficient[0];

          scalar_name r = (-3*a3*a3*a3*a3 +256*a0*a4*a4*a4 - 64*a1*a3*a4*a4 + 16*a2*a3*a3*a4)/(256*a4*a4*a4*a4);
          scalar_name q = (a3*a3*a3 - 4*a2*a3*a4+8*a1*a4*a4)/(8*a4*a4*a4 );
          scalar_name p = ( 8*a2*a4-3*a3*a3)/( 8*a4*a4  );
          scalar_name depressedC[3]={ r, q, p };

          //std:: cout << "p:" << p << "; q: " << q << "; r: " << r << std::endl; 

          scalar_name substitution = -a3/(4*a4);
          unsigned count;
          switch( count = ::math::polynomial::quartic::solve::ferrari( root, depressedC, epsilon ) )
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
        unsigned general( std::array<scalar_name,4> & root, std::array<scalar_name,5> const& coefficient, scalar_name const& epsilon = 1e-12 )
         {
          return ::math::polynomial::quartic::solve::general<scalar_name>( root.data(), coefficient.data(), epsilon );
         }

        }
      }
    }
  }

#endif
