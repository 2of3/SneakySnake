//------------------------------------------------------------------------------
// <auto-generated />
//
// This file was automatically generated by SWIG (http://www.swig.org).
// Version 3.0.5
//
// Do not make changes to this file unless you know what you are doing--modify
// the SWIG interface file instead.
//------------------------------------------------------------------------------


public class example {
  public static void myArrayCopy(int[] sourceArray, int[] targetArray, int nitems) {
    examplePINVOKE.myArrayCopy(sourceArray, targetArray, nitems);
  }

  public static void myArraySwap(int[] array1, int[] array2, int nitems) {
    examplePINVOKE.myArraySwap(array1, array2, nitems);
  }

  public unsafe static void myArrayCopyUsingFixedArrays(int[] sourceArray, int[] targetArray, int nitems) {
    fixed ( int* swig_ptrTo_sourceArray = sourceArray ) {
    fixed ( int* swig_ptrTo_targetArray = targetArray ) {
    {
      examplePINVOKE.myArrayCopyUsingFixedArrays((global::System.IntPtr)swig_ptrTo_sourceArray, (global::System.IntPtr)swig_ptrTo_targetArray, nitems);
    }
    }
    }
  }

  public unsafe static void myArraySwapUsingFixedArrays(int[] array1, int[] array2, int nitems) {
    fixed ( int* swig_ptrTo_array1 = array1 ) {
    fixed ( int* swig_ptrTo_array2 = array2 ) {
    {
      examplePINVOKE.myArraySwapUsingFixedArrays((global::System.IntPtr)swig_ptrTo_array1, (global::System.IntPtr)swig_ptrTo_array2, nitems);
    }
    }
    }
  }

}
