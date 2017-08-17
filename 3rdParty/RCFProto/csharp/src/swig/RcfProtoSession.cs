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
/// Represents the server-side session associated with a RPC connection. 
/// </summary>
public class RcfProtoSession : IDisposable {
  private HandleRef swigCPtr;
  protected bool swigCMemOwn;

  internal RcfProtoSession(IntPtr cPtr, bool cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = new HandleRef(this, cPtr);
  }

  internal static HandleRef getCPtr(RcfProtoSession obj) {
    return (obj == null) ? new HandleRef(null, IntPtr.Zero) : obj.swigCPtr;
  }

  ~RcfProtoSession() {
    Dispose();
  }

  public virtual void Dispose() {
    lock(this) {
      if (swigCPtr.Handle != IntPtr.Zero) {
        if (swigCMemOwn) {
          swigCMemOwn = false;
          RCFProtoPINVOKE.delete_RcfProtoSession(swigCPtr);
        }
        swigCPtr = new HandleRef(null, IntPtr.Zero);
      }
      GC.SuppressFinalize(this);
    }
  }

  internal int _GetRequestBufferLength() {
    int ret = RCFProtoPINVOKE.RcfProtoSession__GetRequestBufferLength(swigCPtr);
    if (RCFProtoPINVOKE.SWIGPendingException.Pending) throw RCFProtoPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  internal void _GetRequestBuffer(byte[] szBuffer, int szBufferLen) {
    RCFProtoPINVOKE.RcfProtoSession__GetRequestBuffer(swigCPtr, szBuffer, szBufferLen);
    if (RCFProtoPINVOKE.SWIGPendingException.Pending) throw RCFProtoPINVOKE.SWIGPendingException.Retrieve();
  }

  internal void _SetResponseBuffer(byte[] szBuffer, int szBufferLen) {
    RCFProtoPINVOKE.RcfProtoSession__SetResponseBuffer(swigCPtr, szBuffer, szBufferLen);
    if (RCFProtoPINVOKE.SWIGPendingException.Pending) throw RCFProtoPINVOKE.SWIGPendingException.Retrieve();
  }

  /// <summary>
  /// Causes Failed() to return true on the client side.  "reason" will be incorporated into the message returned by ErrorText().  If you find you need to return machine-readable information about failures, you should incorporate it into your response protocol buffer and should NOT call SetFailed(). 
  /// </summary>
  public void SetFailed(string reason) {
    RCFProtoPINVOKE.RcfProtoSession_SetFailed(swigCPtr, reason);
    if (RCFProtoPINVOKE.SWIGPendingException.Pending) throw RCFProtoPINVOKE.SWIGPendingException.Retrieve();
  }

  /// <summary>
  /// If true, indicates that the client canceled the RPC, so the server may as well give up on replying to it.  The server should still call the final "done" callback. 
  /// </summary>
  public bool IsCanceled() {
    bool ret = RCFProtoPINVOKE.RcfProtoSession_IsCanceled(swigCPtr);
    if (RCFProtoPINVOKE.SWIGPendingException.Pending) throw RCFProtoPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  internal void _Commit(string errorMsg) {
    RCFProtoPINVOKE.RcfProtoSession__Commit__SWIG_0(swigCPtr, errorMsg);
    if (RCFProtoPINVOKE.SWIGPendingException.Pending) throw RCFProtoPINVOKE.SWIGPendingException.Retrieve();
  }

  internal void _Commit() {
    RCFProtoPINVOKE.RcfProtoSession__Commit__SWIG_1(swigCPtr);
    if (RCFProtoPINVOKE.SWIGPendingException.Pending) throw RCFProtoPINVOKE.SWIGPendingException.Retrieve();
  }

  internal string _GetRequestBuffer_WithCopy() {
    string ret = RCFProtoPINVOKE.RcfProtoSession__GetRequestBuffer_WithCopy(swigCPtr);
    if (RCFProtoPINVOKE.SWIGPendingException.Pending) throw RCFProtoPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  internal void _SetResponseBuffer_WithCopy(string buffer) {
    RCFProtoPINVOKE.RcfProtoSession__SetResponseBuffer_WithCopy(swigCPtr, buffer);
    if (RCFProtoPINVOKE.SWIGPendingException.Pending) throw RCFProtoPINVOKE.SWIGPendingException.Retrieve();
  }

  /// <summary>
  /// Returns the Windows username of the client, if a NTLM or Kerberos transport protocol is being used. 
  /// </summary>
  public string GetClientUsername() {
    string ret = RCFProtoPINVOKE.RcfProtoSession_getClientUsername(swigCPtr);
    if (RCFProtoPINVOKE.SWIGPendingException.Pending) throw RCFProtoPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  /// <summary>
  /// Returns the transport protocol in use on this server session. 
  /// </summary>
  public TransportProtocol GetTransportProtocol() {
    TransportProtocol ret = (TransportProtocol)RCFProtoPINVOKE.RcfProtoSession_getTransportProtocol(swigCPtr);
    if (RCFProtoPINVOKE.SWIGPendingException.Pending) throw RCFProtoPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  /// <summary>
  /// Returns the transport type of this server session. 
  /// </summary>
  public TransportType GetTransportType() {
    TransportType ret = (TransportType)RCFProtoPINVOKE.RcfProtoSession_getTransportType(swigCPtr);
    if (RCFProtoPINVOKE.SWIGPendingException.Pending) throw RCFProtoPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  /// <summary>
  /// Returns true if compression is enabled for this server session, and false otherwise. Compression is enabled by the client. 
  /// </summary>
  public bool GetEnableCompression() {
    bool ret = RCFProtoPINVOKE.RcfProtoSession_getEnableCompression(swigCPtr);
    if (RCFProtoPINVOKE.SWIGPendingException.Pending) throw RCFProtoPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  /// <summary>
  /// Returns the duration of the client connection, in milliseconds. 
  /// </summary>
  public uint GetConnectionDuration() {
    uint ret = RCFProtoPINVOKE.RcfProtoSession_getConnectionDuration(swigCPtr);
    if (RCFProtoPINVOKE.SWIGPendingException.Pending) throw RCFProtoPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  /// <summary>
  /// Returns the number of remote calls executed on the server session so far. 
  /// </summary>
  public uint GetRemoteCallCount() {
    uint ret = RCFProtoPINVOKE.RcfProtoSession_getRemoteCallCount(swigCPtr);
    if (RCFProtoPINVOKE.SWIGPendingException.Pending) throw RCFProtoPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  /// <summary>
  /// Returns the total number of bytes received by the server session so far. 
  /// </summary>
  public ulong GetTotalBytesReceived() {
    ulong ret = RCFProtoPINVOKE.RcfProtoSession_getTotalBytesReceived(swigCPtr);
    if (RCFProtoPINVOKE.SWIGPendingException.Pending) throw RCFProtoPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  /// <summary>
  /// Returns the total number of bytes sent from the server session so far. 
  /// </summary>
  public ulong GetTotalBytesSent() {
    ulong ret = RCFProtoPINVOKE.RcfProtoSession_getTotalBytesSent(swigCPtr);
    if (RCFProtoPINVOKE.SWIGPendingException.Pending) throw RCFProtoPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

}

}