#ifndef math_geometry_direction_ABC2D
#define math_geometry_direction_ABC2D

// ::math::geometry::direction::ABC2D<scalar_name>
#include <array>
#include "../../linear/vector/structure.hpp"





namespace math
 {
  namespace geometry
   {
    namespace direction
     {

      template<typename scalar_name, unsigned dimesion_number >
        class two;

      template<typename scalar_name, unsigned dimesion_number >
        class parametric;

      template<typename scalar_name>
        class polar;

      template
       <
         typename scalar_name = double
       >
       class ABC2D
        {
         public:

           typedef unsigned      size_type;
           typedef scalar_name scalar_type;

           typedef ::math::linear::vector::point<scalar_type,2> point2_type;
           typedef std::array<scalar_type,3> array_type;

           typedef ::math::geometry::direction::two<scalar_name, 2>               two_type;
           typedef ::math::geometry::direction::ABC2D<scalar_name>               this_type;
           typedef ::math::geometry::direction::parametric<scalar_name, 2> parametric_type;
           typedef ::math::geometry::direction::polar<scalar_name>              polar_type;

           explicit ABC2D( scalar_type const& A=0, scalar_type const& B=0, scalar_type const& C=0 )
            :m_A(A)
            ,m_B(B)
            ,m_C(C)
            {
            }

           explicit ABC2D( array_type const& array )
            :m_A( array[0] )
            ,m_B( array[1] )
            ,m_C( array[2] )
            {
            }

           explicit ABC2D( two_type const& two )
            {
             *this = two;
            }

           explicit ABC2D( parametric_type const& parametric )
            {
             *this = parametric;
            }

           explicit ABC2D( polar_type const& polar )
            {
             *this = polar;
            }

           this_type & operator=( parametric_type const& parametric )
            {
             this->A() = +parametric.direction()[1];
             this->B() = -parametric.direction()[0];
             this->C() = - this->A()*parametric.origin()[0] - this->B()*parametric.origin()[1];
             return *this;
            }

           this_type & operator=( polar_type const& polar )
            {
             this->A() = +sin( polar.angle() );
             this->B() = -cos( polar.angle() );
             this->C() = - this->A() * polar.origin()[0] - this->B() * polar.origin()[1];

             //this->C() = - sin( polar.angle() )*polar.origin()[0] + cos( polar.angle()  )*polar.origin()[1] ;

             return *this;
            }

           this_type & operator=( two_type const& two )
            {
             this->A() = +(two.second()[1] - two.first()[1] );
             this->B() = -(two.second()[0] - two.first()[0] );
             this->C() = - this->A()*two.first()[0] - this->B() * two.first()[1];
             return *this;
            }

           void set( array_type const& array )
            {
             this->A() = array[0]; 
             this->B() = array[1]; 
             this->C() = array[2];
            }

           scalar_type calc( point2_type const& point )const
            {
             return this->A() * point[0]  +  this->B() * point[1]  +  this->C();
            }

           template< unsigned index_number >
            scalar_type const& get()const
             {
             switch( index_number )
              {
               default:
               case( 0 ): return this->A();
               case( 1 ): return this->B();
               case( 2 ): return this->C();
              }
             }

           scalar_type const& operator[]( size_type const& index )const
            {
             switch( index )
              {
               default:
               case( 0 ): return this->A();
               case( 1 ): return this->B();
               case( 2 ): return this->C();
              }
            }

           this_type  normalize()const
            {
             this_type result;
             scalar_type D = sqrt( this->A() * this->A()  +  this->B() * this->B() );
             result.A() = this->A() / D;
             result.B() = this->B() / D;
             result.C() = this->C() / D;
             return result;
            }

           this_type & normalize()
            {
             scalar_type D = sqrt( this->A() * this->A()  +  this->B() * this->B() );
             this->A() /= D;
             this->B() /= D;
             this->C() /= D;
             return *this;
            }

           this_type & normalize3()
            {
             scalar_type D = sqrt( this->A() * this->A()  +  this->B() * this->B()  +  this->C() * this->C() );
             this->A() /= D;
             this->B() /= D;
             this->C() /= D;
             return *this;
            }
           this_type  normalize3()const
            {
             this_type result;
             scalar_type D = sqrt( this->A() * this->A()  +  this->B() * this->B()  +  this->C() * this->C());
             result.A() = this->A() / D;
             result.B() = this->B() / D;
             result.C() = this->C() / D;
             return result;
            }

        public:
          scalar_type const& A()const{ return m_A; }
          scalar_type      & A()     { return m_A; }
          scalar_type const& B()const{ return m_B; }
          scalar_type      & B()     { return m_B; }
          scalar_type      & C()     { return m_C; }
          scalar_type const& C()const{ return m_C; }
        private:
           // A * x  +  B * y  +  C = 0
           scalar_type m_A, m_B, m_C;
        };

     }
   }
 }

#endif

