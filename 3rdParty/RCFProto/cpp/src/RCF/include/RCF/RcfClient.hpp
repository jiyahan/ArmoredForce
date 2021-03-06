
//******************************************************************************
// RCF - Remote Call Framework
//
// Copyright (c) 2005 - 2013, Delta V Software. All rights reserved.
// http://www.deltavsoft.com
//
// RCF is distributed under dual licenses - closed source or GPL.
// Consult your particular license for conditions of use.
//
// If you have not purchased a commercial license, you are using RCF 
// under GPL terms.
//
// Version: 2.0
// Contact: support <at> deltavsoft.com 
//
//******************************************************************************

#ifndef INCLUDE_RCF_RCFCLIENT_HPP
#define INCLUDE_RCF_RCFCLIENT_HPP

#include <boost/mpl/eval_if.hpp>
#include <boost/mpl/bool_fwd.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/utility/enable_if.hpp>

#include <RCF/CheckRtti.hpp>
#include <RCF/ClientStub.hpp>
#include <RCF/Export.hpp>

namespace RCF {

    class ClientStub;
    class ServerBinding;

    typedef boost::shared_ptr<ClientStub> ClientStubPtr;
    typedef boost::shared_ptr<ServerBinding> ServerBindingPtr;

    RCF_EXPORT void setCurrentCallDesc(std::string& desc, RCF::MethodInvocationRequest& request, const char * szFunc, const char * szArity);

    // Base class of all RcfClient<> templates.
    class I_RcfClient
    {
    public:

        virtual ~I_RcfClient()
        {}

        // Returns a reference to the contained client stub, if one is available, i.e. if the RcfClient<> template is configured as a client stub.
        virtual ClientStub &getClientStub() = 0;
        virtual const ClientStub &getClientStub() const = 0;

        // Returns a reference to the contained server stub, if one is available, i.e. if the RcfClient<> template is configured as a server stub.
        virtual ServerBinding &getServerStub() = 0;

        virtual ClientStubPtr getClientStubPtr() const = 0;
        virtual ServerBindingPtr getServerStubPtr() const = 0;
    };

    typedef boost::shared_ptr<I_RcfClient> RcfClientPtr;

    // some meta-programming functionality needed by the macros in IDL.hpp

    typedef char (&yes_type)[1];
    typedef char (&no_type)[2];

    template<typename U> static yes_type RCF_hasRcfClientTypedef(typename U::RcfClientT *);
    template<typename U> static no_type RCF_hasRcfClientTypedef(...);

    template<typename T>
    struct GetRcfClient
    {
        typedef typename T::RcfClientT type;
    };

    template<typename T>
    struct Identity
    {
        typedef T type;
    };

    template<typename T>
    struct GetInterface
    {
        // tried eval_if here, but got some weird errors with vc71
        typedef typename boost::mpl::if_c<
            sizeof(yes_type) == sizeof(RCF_hasRcfClientTypedef<T>(0)),
            GetRcfClient<T>,
            Identity<T> >::type type0;

        typedef typename type0::type type;
    };

    class default_ { char a[1]; };
    class defined_ { char a[2]; };
    template<typename T> class Dummy {};

} // namespace RCF

#endif // ! INCLUDE_RCF_RCFCLIENT_HPP
