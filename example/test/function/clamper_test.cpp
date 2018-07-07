//! @warning  Use it at your own risk.
//! @copyright *this file is FREEWARE. 
//! @file clamper_test.cpp
//! @author Dejan D. M. Milosavljevic
//! @version 1.0
//! @date 2003
//! @description Test for clampers.
//! @warning  Use it at your own risk.
//! @copyright *this file is FREEWARE. 


#include <iostream>
#include <iomanip>

#include "clamper.hpp"

using namespace std;
using namespace S_DDMRM::S_math;

void graf( float P_len)
 {
  for(int i=0; i< P_len; i++ )
   cout<< " ";
   cout<< "*"<< endl;
 
 }

int main_clamper( int argc, char *argv[] )
 {
  cout << "main_clamper" << endl;

  double I_dval;
  for( I_dval=-3;  I_dval< 0.5; I_dval += 0.01)
   {
    cout << "ramp( " << I_dval << " ) = " << GF_ramp( I_dval ) << endl;
    cout << "saw( " << I_dval << " ) = " <<  GF_saw<double>( I_dval, 0.3, 0.8 )  << endl;
    cout << "wave( " << I_dval << " ) = " << GF_wave<double>( I_dval, 0.3, 0.8 ) << endl;
    cout << "to_one<double>( " << I_dval << ", -5, 5 ) = " << GF_to_one<double>( I_dval, -5, 5 ) << endl;
   }
   
   
  float I_fval;
  for( I_fval = float(-5);  I_fval< float(5); I_fval += float( 0.1 ))
   {
    cout << "ramp( " << I_fval << " ) = " << GF_ramp( I_fval ) << endl;
    cout << "saw( " << I_fval << " ) = " << GF_saw( I_fval )  << endl;
    cout << "wave( " << I_fval << " ) = " << GF_wave( I_fval ) << endl;
    cout << "to_one<float>( " << I_fval << ", -5, 5 ) = " << GF_to_one<float>( I_fval, -5, 5 ) << endl;
   }
  
  //cin.get();

  return 0;
 }

