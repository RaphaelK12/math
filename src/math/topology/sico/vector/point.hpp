#ifndef math_topology_sico_vector_point
#define math_topology_sico_vector_point

// ::math::topology::sico::vector::point<data_name>

#include <vector>
#include <array>
#include "../../../linear/vector/distance.hpp"

#include "../simplex.hpp"

namespace math
 {
  namespace topology
   {
    namespace sico
     {

      namespace vector
       {

       template
         <
           typename         data_name //!< Essentially whatever. Copyable
          ,typename     scalar_number
          ,unsigned   dimesion_number
         >
         ::math::linear::vector::point< scalar_number, dimesion_number > const & 
         point 
         (
          ::math::topology::sico::simplex<data_name> const& simplex
         )
         {
          return simplex.data();
         }

       }

     }
   }
 }

#endif
