#ifndef math_library_linear_algebra__vector_reflect_HPP_
 #define math_library_linear_algebra__vector_reflect_HPP_
 
//::math::linear::vector::project( result, incident, normal )

#include "./structure.hpp"


 
 
 


 namespace math
  {
   namespace linear
    {
     namespace vector
      {

       template< typename scalar_name, unsigned dimension_number >
        inline
        void
        reflect
         (
           ::math::linear::vector::structure< scalar_name, dimension_number >      & result_param
          ,::math::linear::vector::structure< scalar_name, dimension_number > const& incident
          ,::math::linear::vector::structure< scalar_name, dimension_number > const& normal
         )
         {
          using namespace ::math::linear::vector;
          result_param = incident - 2 * ::math::linear::vector::dot( incident, normal ) * normal;
         }

       template< typename scalar_name >
        inline
        void
        reflect
         (
           ::math::linear::vector::structure< scalar_name, 2 >      & result_param
          ,::math::linear::vector::structure< scalar_name, 2 > const& P_incident
          ,::math::linear::vector::structure< scalar_name, 2 > const& P_normal
         )
         {
          using namespace ::math::linear::vector;
          scalar_name I_dot = ::math::linear::vector::dot( P_incident, P_normal );
          result_param[0] = P_incident[0] - 2 * I_dot * P_normal[0];
          result_param[1] = P_incident[1] - 2 * I_dot * P_normal[1];
         }

       template< typename scalar_name >
        inline
        void
        reflect
         (
           ::math::linear::vector::structure< scalar_name, 3 >      & result_param
          ,::math::linear::vector::structure< scalar_name, 3 > const& P_incident
          ,::math::linear::vector::structure< scalar_name, 3 > const& P_normal
         )
         {
          using namespace ::math::linear::vector;
          scalar_name I_dot = ::math::linear::vector::dot( P_incident, P_normal );
          result_param[0] = P_incident[0] - 2 * I_dot * P_normal[0];
          result_param[1] = P_incident[1] - 2 * I_dot * P_normal[1];
          result_param[2] = P_incident[2] - 2 * I_dot * P_normal[2];
         }

       template< typename scalar_name >
        inline
        void
        reflect
         (
           ::math::linear::vector::structure< scalar_name, 4 >      & result_param
          ,::math::linear::vector::structure< scalar_name, 4 > const& P_incident
          ,::math::linear::vector::structure< scalar_name, 4 > const& P_normal
         )
         {
          using namespace ::math::linear::vector;
          scalar_name I_dot = ::math::linear::vector::dot( P_incident, P_normal );
          result_param[0] = P_incident[0] - 2 * I_dot * P_normal[0];
          result_param[1] = P_incident[1] - 2 * I_dot * P_normal[1];
          result_param[2] = P_incident[2] - 2 * I_dot * P_normal[2];
          result_param[3] = P_incident[3] - 2 * I_dot * P_normal[3];
         }

      }
    }
  }

#endif
