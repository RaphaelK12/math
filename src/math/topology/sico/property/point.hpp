#ifndef math_topology_sico_property_point
#define math_topology_sico_property_point

// ::math::topology::sico::vector::point<data_name>

#include <vector>
#include <array>
#include "../../../linear/vector/distance.hpp"

#include "../simplex/loaded.hpp"

namespace math
 {
  namespace topology
   {
    namespace sico
     {
      namespace property
       {

       template
        <
          typename     scalar_number
         ,unsigned   dimesion_number
         ,typename         data_name //!< Essentially whatever. Copyable
        >
        inline ::math::linear::vector::point< scalar_number, dimesion_number > const &
        point
         (
           ::math::topology::sico::simplex::loaded<data_name> const& simplex
         )
         {
          return simplex.data();
         }

       }
     }
   }
 }

#endif
