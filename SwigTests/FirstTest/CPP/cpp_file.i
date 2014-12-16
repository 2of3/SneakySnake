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
%include "btVector3.h"
%include "btAabbUtil2.h"
%include "btAlignedObjectArray.h"
%include "btConvexHull.h" 
%include "btConvexHullComputer.h"
%include "btCpuFeatureUtility.h"
%include "btDefaultMotionState.h"

//Ignore function isInside, only functionhead exists and causes errors
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

//Ignore function Enter_Largest_Child, only functionhead exists and causes errors
%ignore btQuickprof::Enter_Largest_Child
%include "btQuickprof.h"

%include "btRandom.h"
%include "btSerializer.h"
%include "btStackAlloc.h"
%include "btTransform.h"
%include "btTransformUtil.h"


