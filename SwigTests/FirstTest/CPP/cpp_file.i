%module cpp   
%{  

	#include "cpp_file.h"
%} 
 
%include <windows.i>
//*%include "arrays_csharp.i"

//%apply float INPUT[]  { float* ANY }
//%apply float OUTPUT[] { float* a2 }*/


//%typemap(ctype) Fusee.Math.float3   "float $1[3] /* typemap(cstype) float3 %1[3] to float[3]*/"
//%typemap(cstype) float[3]   "Fusee.Math.float3 /* typemap(cstype) float %1[3] to float3*/"



// Map float[3] and &   TO   ref Fusee.Math.float3
%typemap(cstype, out="$csclassname") float[3], float & "ref Fusee.Math.float3 /* Vector*&_cstype */"
%typemap(csin) float[3] " ref $csinput /* float*&_csin */"
%typemap(imtype, out="global::System.IntPtr") float[3] "ref Fusee.Math.float3 /* Vector*&_imtype */"
%typemap(in) float[3] "$1 = ($1_ltype)$input; /* float[3]&_in */"
//%typemap(csdirectorout) float[3] "$cscall /* float[3]&_csdirectorout */"


%include "cpp_file.h"


