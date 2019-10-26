#ifndef math_polynomial_interpolate_linear_HPP_
 #define math_polynomial_interpolate_linear_HPP_

 // ::math::polynomial::solve::linear<scalar_name>( coefficient, x, y )



 namespace math
  {
   namespace polynomial
    {
     namespace linear
      {

       template
        <
          typename scalar_name
        >
        inline bool interpolate
         (
           scalar_name coefficient[2]
          ,scalar_name const& x0, scalar_name const& y0
          ,scalar_name const& x1, scalar_name const& y1
          ,scalar_name const& epsilon = 1e-12
         )
         { // purposly not yet optimal
          scalar_name f0 = y0 /( x0 - x1 );
          scalar_name f1 = y1 /( x1 - x0 );

          scalar_name a0 = f0;
          scalar_name b0 = f0*( -( x1 ) );

          scalar_name a1 = f1;
          scalar_name b1 = f1*( -( x0 ) );

          coefficient[ 1 ] = a0 + a1;
          coefficient[ 0 ] = b0 + b1;

          return true;
         }
/*
       template
        <
          typename scalar_name
        >
        inline unsigned interpolate( scalar_name coefficient[2], scalar_name const x[2], scalar_name const y[2] )
         {
          return ::math::polynomial::linear::interpolate( coefficient, x[0], y[0], x[1], y[1] );
         }

       template
        <
          typename scalar_name
        >
        inline unsigned interpolate( scalar_name coefficient[2], scalar_name const& cloud[2][2] )
         {
          return ::math::polynomial::linear::interpolate( coefficient, cloud[0], cloud[1] );
         }

       template
        <
          typename scalar_name
        >
        inline unsigned interpolate( scalar_name coefficient[2], std::array<scalar_name,2> const& cloud[2] )
         {
          return ::math::polynomial::linear::interpolate( TODO );
         }

       template
        <
          typename scalar_name
        >
        inline unsigned interpolate( scalar_name coefficient[2], std::array< std::array<scalar_name,2> , 2> const& cloud )
         {
          return ::math::polynomial::linear::interpolate( TODO );
         }

       template
        <
          typename scalar_name
        >
        inline unsigned interpolate( std::array<scalar_name,1> & coefficient, std::array< std::array<scalar_name,2> , 2> const& cloud )
         {
          return interpolate( coefficient.data(), cloud );
         }
*/
      }
    }
  }

#endif
