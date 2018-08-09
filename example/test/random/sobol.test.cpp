#include <iostream>
#include <iomanip>

#include "sobol.cpp"

using namespace std;

int main( int argc, char *argv[] )
 {
  Sobol2D s1;
  typedef sobol<2, double, unsigned > sobol_type;
  sobol_type s2;

  for( int i=0; i< 20; i++ )
   {
    Sobol2D::T_scalar I_x, I_y;
    s1.next( I_x, I_y );
    sobol_type::T_coord I_coord;
    s2.next( I_coord );
    
    cout << setw(14) << I_x << " - " << setw(14) << I_coord[0]  << ";";
    cout << setw(14) << I_y << " - " << setw(14) <<I_coord[1]  << endl;
   }

  return EXIT_SUCCESS;
 }

