%module cpp   
%{  

	//#include "cpp_file.h"
	#include "uniplug_blender_api.h"
%} 
 
%include <windows.i>
%include "std_string.i"
%include "typemaps.i"

//%typemap(ctype) Fusee.Math.float3   "float $1[3] /* typemap(cstype) float3 %1[3] to float[3]*/"



//Map int* to int - old version
//%typemap(ctype)  int * "int * /* int*_ctype */"
//%typemap(imtype) int * "IntPtr /* int*_imtype */"
//%typemap(cstype) int * "int /* int*_cstype */"
//%typemap(csin)   int * "$csinput /* int*_csin */"
//%typemap(in)     int * %{ $1 = $input; %}
//%typemap(out)    int * %{ $result = $1; %}
//%typemap(csout)  int * { return $imcall; }


//Map int* to int - in progress
%typemap(ctype)  int * "int * /* int*_ctype */"
%typemap(imtype) int * "System.IntPtr /* int*_imtype */"
%typemap(cstype) int * "int /* int*_cstype */"
%typemap(csin)   int * "$csinput /* int*_csin */"
%typemap(in)     int * %{ $1 = $input /* int*_in */; %}
%typemap(out)    int * %{ $result = $1 /* int*_out */; %}
%typemap(csout)  int * { return (int)$imcall /* int*_csout */; }



/************* mapping float types *****************************/
// Map float $1[ANY] TO  float[]
%typemap(cstype, out="$csclassname") float[ANY] "float[] /* float[]_cstype */"
%typemap(csin) float[ANY] " $csinput /* float[]_csin */"
%typemap(imtype, out="global::System.IntPtr") float[ANY] "float[] /* float[]_imtype */"

// Map float[3] TO   Fusee.Math.float3
%typemap(cstype, out="$csclassname") float[3] "Fusee.Math.float3 /* float[3]_cstype */"
%typemap(csin) float[3] " $csinput /* float[3]_csin */"
%typemap(imtype, out="global::System.IntPtr") float[3] "Fusee.Math.float3 /* float[3]_imtype */"

// Map float[3] TO   ref Fusee.Math.float3
//%typemap(cstype, out="$csclassname") float[3] "ref Fusee.Math.float3 /* float[3]&_cstype */"
//%typemap(csin) float[3] " ref $csinput /* float[3]&_csin */"
//%typemap(imtype, out="global::System.IntPtr") float[3] "ref Fusee.Math.float3 /* float[3]&_imtype */"


/************mapping int types **********************************/
// Map int $1[ANY] TO  int[]
%typemap(cstype, out="$csclassname") int[ANY] "int[] /* int[]_cstype */"
%typemap(csin) int[ANY] " $csinput /* int[]_csin */"
%typemap(imtype, out="global::System.IntPtr") int[ANY] "int[] /* int[]_imtype */"


// Map int $1[3] TO  int[3]
%typemap(cstype, out="$csclassname") int $1[3] "int[3] /* int[3]_cstype */"
%typemap(csin) int $1[3] " $csinput /* int[3]_csin */"
%typemap(imtype, out="global::System.IntPtr") int $1[3] "int[3] /* int[3]_imtype */"


/***************maping bool types ****************************/
// Map bool $1[ANY] TO  bool[]
%typemap(cstype, out="$csclassname") bool[ANY] "bool[] /* bool[]_cstype */"
%typemap(csin) bool[ANY] " $csinput /* bool[]_csin */"
%typemap(imtype, out="global::System.IntPtr") bool[ANY] "bool[] /* bool[]_imtype */"

//%include "cpp_file.h"
%include "uniplug_blender_api.h"


