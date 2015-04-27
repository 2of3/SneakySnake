%module cpp   
%{  

	//#include "cpp_file.h"
	#include "uniplug_blender_api.h"
%} 
 
%include <windows.i>
%include "std_string.i"
%include "typemaps.i"
//%include "arrays_csharp.i"


//%apply float INPUT[]  { float* ANY }
//%apply float OUTPUT[] { float* a2 }*/


//%typemap(ctype) Fusee.Math.float3   "float $1[3] /* typemap(cstype) float3 %1[3] to float[3]*/"


//Map int* to int
%typemap(ctype)  int * "int *"
%typemap(imtype) int * "IntPtr"
%typemap(cstype) int * "int"
%typemap(csin)   int * "$csinput"
%typemap(in)     int * %{ $1 = $input; %}
%typemap(out)    int * %{ $result = $1; %}
%typemap(csout)  int * { return $imcall; }





// Map float[3] TO   Fusee.Math.float3
%typemap(cstype, out="$csclassname") float[3] "Fusee.Math.float3 /* float[3]_cstype */"
%typemap(csin) float[3] " $csinput /* float[3]_csin */"
%typemap(imtype, out="global::System.IntPtr") float[3] "Fusee.Math.float3 /* float[3]_imtype */"

// Map float[3] TO   ref Fusee.Math.float3
//%typemap(cstype, out="$csclassname") float[3] "ref Fusee.Math.float3 /* float[3]&_cstype */"
//%typemap(csin) float[3] " ref $csinput /* float[3]&_csin */"
//%typemap(imtype, out="global::System.IntPtr") float[3] "ref Fusee.Math.float3 /* float[3]&_imtype */"


// Map float $1[Any] TO  float[3]
%typemap(cstype, out="$csclassname") float[] "float[] /* float[]_cstype */"
%typemap(csin) float[Any] " $csinput /* float[]_csin */"
%typemap(imtype, out="global::System.IntPtr") float[] "float[] /* float[]_imtype */"

// Map int $1[Any] TO  int[]
%typemap(cstype, out="$csclassname") int[] "int[] /* int[]_cstype */"
%typemap(csin) int[Any] " $csinput /* int[]_csin */"
%typemap(imtype, out="global::System.IntPtr") int[] "int[] /* int[]_imtype */"


// Map int $1[3] TO  int[3]
%typemap(cstype, out="$csclassname") int[3] "int[3] /* int[3]_cstype */"
%typemap(csin) int[Any] " $csinput /* int[3]_csin */"
%typemap(imtype, out="global::System.IntPtr") int[3] "int[3] /* int[3]_imtype */"

//%include "cpp_file.h"
%include "uniplug_blender_api.h"


