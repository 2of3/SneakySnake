%module cpp   
%{  

	#include "uniplug_blender_api.h"
%} 
 
%include <windows.i>
//*%include "arrays_csharp.i"

//%apply float INPUT[]  { float* ANY }
//%apply float OUTPUT[] { float* a2 }*/

// Map float[3]   TO   Fusee.Math.float3
%typemap(in) float[3] 
%{ /* <Matrix_in> */ 
   $1 = (float*) $input; 
   /* </Matrix_in> */%}
%typemap(out) float* 
%{ /* <Matrix_out> */ 
   $result = *((Matrix_POD *)(&$1)); 
   /* </Matrix_out> */%}
%typemap(cstype) float[3]   "Fusee.Math.float3 /* typemap(cstype) */"
%typemap(csin, 
   pre="    float[] adbl_$csinput;\n"
       "    unsafe {adbl_$csinput = Fusee.Math.ArrayConvert.float3ToBlenderfloatArray($csinput); /*convert from float3 to float[3]*/"
       "    fixed (float *pdbl_$csinput = adbl_$csinput) {\n"
       "    /* Matrix_csin_pre */", 
   terminator="} } /* Matrix_csin_terminator */"
  ) float[3]
"(System.IntPtr) pdbl_$csinput /*  Matrix_csin */"
%typemap(imtype, out="BVec3 /* float[3]_imtype_out see C34M (struct of 3 floats) */") float[3]  "System.IntPtr /* float[3] _imtype */"

//%typemap(out) float[] 



%include "uniplug_blender_api.h"







