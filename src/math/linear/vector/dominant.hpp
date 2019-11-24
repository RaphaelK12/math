#ifndef math_library_linear_algebra__vector_dominant_HPP_
 #define math_library_linear_algebra__vector_dominant_HPP_

 // ::math::linear::vector::dominant( coord )


#include "./structure.hpp"





 namespace math
  {
   namespace linear
    {
     namespace vector
      {

       template< typename scalar_name, unsigned dimension_number >
        inline
        std::pair<std::size_t, scalar_name >
        dominant
         (
           ::math::linear::vector::structure< scalar_name, dimension_number > const& v
         )
         { // TODO not optimal
          std::pair<std::size_t, scalar_name > result;
          auto & index=result.first;
          auto & dominator = result.second = fabs( v[index] );

          for( std::size_t i=1; i < dimension_number; ++i)
           {
            scalar_name chalenger = fabs( v[i] );
            if( dominator < chalenger )
             {
              index = i;
              dominator = chalenger;
             }
           }
          return result;
         }

       template< typename scalar_name >
        inline
        std::pair<std::size_t, scalar_name >
        dominant
         (
           ::math::linear::vector::structure< scalar_name, 2 > const& v
         )
         {
          std::pair<std::size_t, scalar_name > result;
          auto & index=result.first;
          auto & dominator = result.second = fabs( v[index] );

          { scalar_name chalenger = fabs( v[1] ); if( dominator < chalenger ){ dominator = chalenger; index = 1; } }

          return result;
         }

       template< typename scalar_name >
        inline
        std::pair<std::size_t, scalar_name >
        dominant
         (
           ::math::linear::vector::structure< scalar_name, 3 > const& v
         )
         {
          std::pair<std::size_t, scalar_name > result;
          auto & index=result.first;
          auto & dominator = result.second = fabs( v[index] );

          { scalar_name chalenger = fabs( v[1] ); if( dominator < chalenger ){ dominator = chalenger; index = 1; } }
          { scalar_name chalenger = fabs( v[2] ); if( dominator < chalenger ){ dominator = chalenger; index = 2; } }

          return result;
         }

       template< typename scalar_name >
        inline
        std::pair<std::size_t, scalar_name >
        dominant
         (
           ::math::linear::vector::structure< scalar_name, 4 > const& v
         )
         {
          std::pair<std::size_t, scalar_name > result;
          auto & index=result.first;
          auto & dominator = result.second = fabs( v[index] );

          { scalar_name chalenger = fabs( v[1] ); if( dominator < chalenger ){ dominator = chalenger; index = 1; } }
          { scalar_name chalenger = fabs( v[2] ); if( dominator < chalenger ){ dominator = chalenger; index = 2; } }
          { scalar_name chalenger = fabs( v[3] ); if( dominator < chalenger ){ dominator = chalenger; index = 3; } }

          return result;
         }

     }
   }
 }

#endif
