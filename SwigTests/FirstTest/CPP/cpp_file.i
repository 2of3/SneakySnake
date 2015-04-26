%module cpp   
%{  

	#include "cpp_file.h"
%} 
 
%include <windows.i>
//*%include "arrays_csharp.i"

//%apply float INPUT[]  { float* ANY }
//%apply float OUTPUT[] { float* a2 }*/


//%typemap(ctype) Fusee.Math.float3   "float $1[3] /* typemap(cstype) float3 %1[3] to float[3]*/"


// Map float[3] TO   ref Fusee.Math.float3
%typemap(cstype, out="$csclassname") float[3] "ref Fusee.Math.float3 /* float[3]&_cstype */"
%typemap(csin) float[3] " ref $csinput /* float[3]&_csin */"
%typemap(imtype, out="global::System.IntPtr") float[3] "ref Fusee.Math.float3 /* float[3]&_imtype */"


%include "cpp_file.h"


