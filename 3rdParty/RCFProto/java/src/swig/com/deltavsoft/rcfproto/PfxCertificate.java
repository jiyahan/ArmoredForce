/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 2.0.4
 *
 * Do not make changes to this file unless you know what you are doing--modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */

package com.deltavsoft.rcfproto;

/**
 * Use this class to load a certificate from .pfx format. Only applicable to Schannel. 
 */
public class PfxCertificate extends Win32Certificate {
  private long swigCPtr;
  private boolean swigCMemOwnDerived;

  PfxCertificate(long cPtr, boolean cMemoryOwn) {
    super(RCFProtoJNI.PfxCertificate_SWIGSmartPtrUpcast(cPtr), true);
    swigCMemOwnDerived = cMemoryOwn;
    swigCPtr = cPtr;
  }

  protected static long getCPtr(PfxCertificate obj) {
    return (obj == null) ? 0 : obj.swigCPtr;
  }

  protected void finalize() {
    delete();
  }

  public synchronized void delete() {
    if (swigCPtr != 0) {
      if (swigCMemOwnDerived) {
        swigCMemOwnDerived = false;
        RCFProtoJNI.delete_PfxCertificate(swigCPtr);
      }
      swigCPtr = 0;
    }
    super.delete();
  }

  /**
   * Loads a certificate from a .pfx file, using the given file path, password and certificate name. 
   */
  public PfxCertificate(String pathToCert, String password, String certName) {
    this(RCFProtoJNI.new_PfxCertificate(pathToCert, password, certName), true);
  }

  /**
   * Adds the certificate to the given Windows certificate store. 
   */
  public void addToStore(Win32CertificateLocation certStoreLocation, Win32CertificateStore certStore) {
    RCFProtoJNI.PfxCertificate_addToStore(swigCPtr, this, certStoreLocation.swigValue(), certStore.swigValue());
  }

}
