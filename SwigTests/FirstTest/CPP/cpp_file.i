%module cpp   
%{  

	//#include "cpp_file.h"
	//#include "Foo.h"
	//#include "Bar.h"
	#include "uniplug_blender_api.h"

	struct Vector
	{
		float x,y,z;
	};
%} 
 

%include <windows.i>
%include "arrays_csharp.i"
%include "std_string.i"
%include "cpointer.i"
%include "typemaps.i"





// Map std::array<float, 3>   TO   Fusee.Math.float3
%typemap(cstype, out="Fusee.Math.float3 /* std::array<float, 3>_cstype_out */") std::array<float, 3> "Fusee.Math.float3 /* std::array<float, 3>_cstype */"
%typemap(csout, excode=SWIGEXCODE) std::array<float, 3> 
%{ {  /* <std::array<float, 3>_csout> */
      Fusee.Math.float3 ret = $imcall;$excode
      return ret;
   } /* <std::array<float, 3>_csout> */ %}
%typemap(imtype, out="Fusee.Math.float3 /* std::array<float, 3>_imtype_out */") std::array<float, 3> "Fusee.Math.float3 /* std::array<float, 3>_imtype */"
%typemap(ctype, out="Vector /* std::array<float, 3>_ctype_out */") std::array<float, 3> "std::array<float, 3> /* std::array<float, 3>_ctype */"
%typemap(directorout) std::array<float, 3>
%{ /* <std::array<float, 3>_directorout> */
   $result = *((std::array<float, 3> *)&($input)); 
   /* </std::array<float, 3>_directorout> */
 %}
%typemap(directorin) std::array<float, 3> 
%{ /* <std::array<float, 3>_directorin> */
   $input = *((Vector *)&($1)); 
   /* </std::array<float, 3>_directorin> */ 
%}
%typemap(out) std::array<float, 3> 
%{
	/* <std::array<float, 3>_out> */
	$result = *((Vector *)&($1));
	/* </std::array<float, 3>_out> */
%}
%typemap(in) std::array<float, 3> 
%{
	/* <std::array<float, 3>_in> */
	$1 = *((std::array<float, 3> *)&($input));
	/* </std::array<float, 3>_in> */
%}
%typemap(csin) std::array<float, 3> "$csinput /* std::array<float, 3>_csin */"
%typemap(csdirectorin, 
   pre="/* NOP std::array<float, 3>_csdirectorin_pre */"
  ) std::array<float, 3>
  "$iminput /* std::array<float, 3>_csdirectorin */"
%typemap(csdirectorout) std::array<float, 3> "$cscall /* std::array<float, 3>_csdirectorout */"
%typemap(csvarin) std::array<float, 3> %{
    /* <std::array<float, 3>_csvarin> */
    set 
	{
      $imcall;$excode
    }  /* </std::array<float, 3>_csvarin> */  %}
%typemap(csvarout) std::array<float, 3> %{ 
   /* <std::array<float, 3>_csvarout> */
   get
   {  
      Fusee.Math.float3 ret = $imcall;$excode
      return ret;
   } /* <std::array<float, 3>_csvarout> */ %}


////Map std::array<float,3> To Fusee.Math.float3
//%typemap(ctype)  std::array<float, 3> "std::array<float, 3> /* std::array<float, 3>_ctype */"
//%typemap(imtype) std::array<float, 3> "Fusee.Math.float3 /* Fusee.Math.float3*_imtype */"
//%typemap(cstype) std::array<float, 3> "Fusee.Math.float3 /* iFusee.Math.float3_cstype */"
//%typemap(csin)   std::array<float, 3> "$csinput /* Fusee.Math.float3_csin */"
//%typemap(in)     std::array<float, 3> %{ $1 = $input /* Fusee.Math.float3 in*/; %}
//%typemap(out)    std::array<float, 3> %{ /* Fusee.Math.float3 out*/$result = $1/* Fusee.Math.float3 out*/; %}
//%typemap(csout)  std::array<float, 3> { return $imcall/* Fusee.Math.float3 csout*/; }







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

//%include "cpp_file.h"
//%include "Foo.h"
//%include "Bar.h"
%include "uniplug_blender_api.h"


