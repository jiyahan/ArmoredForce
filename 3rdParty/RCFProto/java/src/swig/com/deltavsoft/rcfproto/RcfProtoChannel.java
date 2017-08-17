/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 2.0.4
 *
 * Do not make changes to this file unless you know what you are doing--modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */

package com.deltavsoft.rcfproto;
import com.google.protobuf.*;
import com.google.protobuf.Descriptors.MethodDescriptor;


/**
 * Represents a single RPC connection to a server. 
 */
public class RcfProtoChannel implements com.google.protobuf.RpcChannel {

  // BEGIN INSERTED CODE

  @Override
  public void callMethod(MethodDescriptor method, RpcController controller,
    Message request, Message responsePrototype,
    RpcCallback<Message> done) {

      RcfProtoChannelImpl.callMethod(this, method, controller, request, responsePrototype, done);
  }

  public Message getResponse()
  {
      return RcfProtoChannelImpl.getResponse(this);
  }

  public void setCertificateValidationCallback(CertificateValidationCallback certValidationCallback)
  {
      mCertValidationCallback = certValidationCallback;
      
      if ( certValidationCallback != null )
      {
          mSwigCallbackCertificate = new SwigCallback_Certificate(this);
          _setCertificateValidationCallback(mSwigCallbackCertificate);
      }
  }

  public CertificateValidationCallback getCertificateValidationCallback()
  {
      return mCertValidationCallback;
  }


  Message                           mResponse;
  String                            mResponseError;

  SwigCallback_CallCompletion       mSwigCallback;
  RpcCallback<Message>              mDone;
  Message                           mResponsePrototype;

  CertificateValidationCallback     mCertValidationCallback;
  SwigCallback_Certificate          mSwigCallbackCertificate;

  // END INSERTED CODE


  private long swigCPtr;
  boolean swigCMemOwn;

  RcfProtoChannel(long cPtr, boolean cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = cPtr;
  }

  static long getCPtr(RcfProtoChannel obj) {
    return (obj == null) ? 0 : obj.swigCPtr;
  }

  protected void finalize() {
    delete();
  }

  public synchronized void delete() {
    if (swigCPtr != 0) {
      if (swigCMemOwn) {
        swigCMemOwn = false;
        RCFProtoJNI.delete_RcfProtoChannel(swigCPtr);
      }
      swigCPtr = 0;
    }
  }

  void _CallMethodSwig(String serviceName, int methodId, byte[] szBuffer, _SwigCallback closure) {
    RCFProtoJNI.RcfProtoChannel__CallMethodSwig(swigCPtr, this, serviceName, methodId, szBuffer, _SwigCallback.getCPtr(closure), closure);
  }

  int _GetResponseBufferLength() {
    return RCFProtoJNI.RcfProtoChannel__GetResponseBufferLength(swigCPtr, this);
  }

  void _GetResponseBuffer(byte[] szBuffer) {
    RCFProtoJNI.RcfProtoChannel__GetResponseBuffer(swigCPtr, this, szBuffer);
  }

  /**
   * Constructs a RPC channel from an endpoint. 
   */
  public RcfProtoChannel(Endpoint endpoint) {
    this(RCFProtoJNI.new_RcfProtoChannel(Endpoint.getCPtr(endpoint), endpoint), true);
  }

  void _CallMethodSwig_WithCopy(String serviceName, int methodId, String strBuffer, _SwigCallback closure) {
    RCFProtoJNI.RcfProtoChannel__CallMethodSwig_WithCopy(swigCPtr, this, serviceName, methodId, strBuffer, _SwigCallback.getCPtr(closure), closure);
  }

  String _GetResponseBuffer_WithCopy() {
    return RCFProtoJNI.RcfProtoChannel__GetResponseBuffer_WithCopy(swigCPtr, this);
  }

  /**
   * After a call has finished, returns true if the call failed.  The possible reasons for failure depend on the RPC implementation.  Failed() must not be called before a call has finished.  If Failed() returns true, the contents of the response message are undefined. 
   */
  public boolean failed() {
    return RCFProtoJNI.RcfProtoChannel_Failed(swigCPtr, this);
  }

  /**
   * If Failed() is true, returns a human-readable description of the error. 
   */
  public String errorText() {
    return RCFProtoJNI.RcfProtoChannel_ErrorText(swigCPtr, this);
  }

  /**
   * Advises the RPC system that the caller desires that the RPC call be canceled.  The RPC system may cancel it immediately, may wait awhile and then cancel it, or may not even cancel the call at all.  If the call is canceled, the "done" callback will still be called and the RpcController will indicate that the call failed at that time. 
   */
  public void startCancel() {
    RCFProtoJNI.RcfProtoChannel_StartCancel(swigCPtr, this);
  }

  public boolean completed() {
    return RCFProtoJNI.RcfProtoChannel_Completed(swigCPtr, this);
  }

  /**
   * Connects to the server. 
   */
  public void connect() {
    RCFProtoJNI.RcfProtoChannel_connect(swigCPtr, this);
  }

  /**
   * Disconencts from the server. 
   */
  public void disconnect() {
    RCFProtoJNI.RcfProtoChannel_disconnect(swigCPtr, this);
  }

  /**
   * Sets the remote call timeout value, in milliseconds. 
   */
  public void setRemoteCallTimeoutMs(long remoteCallTimeoutMs) {
    RCFProtoJNI.RcfProtoChannel_setRemoteCallTimeoutMs(swigCPtr, this, remoteCallTimeoutMs);
  }

  /**
   * Gets the remote call timeout value, in milliseconds. 
   */
  public long getRemoteCallTimeoutMs() {
    return RCFProtoJNI.RcfProtoChannel_getRemoteCallTimeoutMs(swigCPtr, this);
  }

  /**
   * Sets the connect timeout value, in milliseconds. 
   */
  public void setConnectTimeoutMs(long connectTimeoutMs) {
    RCFProtoJNI.RcfProtoChannel_setConnectTimeoutMs(swigCPtr, this, connectTimeoutMs);
  }

  /**
   * Gets the connect timeout value, in milliseconds. 
   */
  public long getConnectTimeoutMs() {
    return RCFProtoJNI.RcfProtoChannel_getConnectTimeoutMs(swigCPtr, this);
  }

  /**
   * Sets the transport protocol being used by the channel. 
   */
  public void setTransportProtocol(TransportProtocol protocol) {
    RCFProtoJNI.RcfProtoChannel_setTransportProtocol(swigCPtr, this, protocol.swigValue());
  }

  /**
   * Gets the transport protocol being used by the channel. 
   */
  public TransportProtocol getTransportProtocol() {
    return TransportProtocol.swigToEnum(RCFProtoJNI.RcfProtoChannel_getTransportProtocol(swigCPtr, this));
  }

  /**
   * Sets the asynchronous RPC mode. By default the asynchronous RPC mode is false. 
   */
  public void setAsynchronousRpcMode(boolean enable) {
    RCFProtoJNI.RcfProtoChannel_setAsynchronousRpcMode(swigCPtr, this, enable);
  }

  /**
   * Gets the asynchronous RPC mode. 
   */
  public boolean getAsynchronousRpcMode() {
    return RCFProtoJNI.RcfProtoChannel_getAsynchronousRpcMode(swigCPtr, this);
  }

  /**
   * Sets the ping back interval of the connection, in milliseconds. Ping backs are sent from the server back to the client, while a remote call is in progress. 
   */
  public void setPingBackIntervalMs(int pingBackIntervalMs) {
    RCFProtoJNI.RcfProtoChannel_setPingBackIntervalMs(swigCPtr, this, pingBackIntervalMs);
  }

  /**
   * Returns the ping back interval of the connection. 
   */
  public int getPingBackIntervalMs() {
    return RCFProtoJNI.RcfProtoChannel_getPingBackIntervalMs(swigCPtr, this);
  }

  /**
   * Sets the network address of the HTTP proxy server, through which to route remote calls. Only valid when using a HTTP or HTTPS endpoint. 
   */
  public void setHttpProxy(String httpProxy) {
    RCFProtoJNI.RcfProtoChannel_setHttpProxy(swigCPtr, this, httpProxy);
  }

  /**
   * Returns the network address of the HTTP proxy server. 
   */
  public String getHttpProxy() {
    return RCFProtoJNI.RcfProtoChannel_getHttpProxy(swigCPtr, this);
  }

  /**
   * Sets the port number of the HTTP proxy server, through which to route remote calls. Only valid when using a HTTP or HTTPS endpoint. 
   */
  public void setHttpProxyPort(int httpProxyPort) {
    RCFProtoJNI.RcfProtoChannel_setHttpProxyPort(swigCPtr, this, httpProxyPort);
  }

  /**
   * Returns the port number of the HTTP proxy server. 
   */
  public int getHttpProxyPort() {
    return RCFProtoJNI.RcfProtoChannel_getHttpProxyPort(swigCPtr, this);
  }

  /**
   * Returns the transport type of the connection. 
   */
  public TransportType getTransportType() {
    return TransportType.swigToEnum(RCFProtoJNI.RcfProtoChannel_getTransportType(swigCPtr, this));
  }

  /**
   * Sets the Windows username to use when connecting. Only valid for NTLM and Kerberos transport protocols. 
   */
  public void setUsername(String username) {
    RCFProtoJNI.RcfProtoChannel_setUsername(swigCPtr, this, username);
  }

  /**
   * Returns the Windows username to use when connecting. 
   */
  public String getUsername() {
    return RCFProtoJNI.RcfProtoChannel_getUsername(swigCPtr, this);
  }

  /**
   * Sets the Windows password to use when connecting. Only valid for NTLM and Kerberos transport protocols. 
   */
  public void setPassword(String password) {
    RCFProtoJNI.RcfProtoChannel_setPassword(swigCPtr, this, password);
  }

  /**
   * Returns the Windows password to use when connecting. 
   */
  public String getPassword() {
    return RCFProtoJNI.RcfProtoChannel_getPassword(swigCPtr, this);
  }

  /**
   * Sets the Kerberos SPN to use when connecting. Only valid for Kerberos transport protocols. 
   */
  public void setKerberosSpn(String kerberosSpn) {
    RCFProtoJNI.RcfProtoChannel_setKerberosSpn(swigCPtr, this, kerberosSpn);
  }

  /**
   * Returns the Kerberos SPN to use when connecting. 
   */
  public String getKerberosSpn() {
    return RCFProtoJNI.RcfProtoChannel_getKerberosSpn(swigCPtr, this);
  }

  /**
   * Sets the transport level compression setting for this connection. 
   */
  public void setEnableCompression(boolean enableCompression) {
    RCFProtoJNI.RcfProtoChannel_setEnableCompression(swigCPtr, this, enableCompression);
  }

  /**
   * Returns the transport level compression setting for this connection. 
   */
  public boolean getEnableCompression() {
    return RCFProtoJNI.RcfProtoChannel_getEnableCompression(swigCPtr, this);
  }

  /**
   * Sets the SSL certificate for the channel. 
   */
  public void setCertificate(Certificate certificatePtr) {
    RCFProtoJNI.RcfProtoChannel_setCertificate(swigCPtr, this, Certificate.getCPtr(certificatePtr), certificatePtr);
  }

  /**
   * Gets the SSL certificate for the channel. 
   */
  public Certificate getCertificate() {
    long cPtr = RCFProtoJNI.RcfProtoChannel_getCertificate(swigCPtr, this);
    return (cPtr == 0) ? null : new Certificate(cPtr, true);
  }

  /**
   * Sets the certificate authority for the channel. 
   */
  public void setCaCertificate(Certificate certificatePtr) {
    RCFProtoJNI.RcfProtoChannel_setCaCertificate(swigCPtr, this, Certificate.getCPtr(certificatePtr), certificatePtr);
  }

  /**
   * Gets the certificate authority for the channel. 
   */
  public Certificate getCaCertificate() {
    long cPtr = RCFProtoJNI.RcfProtoChannel_getCaCertificate(swigCPtr, this);
    return (cPtr == 0) ? null : new Certificate(cPtr, true);
  }

  /**
   * Sets the OpenSSL cipher suite. Only applicable when using OpenSSL as the SSL implementation. 
   */
  public void setOpenSslCipherSuite(String cipherSuite) {
    RCFProtoJNI.RcfProtoChannel_setOpenSslCipherSuite(swigCPtr, this, cipherSuite);
  }

  /**
   * Gets the OpenSSL cipher suite. 
   */
  public String getOpenSslCipherSuite() {
    return RCFProtoJNI.RcfProtoChannel_getOpenSslCipherSuite(swigCPtr, this);
  }

  /**
   * Sets the Schannel certificate validation setting. Only applicable when using Schannel as the SSL implementation. If this setting is non-empty, it will be used by Schannel to automatically validate peer certificates. 
   */
  public void setEnableSchannelCertificateValidation(String peerName) {
    RCFProtoJNI.RcfProtoChannel_setEnableSchannelCertificateValidation(swigCPtr, this, peerName);
  }

  /**
   * Gets the Schannel certificate validation setting. 
   */
  public String getEnableSchannelCertificateValidation() {
    return RCFProtoJNI.RcfProtoChannel_getEnableSchannelCertificateValidation(swigCPtr, this);
  }

  void _setCertificateValidationCallback(_SwigCallback pcb) {
    RCFProtoJNI.RcfProtoChannel__setCertificateValidationCallback(swigCPtr, this, _SwigCallback.getCPtr(pcb), pcb);
  }

  /**
   * Sets the SSL implementation to be used by the channel. 
   */
  public void setSslImplementation(SslImplementation sslImplementation) {
    RCFProtoJNI.RcfProtoChannel_setSslImplementation(swigCPtr, this, sslImplementation.swigValue());
  }

  /**
   * Gets the SSL implementation. 
   */
  public SslImplementation getSslImplementation() {
    return SslImplementation.swigToEnum(RCFProtoJNI.RcfProtoChannel_getSslImplementation(swigCPtr, this));
  }

}