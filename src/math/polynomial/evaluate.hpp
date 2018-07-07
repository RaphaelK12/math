#ifndef Dh_DDMRM_math_polynomial_evaluate_HPP_
 #define Dh_DDMRM_math_polynomial_evaluate_HPP_

 #include <array>
 #include <vector>

 #define math_polynomial_evaluate_linear(x,a0,a1) \
   ( (a0) +   (a1) * (x) )

 #define math_polynomial_evaluate_quadric(x,a0,a1,a2) \
   ( (a0) + ( (a1) + (a2) * (x)   )* (x) )

 #define math_polynomial_evaluate_cubic(x,a0,a1,a2,a3) \
  ( a0 + ( (a1) + ( (a2) + (a3) * (x) )* (x) ) * (x) )

 #define math_polynomial_evaluate_quartic(x,a0,a1,a2,a3,a4) \
 ( a0+ ( a1 + ( (a2) + ( (a3) + (a4) * (x) )* (x) ) * (x) ) * (x) )




  namespace math
  {
   namespace polynomial
    {

     template
      <
        typename scalar_name
      >
      scalar_name evaluate( scalar_name const& paramter, scalar_name const* coefficient, std::size_t const& size )
       {
        // TODO
        return coefficient[0] + paramter * coefficient[1] ;
       }

     template
      <
        typename scalar_name
      >
      scalar_name evaluate( scalar_name const& paramter, std::vector<scalar_name> const& coefficient )
       {
        // TODO
        return coefficient[0] + paramter * coefficient[1] ;
       }

     template
      <
        typename scalar_name
       ,unsigned  size_number
      >
      scalar_name evaluate( scalar_name const& paramter, std::array<scalar_name,size_number> const& coefficient )
       {
        // TODO
        return coefficient[0] + paramter * coefficient[1] ;
       }


     template
      <
        typename scalar_name
      >
      scalar_name evaluate( scalar_name const& paramter, std::array<scalar_name,2> const& coefficient )
       {
        return coefficient[0] + paramter * coefficient[1] ;
       }

     template
      <
        typename scalar_name
      >
      scalar_name evaluate( scalar_name const& paramter, std::array<scalar_name,3> const& coefficient )
       {
        return coefficient[0] + paramter * ( coefficient[1] + paramter*coefficient[2] );
       }

     template
      <
        typename scalar_name
      >
      scalar_name evaluate( scalar_name const& paramter, std::array<scalar_name,4> const& coefficient )
       {
        return coefficient[0] + paramter * ( coefficient[1] + paramter*( coefficient[2] + paramter*coefficient[3] ) );
       }

     template
      <
        typename scalar_name
      >
      scalar_name evaluate( scalar_name const& paramter, std::array<scalar_name,5> const& coefficient )
       {
        return coefficient[0] + paramter * ( coefficient[1] + paramter*( coefficient[2] + paramter*( coefficient[3] + paramter*coefficient[4] ) ) );
       }

    }
  }

#endif
