#ifndef math_topology_sico_simplex
#define math_topology_sico_simplex

// ::math::topology::sico::simplex<data_name>

#include <vector>

namespace math
 {
  namespace topology
   {
    namespace sico
     {

     template
       <
         typename  data_name //!< Essentially whatever. Copyable
       >
       struct simplex
        {
         public:
           typedef size_t size_type;
           typedef std::vector<size_type> face_type;
           typedef std::initializer_list<size_type> list_type;

           explicit simplex( data_name const& data_param ):m_data(data_param){ }
           explicit simplex( data_name const& data_param, face_type const& face ):m_data(data_param), m_face(face){ }

         public:
           data_name const& data() const{ return m_data; }
           data_name      & data()      { return m_data; }
         private:
           data_name m_data;

         public:
           face_type const& face() const{ return m_face; }
           face_type      & face()      { return m_face; }
         private:
           face_type m_face;
        };

     }
   }
 }

#endif
