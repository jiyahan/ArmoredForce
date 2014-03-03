/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 2.0.4
 *
 * Do not make changes to this file unless you know what you are doing--modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */

namespace DeltaVSoft.RCFProto {

using System;
using System.Runtime.InteropServices;

/// <summary>
/// Represents an in-memory certificate, usually from a remote peer. Only applicable to Schannel. 
/// </summary>
public class Win32Certificate : Certificate {
  private HandleRef swigCPtr;
  private bool swigCMemOwnDerived;

  internal Win32Certificate(IntPtr cPtr, bool cMemoryOwn) : base(RCFProtoPINVOKE.Win32Certificate_SWIGSmartPtrUpcast(cPtr), true) {
    swigCMemOwnDerived = cMemoryOwn;
    swigCPtr = new HandleRef(this, cPtr);
  }

  internal static HandleRef getCPtr(Win32Certificate obj) {
    return (obj == null) ? new HandleRef(null, IntPtr.Zero) : obj.swigCPtr;
  }

  ~Win32Certificate() {
    Dispose();
  }

  public override void Dispose() {
    lock(this) {
      if (swigCPtr.Handle != IntPtr.Zero) {
        if (swigCMemOwnDerived) {
          swigCMemOwnDerived = false;
          RCFProtoPINVOKE.delete_Win32Certificate(swigCPtr);
        }
        swigCPtr = new HandleRef(null, IntPtr.Zero);
      }
      GC.SuppressFinalize(this);
      base.Dispose();
    }
  }

  internal override CertificateImplementationType _getType() {
    CertificateImplementationType ret = (CertificateImplementationType)RCFProtoPINVOKE.Win32Certificate__getType(swigCPtr);
    if (RCFProtoPINVOKE.SWIGPendingException.Pending) throw RCFProtoPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  /// <summary>
  /// Gets the name of the certificate. 
  /// </summary>
  public string GetCertificateName() {
    string ret = RCFProtoPINVOKE.Win32Certificate_getCertificateName(swigCPtr);
    if (RCFProtoPINVOKE.SWIGPendingException.Pending) throw RCFProtoPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  /// <summary>
  /// Gets the name of the issuer of the certificate. 
  /// </summary>
  public string GetIssuerName() {
    string ret = RCFProtoPINVOKE.Win32Certificate_getIssuerName(swigCPtr);
    if (RCFProtoPINVOKE.SWIGPendingException.Pending) throw RCFProtoPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  /// <summary>
  /// Exports the certificate in PFX format, to the given file path. 
  /// </summary>
  public void ExportToPfx(string pfxFilePath) {
    RCFProtoPINVOKE.Win32Certificate_exportToPfx(swigCPtr, pfxFilePath);
    if (RCFProtoPINVOKE.SWIGPendingException.Pending) throw RCFProtoPINVOKE.SWIGPendingException.Retrieve();
  }

  /// <summary>
  /// Attempts to locate a root certificate for this certificate, in the given certificate store. Returns the root certificate if found, and otherwise null. 
  /// </summary>
  public Win32Certificate FindRootCertificate(Win32CertificateLocation certStoreLocation, Win32CertificateStore certStore) {
    IntPtr cPtr = RCFProtoPINVOKE.Win32Certificate_findRootCertificate(swigCPtr, (int)certStoreLocation, (int)certStore);
    Win32Certificate ret = (cPtr == IntPtr.Zero) ? null : new Win32Certificate(cPtr, true);
    if (RCFProtoPINVOKE.SWIGPendingException.Pending) throw RCFProtoPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

}

}
