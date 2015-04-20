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
%typemap(csdirectorin, 
   pre="    Fusee.Math.float3 vec_$iminput;\n"
       "    unsafe {/* unsafe blaa*/ vec_$iminput = Fusee.Math.ArrayConvert.ArrayDoubleTodouble3((double *)$iminput);}\n"
       "    /* Vector*&_csdirectorin_pre */", 
   post="        unsafe {Fusee.Math.ArrayConvert.double3ToArrayDouble(vec_$iminput, (double *)$iminput);}\n"
        "        /* Vector*&_csdirectorin_post */"
  ) float[3]
  "ref vec_$iminput /* float[3]&_csdirectorin */"
%typemap(csdirectorout) float[3] "$cscall /* Vector*&_csdirectorout */"


%include "cpp_file.h"


