#ifndef math_type_affine_structure
 #define math_type_affine_structure

 // ::math::linear::affine::structure<scalar_name,dimension_number>

#include <array>
#include "../matrix/structure.hpp"
#include "../vector/vector.hpp"



 namespace math
  {
   namespace linear
    {
     namespace affine
      {

       template
        <
          typename scalar_name
         ,unsigned dimension_number
        >
        class structure
         {
          public:
            typedef std::size_t   size_type;
            typedef scalar_name scalar_type;

            typedef ::math::linear::matrix::structure<scalar_name,dimension_number,dimension_number> matrix_type;
            typedef ::math::linear::vector::structure<scalar_name,dimension_number> vector_type;

            structure( )
             {
              //nothing
             }

            structure( matrix_type const& m, vector_type const& v )
             : m_matrix( m )
             , m_vector( v )
             {
             }

            vector_type const& operator[]( size_type const& index )const
             {
              switch( index )
               {
                default:
                case( 0 ): return this->matrix()[0];
                case( 1 ): return this->matrix()[1];
                case( 2 ): return this->matrix()[2];
                case( 3 ): return this->vector();
               }
             }

            vector_type & operator[]( size_type const& index )
             {
              switch( index )
               {
                default:
                case( 0 ): return this->matrix()[0];
                case( 1 ): return this->matrix()[1];
                case( 2 ): return this->matrix()[2];
                case( 3 ): return this->vector();
               }
             }

          public:
            matrix_type const& matrix()const
             {
              return m_matrix;
             }
            matrix_type & matrix()
             {
              return m_matrix;
             }
          private:
            matrix_type m_matrix;

          public:
            vector_type const& vector()const
             {
              return m_vector;
             }
            vector_type & vector()
             {
              return m_vector;
             }
          private:
            vector_type m_vector;
         };

      }
    }
  }

#endif
