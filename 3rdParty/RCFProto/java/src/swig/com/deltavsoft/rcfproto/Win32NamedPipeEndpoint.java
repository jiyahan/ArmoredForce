/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 2.0.4
 *
 * Do not make changes to this file unless you know what you are doing--modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */

package com.deltavsoft.rcfproto;

/**
 * Represents a Win32 named pipe endpoint. Only available on Windows platforms. 
 */
public class Win32NamedPipeEndpoint extends Endpoint {
  private long swigCPtr;

  Win32NamedPipeEndpoint(long cPtr, boolean cMemoryOwn) {
    super(RCFProtoJNI.Win32NamedPipeEndpoint_SWIGUpcast(cPtr), cMemoryOwn);
    swigCPtr = cPtr;
  }

  static long getCPtr(Win32NamedPipeEndpoint obj) {
    return (obj == null) ? 0 : obj.swigCPtr;
  }

  protected void finalize() {
    delete();
  }

  public synchronized void delete() {
    if (swigCPtr != 0) {
      if (swigCMemOwn) {
        swigCMemOwn = false;
        RCFProtoJNI.delete_Win32NamedPipeEndpoint(swigCPtr);
      }
      swigCPtr = 0;
    }
    super.delete();
  }

  /**
   * Constructs a Win32 named pipe endpoint with the given pipe name. 
   */
  public Win32NamedPipeEndpoint(String pipeName) {
    this(RCFProtoJNI.new_Win32NamedPipeEndpoint(pipeName), true);
  }

}
