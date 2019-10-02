#ifndef math_topology_sico_simplexA
#define math_topology_sico_simplexA

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
         typename  data_name  //!< Essentially whatever
         unsigned  dimension_size
       >
       struct simplexA 
        {
         public:
           typedef std::array<size_type, dimension_size + 1 > face_type;
           data_name m_data;

           explicit simplexA( data_name const& data_param ):m_data(data_param){ }

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

      template
       <
         typename  data_name
       >
       struct simplexA < data_name, 0 >
        {
         public:
           data_name m_data;

           explicit simplexA( data_name const& data_param ):m_data(data_param){ }

         public:
           data_name const& data() const{ return m_data; }
           data_name      & data()      { return m_data; }
         private:
           data_name m_data;
        };

     }
   }
 }

#endif
