#ifndef math_topology_sico_intersect
#define math_topology_sico_intersect

// ::math::topology::sico::intersect <data_name>( result, left, right )


#include <algorithm>
#include <vector>
#include "./structure.hpp"

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
       struct intersect_struct
        {
         public:
           typedef std::size_t size_type;
           typedef std::vector< size_type > index_type;
           typedef std::pair< index_type, index_type > pair_type;

           typedef std::vector< pair_type > result_type;


           typedef ::math::topology::sico::structure<data_name> structure_type;

         public:
           static size_type process( result_type & result, structure_type const& left, structure_type const& right )
            {
             result.clear();
             result.reserve( std::min( left.size(), right.size() ) );
             result.resize(1);
             for( size_type left_index=0; left_index< left.size(0) ; ++left_index )
              {
               auto const& left_point = left.vertex( left_index );
               for( size_type right_index=0; right_index< right.size(0) ; ++right_index )
                {
                 auto const& right_point = right.vertex( right_index );
                 if( left_point.cell().size() != right_point.cell().size() )
                  {
                   continue;
                  }
                 result[0].first.push_back( left_index );
                 result[0].second.push_back( right_index );
                }
              }
             {
              auto & first = result[0].first;
              std::sort( first.begin(), first.end()  ); first.erase( std::unique( first.begin(), first.end() ), first.end() );
              auto & second = result[0].second;
              std::sort( second.begin(), second.end() ); second.erase( std::unique( second.begin(), second.end() ), second.end() );
             }


             for( size_type dimension=1; dimension < std::min( left.size(), right.size() ); ++dimension )
              {
               result.resize( result.size() + 1 );
               for( size_type left_index=0; left_index< left.size(dimension) ; ++left_index )
                {
                 auto const& left_simplex = left.simplex( dimension, left_index );

                 auto const& left_subs = result[dimension-1].first;
                 bool left_skip = false;
                 for( auto const& face : left_simplex.face()  )
                  {
                   if(  false == ::std::binary_search( left_subs.begin(), left_subs.end(), face ) )
                    {
                     left_skip = true;
                     break;
                    }
                  }

                 if( true == left_skip )
                  {
                   continue;
                  }

                 for( size_type right_index=0; right_index< right.size(dimension) ; ++right_index )
                  {
                   auto const& right_simplex = right.simplex( dimension, right_index );
                   if( left_simplex.cell().size() != right_simplex.cell().size() )
                    {
                     continue;
                    }

                   auto const& right_subs = result[dimension-1].second;
                   bool right_skip = false;
                   for( auto const& face : right_simplex.face()  )
                    {
                     if(  false == ::std::binary_search( right_subs.begin(), right_subs.end(), face ) )
                      {
                       right_skip = true;
                       break;
                      }
                    }

                   if( true == right_skip )
                    {
                     continue;
                    }

                   result[dimension].first.push_back( left_index );
                   result[dimension].second.push_back( right_index );
                  }
                }

               {
                auto & first = result[dimension].first;
                std::sort( first.begin(), first.end()  ); first.erase( std::unique( first.begin(), first.end() ), first.end() );
                auto & second = result[dimension].second;
                std::sort( second.begin(), second.end() ); second.erase( std::unique( second.begin(), second.end() ), second.end() );
               }
              }

             return 0;
            }

           //static void convert( structure_type & result, index_type const& list )
           // {
           //  structure_type result;
           // }

       };



      template
       <
         typename  data_name
       >
       size_t intersect
        (
           typename intersect_struct<data_name>::result_type      & result
         ,::math::topology::sico::structure<data_name>       const& left
         ,::math::topology::sico::structure<data_name>       const& right
        )
        {
         return ::math::topology::sico::intersect_struct<data_name>::process( result, left, right );
        }

     }
   }
 }

#endif
