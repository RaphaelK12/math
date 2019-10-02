#ifndef math_topology_sico_container
#define math_topology_sico_container

// ::math::topology::sico::container<data_name>



#include <algorithm>
#include <map>
#include "./simplex.hpp"
#include "../../function/binomial.hpp"

namespace math
 {
  namespace topology
   {
    namespace sico
     {

      template
       <
         typename  data_name
       >
       class container;

      template
       <
         typename  data_name
       >
       size_t star  // All simplexes of dimension+1 that contain this simplex(dimension,index)
        (
           std::vector< std::size_t >                       & result
         , std::size_t                                 const& dimension
         , std::size_t                                 const& index
         ,::math::topology::sico::container<data_name> const& sc
        );

      template
       <
         typename  data_name
       >
       class container //!< Essentially whatever
        {
         public:
           typedef std::size_t     size_type;

           typedef data_name       data_type;

           typedef ::math::topology::sico::simplex<data_name> simplex_type;
           typedef typename simplex_type::face_type face_type;

           typedef std::vector< simplex_type > level_type;
           typedef std::vector< level_type > structure_type;
           typedef std::initializer_list<size_type> list_type;

         public:
           container()
            {
             this->clear();
            }

           size_t push( data_name const& data, face_type const& face )
            {
             if( 0 == face.size() )
              {
               m_structure[0].emplace_back( data, face );
               return m_structure[0].size()-1;
              }

             if( 1 == face.size() )
              {
               if( m_structure[0].size() <= face[0] )
                {
                 return m_structure[0].size();
                }
               m_structure[0][ face[0] ].data() = data;
               return face[0];
              }

             size_type dimension = face.size() -1;
             if( m_structure.size() < dimension )
              {
               return m_structure[dimension].size();
              }

             if( dimension == m_structure.size() )
              {
               m_structure.resize( dimension + 1 );
              }

             for( size_type index=0; index < face.size(); ++index )
              {
               if( m_structure[ dimension-1 ].size() <= face[index] )
                {
                 return m_structure[dimension].size();
                }
              }

             {
              size_type index = this->find( face );
              if( m_structure[dimension].size() != index )
               {
                return index;
               }
             }

             if( 2 == face.size() )
              {
               m_structure[1].emplace_back( data, face );
               return m_structure[1].size() -1;
              }

             std::map<size_type, size_type> counter;
             for( auto const& index_line : face )
              {
               for( auto const& index_point: m_structure[dimension-1][index_line].face() )
                 {
                  auto & size = counter[ index_point ];
                  size ++;
                  if( 2 < size )
                   {
                    return m_structure[dimension].size();
                   }
                 }
              }

             if( ::math::function::binomial( dimension + 1, dimension - 1 ) != counter.size() )
              {
               return m_structure[dimension].size();
              }

             for( auto a : counter )
              {
               if( a.second != 2 )
                {
                 return m_structure[dimension].size();
                }
              }
             m_structure[dimension].emplace_back( data, face );
             return m_structure[dimension].size();
            }

           bool erase( size_type const& dimension, size_type const& index )
            {
             if( false == this->exists( dimension, index ) )
              {
               return false;
              }

             if( this->dimension() == dimension )
              {
               m_structure[dimension].erase( m_structure[dimension].begin() + index );
               return true;
              }

             std::vector< size_type> to_remove;
             ::math::topology::sico::star( to_remove, dimension, index, *this );
             std::sort( to_remove.begin(), to_remove.end() );
             auto upper = dimension + 1;
             for (auto iteratori = to_remove.rbegin(); iteratori != to_remove.rend(); ++iteratori )
              {
               this->erase( upper, *iteratori );
              }

             for( size_type index_up=0; index_up < this->size( upper ); ++index_up )
              {
               auto & face = m_structure[upper][ index_up].face();
               for( auto & i : face )
                {
                 if( index <= i )
                  {
                   --i;
                  }
                }
              }

             this->m_structure[dimension].erase( m_structure[dimension].begin() + index );

             return true;
            }

           void clear()
            {
             this->m_structure.clear();
             this->m_structure.resize( 1 );
            }

           size_type find( face_type const& face )const
            {
             if( m_structure.size() < face.size() )
              {
               return m_structure.size();
              }

             size_type dimension = face.size() -1;
             auto other = face;
             std::sort( other.begin(), other.end() );

             for( size_type index=0; index < m_structure[ dimension ].size(); ++index )
              {
               auto const& simplex = m_structure[ dimension ][index];
               auto me = simplex.face();
               std::sort( me.begin(), me.end() );
 
               if( other == me )
                {
                 return index;
                }
              }

             return m_structure[dimension].size();
            }

           bool exists( size_type const& dimension, size_type const& index )const
            {
             if( m_structure.size() <= dimension )
              {
                return false;
              }
             return index < m_structure[dimension].size();
            }

            size_type dimension()const
             {
              return (0 !=m_structure.size())? m_structure.size()-1 : 0;
             }

            size_type size()const
             {
              return m_structure.size();
             }

           size_type size( size_type const& dimension )const
            {
             if( m_structure.size() <= dimension )
              {
               return 0;
              }
             return m_structure[ dimension ].size();
            }

           level_type const & vertex()const
            {
              return m_structure[0];
            }

           simplex_type const & vertex( size_type const&  index )const
            {
             return m_structure[0][index];
            }

           simplex_type       & vertex( size_type const&  index )
            {
             return m_structure[0][index];
            }

            size_t trim( size_type dimension )
             {
              dimension = std::min( dimension, this->dimension() );
              do
               {
                if( 0 == this->size( dimension ) )
                 {
                  this->m_structure.resize( dimension );
                 }
                break;
               }
              while( --dimension );

              this->m_structure.resize( dimension + 1 );
              return this->dimension();
             }

            level_type const& level( size_type const& dimension )
            {
             static level_type empty;
             if( this->size() < dimension )
              {
               return empty;
              }
             if( 0 == this->m_structure[ dimension ] )
              {
               return empty;
              }
              return this->m_structure[ dimension ];
             }

           simplex_type const & simplex( size_type const& dimension, size_type const&  index )const
            {
             return m_structure[dimension][index];
            }

           simplex_type       & simplex( size_type const& dimension, size_type const&  index )
            {
             return m_structure[dimension][index];
            }
         public:
           structure_type const& structure()const{ return m_structure; }
         protected:
           //structure_type      & structure()     { return m_structure; }
         private:
           structure_type       m_structure;
        };

     }
   }
 }

#endif
