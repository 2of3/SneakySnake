//------------------------------------------------------------------------------
// <auto-generated />
//
// This file was automatically generated by SWIG (http://www.swig.org).
// Version 3.0.5
//
// Do not make changes to this file unless you know what you are doing--modify
// the SWIG interface file instead.
//------------------------------------------------------------------------------


class examplePINVOKE {

  protected class SWIGExceptionHelper {

    public delegate void ExceptionDelegate(string message);
    public delegate void ExceptionArgumentDelegate(string message, string paramName);

    static ExceptionDelegate applicationDelegate = new ExceptionDelegate(SetPendingApplicationException);
    static ExceptionDelegate arithmeticDelegate = new ExceptionDelegate(SetPendingArithmeticException);
    static ExceptionDelegate divideByZeroDelegate = new ExceptionDelegate(SetPendingDivideByZeroException);
    static ExceptionDelegate indexOutOfRangeDelegate = new ExceptionDelegate(SetPendingIndexOutOfRangeException);
    static ExceptionDelegate invalidCastDelegate = new ExceptionDelegate(SetPendingInvalidCastException);
    static ExceptionDelegate invalidOperationDelegate = new ExceptionDelegate(SetPendingInvalidOperationException);
    static ExceptionDelegate ioDelegate = new ExceptionDelegate(SetPendingIOException);
    static ExceptionDelegate nullReferenceDelegate = new ExceptionDelegate(SetPendingNullReferenceException);
    static ExceptionDelegate outOfMemoryDelegate = new ExceptionDelegate(SetPendingOutOfMemoryException);
    static ExceptionDelegate overflowDelegate = new ExceptionDelegate(SetPendingOverflowException);
    static ExceptionDelegate systemDelegate = new ExceptionDelegate(SetPendingSystemException);

    static ExceptionArgumentDelegate argumentDelegate = new ExceptionArgumentDelegate(SetPendingArgumentException);
    static ExceptionArgumentDelegate argumentNullDelegate = new ExceptionArgumentDelegate(SetPendingArgumentNullException);
    static ExceptionArgumentDelegate argumentOutOfRangeDelegate = new ExceptionArgumentDelegate(SetPendingArgumentOutOfRangeException);

    [global::System.Runtime.InteropServices.DllImport("example", EntryPoint="SWIGRegisterExceptionCallbacks_example")]
    public static extern void SWIGRegisterExceptionCallbacks_example(
                                ExceptionDelegate applicationDelegate,
                                ExceptionDelegate arithmeticDelegate,
                                ExceptionDelegate divideByZeroDelegate, 
                                ExceptionDelegate indexOutOfRangeDelegate, 
                                ExceptionDelegate invalidCastDelegate,
                                ExceptionDelegate invalidOperationDelegate,
                                ExceptionDelegate ioDelegate,
                                ExceptionDelegate nullReferenceDelegate,
                                ExceptionDelegate outOfMemoryDelegate, 
                                ExceptionDelegate overflowDelegate, 
                                ExceptionDelegate systemExceptionDelegate);

    [global::System.Runtime.InteropServices.DllImport("example", EntryPoint="SWIGRegisterExceptionArgumentCallbacks_example")]
    public static extern void SWIGRegisterExceptionCallbacksArgument_example(
                                ExceptionArgumentDelegate argumentDelegate,
                                ExceptionArgumentDelegate argumentNullDelegate,
                                ExceptionArgumentDelegate argumentOutOfRangeDelegate);

    static void SetPendingApplicationException(string message) {
      SWIGPendingException.Set(new global::System.ApplicationException(message, SWIGPendingException.Retrieve()));
    }
    static void SetPendingArithmeticException(string message) {
      SWIGPendingException.Set(new global::System.ArithmeticException(message, SWIGPendingException.Retrieve()));
    }
    static void SetPendingDivideByZeroException(string message) {
      SWIGPendingException.Set(new global::System.DivideByZeroException(message, SWIGPendingException.Retrieve()));
    }
    static void SetPendingIndexOutOfRangeException(string message) {
      SWIGPendingException.Set(new global::System.IndexOutOfRangeException(message, SWIGPendingException.Retrieve()));
    }
    static void SetPendingInvalidCastException(string message) {
      SWIGPendingException.Set(new global::System.InvalidCastException(message, SWIGPendingException.Retrieve()));
    }
    static void SetPendingInvalidOperationException(string message) {
      SWIGPendingException.Set(new global::System.InvalidOperationException(message, SWIGPendingException.Retrieve()));
    }
    static void SetPendingIOException(string message) {
      SWIGPendingException.Set(new global::System.IO.IOException(message, SWIGPendingException.Retrieve()));
    }
    static void SetPendingNullReferenceException(string message) {
      SWIGPendingException.Set(new global::System.NullReferenceException(message, SWIGPendingException.Retrieve()));
    }
    static void SetPendingOutOfMemoryException(string message) {
      SWIGPendingException.Set(new global::System.OutOfMemoryException(message, SWIGPendingException.Retrieve()));
    }
    static void SetPendingOverflowException(string message) {
      SWIGPendingException.Set(new global::System.OverflowException(message, SWIGPendingException.Retrieve()));
    }
    static void SetPendingSystemException(string message) {
      SWIGPendingException.Set(new global::System.SystemException(message, SWIGPendingException.Retrieve()));
    }

    static void SetPendingArgumentException(string message, string paramName) {
      SWIGPendingException.Set(new global::System.ArgumentException(message, paramName, SWIGPendingException.Retrieve()));
    }
    static void SetPendingArgumentNullException(string message, string paramName) {
      global::System.Exception e = SWIGPendingException.Retrieve();
      if (e != null) message = message + " Inner Exception: " + e.Message;
      SWIGPendingException.Set(new global::System.ArgumentNullException(paramName, message));
    }
    static void SetPendingArgumentOutOfRangeException(string message, string paramName) {
      global::System.Exception e = SWIGPendingException.Retrieve();
      if (e != null) message = message + " Inner Exception: " + e.Message;
      SWIGPendingException.Set(new global::System.ArgumentOutOfRangeException(paramName, message));
    }

    static SWIGExceptionHelper() {
      SWIGRegisterExceptionCallbacks_example(
                                applicationDelegate,
                                arithmeticDelegate,
                                divideByZeroDelegate,
                                indexOutOfRangeDelegate,
                                invalidCastDelegate,
                                invalidOperationDelegate,
                                ioDelegate,
                                nullReferenceDelegate,
                                outOfMemoryDelegate,
                                overflowDelegate,
                                systemDelegate);

      SWIGRegisterExceptionCallbacksArgument_example(
                                argumentDelegate,
                                argumentNullDelegate,
                                argumentOutOfRangeDelegate);
    }
  }

  protected static SWIGExceptionHelper swigExceptionHelper = new SWIGExceptionHelper();

  public class SWIGPendingException {
    [global::System.ThreadStatic]
    private static global::System.Exception pendingException = null;
    private static int numExceptionsPending = 0;

    public static bool Pending {
      get {
        bool pending = false;
        if (numExceptionsPending > 0)
          if (pendingException != null)
            pending = true;
        return pending;
      } 
    }

    public static void Set(global::System.Exception e) {
      if (pendingException != null)
        throw new global::System.ApplicationException("FATAL: An earlier pending exception from unmanaged code was missed and thus not thrown (" + pendingException.ToString() + ")", e);
      pendingException = e;
      lock(typeof(examplePINVOKE)) {
        numExceptionsPending++;
      }
    }

    public static global::System.Exception Retrieve() {
      global::System.Exception e = null;
      if (numExceptionsPending > 0) {
        if (pendingException != null) {
          e = pendingException;
          pendingException = null;
          lock(typeof(examplePINVOKE)) {
            numExceptionsPending--;
          }
        }
      }
      return e;
    }
  }


  protected class SWIGStringHelper {

    public delegate string SWIGStringDelegate(string message);
    static SWIGStringDelegate stringDelegate = new SWIGStringDelegate(CreateString);

    [global::System.Runtime.InteropServices.DllImport("example", EntryPoint="SWIGRegisterStringCallback_example")]
    public static extern void SWIGRegisterStringCallback_example(SWIGStringDelegate stringDelegate);

    static string CreateString(string cString) {
      return cString;
    }

    static SWIGStringHelper() {
      SWIGRegisterStringCallback_example(stringDelegate);
    }
  }

  static protected SWIGStringHelper swigStringHelper = new SWIGStringHelper();


  static examplePINVOKE() {
  }


  [global::System.Runtime.InteropServices.DllImport("example", EntryPoint="CSharp_ivar_set")]
  public static extern void ivar_set(int jarg1);

  [global::System.Runtime.InteropServices.DllImport("example", EntryPoint="CSharp_ivar_get")]
  public static extern int ivar_get();

  [global::System.Runtime.InteropServices.DllImport("example", EntryPoint="CSharp_svar_set")]
  public static extern void svar_set(short jarg1);

  [global::System.Runtime.InteropServices.DllImport("example", EntryPoint="CSharp_svar_get")]
  public static extern short svar_get();

  [global::System.Runtime.InteropServices.DllImport("example", EntryPoint="CSharp_lvar_set")]
  public static extern void lvar_set(int jarg1);

  [global::System.Runtime.InteropServices.DllImport("example", EntryPoint="CSharp_lvar_get")]
  public static extern int lvar_get();

  [global::System.Runtime.InteropServices.DllImport("example", EntryPoint="CSharp_uivar_set")]
  public static extern void uivar_set(uint jarg1);

  [global::System.Runtime.InteropServices.DllImport("example", EntryPoint="CSharp_uivar_get")]
  public static extern uint uivar_get();

  [global::System.Runtime.InteropServices.DllImport("example", EntryPoint="CSharp_usvar_set")]
  public static extern void usvar_set(ushort jarg1);

  [global::System.Runtime.InteropServices.DllImport("example", EntryPoint="CSharp_usvar_get")]
  public static extern ushort usvar_get();

  [global::System.Runtime.InteropServices.DllImport("example", EntryPoint="CSharp_ulvar_set")]
  public static extern void ulvar_set(uint jarg1);

  [global::System.Runtime.InteropServices.DllImport("example", EntryPoint="CSharp_ulvar_get")]
  public static extern uint ulvar_get();

  [global::System.Runtime.InteropServices.DllImport("example", EntryPoint="CSharp_scvar_set")]
  public static extern void scvar_set(sbyte jarg1);

  [global::System.Runtime.InteropServices.DllImport("example", EntryPoint="CSharp_scvar_get")]
  public static extern sbyte scvar_get();

  [global::System.Runtime.InteropServices.DllImport("example", EntryPoint="CSharp_ucvar_set")]
  public static extern void ucvar_set(byte jarg1);

  [global::System.Runtime.InteropServices.DllImport("example", EntryPoint="CSharp_ucvar_get")]
  public static extern byte ucvar_get();

  [global::System.Runtime.InteropServices.DllImport("example", EntryPoint="CSharp_cvar_set")]
  public static extern void cvar_set(char jarg1);

  [global::System.Runtime.InteropServices.DllImport("example", EntryPoint="CSharp_cvar_get")]
  public static extern char cvar_get();

  [global::System.Runtime.InteropServices.DllImport("example", EntryPoint="CSharp_fvar_set")]
  public static extern void fvar_set(float jarg1);

  [global::System.Runtime.InteropServices.DllImport("example", EntryPoint="CSharp_fvar_get")]
  public static extern float fvar_get();

  [global::System.Runtime.InteropServices.DllImport("example", EntryPoint="CSharp_dvar_set")]
  public static extern void dvar_set(double jarg1);

  [global::System.Runtime.InteropServices.DllImport("example", EntryPoint="CSharp_dvar_get")]
  public static extern double dvar_get();

  [global::System.Runtime.InteropServices.DllImport("example", EntryPoint="CSharp_strvar_set")]
  public static extern void strvar_set(string jarg1);

  [global::System.Runtime.InteropServices.DllImport("example", EntryPoint="CSharp_strvar_get")]
  public static extern string strvar_get();

  [global::System.Runtime.InteropServices.DllImport("example", EntryPoint="CSharp_cstrvar_get")]
  public static extern string cstrvar_get();

  [global::System.Runtime.InteropServices.DllImport("example", EntryPoint="CSharp_iptrvar_set")]
  public static extern void iptrvar_set(global::System.Runtime.InteropServices.HandleRef jarg1);

  [global::System.Runtime.InteropServices.DllImport("example", EntryPoint="CSharp_iptrvar_get")]
  public static extern global::System.IntPtr iptrvar_get();

  [global::System.Runtime.InteropServices.DllImport("example", EntryPoint="CSharp_name_set")]
  public static extern void name_set(string jarg1);

  [global::System.Runtime.InteropServices.DllImport("example", EntryPoint="CSharp_name_get")]
  public static extern string name_get();

  [global::System.Runtime.InteropServices.DllImport("example", EntryPoint="CSharp_ptptr_set")]
  public static extern void ptptr_set(global::System.Runtime.InteropServices.HandleRef jarg1);

  [global::System.Runtime.InteropServices.DllImport("example", EntryPoint="CSharp_ptptr_get")]
  public static extern global::System.IntPtr ptptr_get();

  [global::System.Runtime.InteropServices.DllImport("example", EntryPoint="CSharp_pt_set")]
  public static extern void pt_set(global::System.Runtime.InteropServices.HandleRef jarg1);

  [global::System.Runtime.InteropServices.DllImport("example", EntryPoint="CSharp_pt_get")]
  public static extern global::System.IntPtr pt_get();

  [global::System.Runtime.InteropServices.DllImport("example", EntryPoint="CSharp_status_get")]
  public static extern int status_get();

  [global::System.Runtime.InteropServices.DllImport("example", EntryPoint="CSharp_path_get")]
  public static extern string path_get();

  [global::System.Runtime.InteropServices.DllImport("example", EntryPoint="CSharp_print_vars")]
  public static extern void print_vars();

  [global::System.Runtime.InteropServices.DllImport("example", EntryPoint="CSharp_new_int")]
  public static extern global::System.IntPtr new_int(int jarg1);

  [global::System.Runtime.InteropServices.DllImport("example", EntryPoint="CSharp_new_Point")]
  public static extern global::System.IntPtr new_Point(int jarg1, int jarg2);

  [global::System.Runtime.InteropServices.DllImport("example", EntryPoint="CSharp_Point_print")]
  public static extern string Point_print(global::System.Runtime.InteropServices.HandleRef jarg1);

  [global::System.Runtime.InteropServices.DllImport("example", EntryPoint="CSharp_pt_print")]
  public static extern void pt_print();
}
