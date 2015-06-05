%module cpp   
%{  

	#include "cpp_file.h"
	#include "Foo.h"
	//#include "uniplug_blender_api.h"
%} 
 

%include <windows.i>
%include "arrays_csharp.i"
%include "std_string.i"
%include "cpointer.i"
%include "typemaps.i"




//Map std::array<float,3> To Fusee.Math.float3
%typemap(ctype)  std::array<float, 3> "std::array<float, 3> /* std::array<float, 3>_ctype */"
%typemap(imtype) std::array<float, 3> "Fusee.Math.float3 /* Fusee.Math.float3*_imtype */"
%typemap(cstype) std::array<float, 3> "Fusee.Math.float3 /* iFusee.Math.float3_cstype */"
%typemap(csin)   std::array<float, 3> "$csinput /* Fusee.Math.float3_csin */"
%typemap(in)     std::array<float, 3> %{ $1 = $input /* Fusee.Math.float3 in*/; %}
%typemap(out)    std::array<float, 3> %{ /* Fusee.Math.float3 out*/$result = $1/* Fusee.Math.float3 out*/; %}
%typemap(csout)  std::array<float, 3> { return $imcall/* Fusee.Math.float3 csout*/; }




//Map int* to int - old version
//%typemap(ctype)  int * "int * /* int*_ctype */"
//%typemap(imtype) int * "int /* int*_imtype */"
//%typemap(cstype) int * "int /* int*_cstype */"
//%typemap(csin)   int * "$csinput /* int*_csin */"
//%typemap(in)     int * %{ $1 = $input; %}
//%typemap(out)    int * %{ $result = $1; %}
//%typemap(csout)  int * { return $imcall; }


/************* mapping float types *****************************/
// Map float $1[ANY] TO  float[]
%typemap(cstype, out="$csclassname") float[ANY] "float[] /* float[]_cstype */"
%typemap(csin) float[ANY] " $csinput /* float[]_csin */"
%typemap(imtype) float[ANY] "float[] /* float[]_imtype */"

// Map float[3] TO   Fusee.Math.float3
//%typemap(cstype, out="$csclassname") float[3] "Fusee.Math.float3 /* float[3]_cstype */"
//%typemap(csin) float[3] " $csinput /* float[3]_csin */"
//%typemap(imtype) float[3] "Fusee.Math.float3 /* float[3]_imtype */"

// Map float[3] TO   ref Fusee.Math.float3
//%typemap(cstype, out="$csclassname") float[3] "ref Fusee.Math.float3 /* float[3]&_cstype */"
//%typemap(csin) float[3] " ref $csinput /* float[3]&_csin */"
//%typemap(imtype) float[3] "ref Fusee.Math.float3 /* float[3]&_imtype */"


/************mapping int types **********************************/
// Map int $1[ANY] TO  int[]
%typemap(cstype, out="$csclassname") int[ANY] "int[] /* int[]_cstype */"
%typemap(csin) int[ANY] " $csinput /* int[]_csin */"
%typemap(imtype) int[ANY] "int[] /* int[]_imtype */"


// Map int $1[3] TO  int[3]
%typemap(cstype, out="$csclassname") int $1[3] "int[3] /* int[3]_cstype */"
%typemap(csin) int $1[3] " $csinput /* int[3]_csin */"
%typemap(imtype) int $1[3] "int[3] /* int[3]_imtype */"


/***************maping bool types ****************************/
// Map bool $1[ANY] TO  bool[]
%typemap(cstype, out="$csclassname") bool[ANY] "bool[] /* bool[]_cstype */"
%typemap(csin) bool[ANY] " $csinput /* bool[]_csin */"
%typemap(imtype) bool[ANY] "bool[] /* bool[]_imtype */"

%include "cpp_file.h"
%include "Foo.h"
//%include "uniplug_blender_api.h"


