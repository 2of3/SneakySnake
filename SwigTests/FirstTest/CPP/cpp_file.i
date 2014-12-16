%module cpp  
  
%{  
    #include "cpp_file.h" 
	#include "btScalar.h"
	#include "btVector3.h"
	#include "btAabbUtil2.h"
	#include "btAlignedObjectArray.h"
	#include "btConvexHull.h"
	#include "btConvexHullComputer.h"
	#include "btCpuFeatureUtility.h"
	#include "btDefaultMotionState.h"	
	#include "btGeometryUtil.h"
	#include "btGrahamScan2dConvexHull.h"
	#include "btHashMap.h"
	#include "btIDebugDraw.h"
	#include "btList.h"
	#include "btMatrix3x3.h"
	#include "btMatrixX.h"
	#include "btMinMax.h"
	#include "btMotionState.h"
	#include "btPolarDecomposition.h"
	#include "btPoolAllocator.h"
	#include "btQuadWord.h"
	#include "btQuaternion.h"
	#include "btQuickprof.h"
	#include "btRandom.h"
	#include "btSerializer.h"
	#include "btStackAlloc.h"
	#include "btTransform.h"
	#include "btTransformUtil.h"

	   
%}  
%include <windows.i>  

%rename(times2_neu) cpp_file::times2(int arg);
%ignore cpp_file::test;  

%include "cpp_file.h"
%include "btScalar.h" //include btScalar before the anything else, it defines datatypes


// Map const btVector3 &  TO  Fusee.Math.float3
%typemap(cstype, out="Fusee.Math.float3 /* constbtVector3&_cstype_out */") const btVector3 & "Fusee.Math.float3 /* constbtVector3&_cstype */"
%typemap(csin) const btVector3 & "ref $csinput /* constbtVector3&_csin */"
%typemap(imtype, out="global::System.IntPtr /* constbtVector3&_imtype_out */") const btVector3 & "ref Fusee.Math.float3 /* constbtVector3&_imtype */"
%typemap(csout, excode=SWIGEXCODE) const btVector3 &
%{ {  /* <constbtVector3&_csout> */
      global::System.IntPtr p_ret = $imcall;$excode
      Fusee.Math.float3 ret;
      unsafe {ret = Fusee.Math.ArrayConvert.ArrayDoubleTofloat3((double *)p_ret);}
      return ret;
   } /* </constbtVector3&_csout> */ %}
%typemap(csdirectorin, 
   pre="    Fusee.Math.float3 vec_$iminput;\n"
       "    unsafe {vec_$iminput = Fusee.Math.ArrayConvert.ArrayDoubleTofloat3((double *)$iminput);}\n"
       "    /* constbtVector3&_csdirectorin_pre */", 
   post="        /* no re-conversion because of const declaration */\n"
        "        /* constbtVector3&_csdirectorin_post */"
  ) const btVector3 &
  "vec_$iminput /* btVector3*&_csdirectorin */"



%include "btVector3.h"
%include "btAabbUtil2.h"
%include "btAlignedObjectArray.h"
%include "btConvexHull.h" 
%include "btConvexHullComputer.h"
%include "btCpuFeatureUtility.h"
%include "btDefaultMotionState.h"

%ignore btGeometryUtil::isInside;  
%include "btGeometryUtil.h"

%include "btGrahamScan2dConvexHull.h"
%include "btHashMap.h"
%include "btIDebugDraw.h"
%include "btList.h"
%include "btMatrix3x3.h"
%include "btMatrixX.h"
%include "btMinMax.h"
%include "btMotionState.h"
%include "btPolarDecomposition.h"
%include "btPoolAllocator.h"
%include "btQuadWord.h"
%include "btQuaternion.h"

%ignore CProfileIterator::Enter_Largest_Child;  
%include "btQuickprof.h"

%include "btRandom.h"
%include "btSerializer.h"
%include "btStackAlloc.h"
%include "btTransform.h"
%include "btTransformUtil.h"


