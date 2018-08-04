// Win32++   Version 8.5.1
// Release Date: TBA
//
//      David Nash
//      email: dnash@bigpond.net.au
//      url: https://sourceforge.net/projects/win32-framework
//
//
// Copyright (c) 2005-2017  David Nash
//
// Permission is hereby granted, free of charge, to
// any person obtaining a copy of this software and
// associated documentation files (the "Software"),
// to deal in the Software without restriction, including
// without limitation the rights to use, copy, modify,
// merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom
// the Software is furnished to do so, subject to the
// following conditions:
//
// The above copyright notice and this permission notice
// shall be included in all copies or substantial portions
// of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF
// ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED
// TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A
// PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT
// SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR
// ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
// ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE
// OR OTHER DEALINGS IN THE SOFTWARE.
//
////////////////////////////////////////////////////////


////////////////////////////////////////////////////////
// wxx_socket.h
//  Declaration of the CSocket class
//
// The CSocket class represents a network socket. After StartEvents is called,
// CSocket monitors the socket and responds automatically to network events.
// This event monitoring, for example, automatically calls OnReceive when
// there is data on the socket to be read, and OnAccept when a server should
// accept a connection from a client.

// Users of this class should be aware that functions like OnReceive,
// OnAccept, etc. are called on a different thread from the one CSocket is
// instantiated on. The thread for these functions needs to respond quickly
// to other network events, so it shouldn't be delayed. It also doesn't run
// a message loop, so it can't be used to create windows. For these reasons
// it might be best to use PostMessage in response to these functions in a
// windows environment.

// Refer to the network samples for an example of how to use this class to
// create a TCP client & server, and a UDP client and server.

// To compile programs with CSocket, link with ws3_32.lib for Win32,
// and ws2.lib for Windows CE. This class uses Winsock version 2, and
// supports Windows 98 and above.

// For a TCP server, inherit a class from CSocket and override OnAccept, OnDisconnect
// and OnRecieve. Create one instance of this class and use it as a listening socket.
// The purpose of the listening socket is to detect connections from clients and accept them.
// For the listening socket, we do the following:
// 1) Create the socket.
// 2) Bind an IP address to the socket.
// 3) Listen on the socket for incoming connection requests.
// 4) Use StartNotifyRevents to receive notification of network events.
// 5) Override OnAccept to accept requests on a newly created data CSocket object.
// 6) Create a new data socket for each client connection accepted.
// 7) The server socket uses the 'accept' function to accept an incoming connection
//     from this new data socket.

// The purpose of the data socket is to send data to, and receive data from the client.
// There will be one data socket for each client accepted by the server.
// To use it we do the following:
// * To receive data from the client, override OnReceive and use Receive.
// * To send data to use Send.
// * OnDisconnect can be used to detect when the client is disconnected.

// For a TCP client, inherit from CSocket and override OnReceive and OnDisconnect.
// Create an instance of this inherited class, and  perform the following steps:
// 1) Create the socket.
// 2) Connect to the server.
// 3) Use StartNotifyRevents to receive notification of network events.
//    We are now ready to send and receive data from the server.
// * Use Send to send data to the server.
// * Override OnReceive and use Receive to receive data from the server
// * OnDisconnect can be used to detect when the client is disconnected from the server.

// Notes regarding IPv6 support
// * IPv6 is supported on Windows Vista and above. Windows XP with SP2 provides
//    "experimental" support, which can be enabled by entering "ipv6 install"
//    at a command prompt.
// * IPv6 is not supported by all compilers and development environments. In
//    particular, it is not supported by Dev-C++ or Borland 5.5. A modern
//    Platform SDK needs to be added to Visual Studio 6 for it to support IPv6.
// * IsIPV6Supported returns false if either the operating system or the
//    development environment fails to support IPv6.
//


#ifndef _WIN32XX_SOCKET_H_
#define _WIN32XX_SOCKET_H_

// include exception handling, TRACE etc.
#include "wxx_wincore.h"
#include "wxx_mutex.h"
#include "wxx_cstring.h"

// Work around a bugs in older versions of Visual Studio
#ifdef _MSC_VER
  #if _MSC_VER < 1500
    // Skip loading wspiapi.h
    #define _WSPIAPI_H_
	#pragma warning (disable : 4355)     // 'this' : used in base member initializer list
  #endif
#endif

#include <ws2tcpip.h>

#define THREAD_TIMEOUT 100


namespace Win32xx
{

    typedef int  WINAPI GETADDRINFO(LPCSTR, LPCSTR, const struct addrinfo*, struct addrinfo**);
    typedef void WINAPI FREEADDRINFO(struct addrinfo*);

    // The CSocket class represents a network socket. It can be used to create
    // network connections, and pass data over those connections.
    class CSocket
    {
    public:
        CSocket();
        virtual ~CSocket();

        // Operations
        virtual void Accept(CSocket& rClientSock, struct sockaddr* addr, int* addrlen) const;
        virtual int  Bind(LPCTSTR addr, UINT port) const;
        virtual int  Bind(const struct sockaddr* name, int namelen) const;
        virtual int  Connect(LPCTSTR addr, UINT port) const;
        virtual int  Connect(const struct sockaddr* name, int namelen) const;
        virtual bool Create( int family, int type, int protocol = IPPROTO_IP);
        virtual void Disconnect();
        virtual void FreeAddrInfo( struct addrinfo* ai ) const;
        virtual int  GetAddrInfo( LPCTSTR nodename, LPCTSTR servname, const struct addrinfo* hints, struct addrinfo** res) const;
        virtual CString GetLastError() const;
        virtual int  ioCtlSocket(long cmd, u_long* argp) const;
        virtual bool IsIPV6Supported() const;
        virtual int  Listen(int backlog = SOMAXCONN) const;
        virtual int  Receive(char* buf, int len, int flags) const;
        virtual int  ReceiveFrom(char* buf, int len, int flags, struct sockaddr* from, int* fromlen) const;
        virtual int  Send(const char* buf, int len, int flags) const;
        virtual int  SendTo(const char* send, int len, int flags, LPCTSTR addr, UINT port) const;
        virtual int  SendTo(const char* buf, int len, int flags, const struct sockaddr* to, int tolen) const;

        virtual void StartEvents();
        virtual void StopEvents();

        // Attributes
        virtual int  GetPeerName(struct sockaddr* name, int* namelen) const;
        virtual int  GetSockName(struct sockaddr* name, int* namelen) const;
        SOCKET& GetSocket() { return m_socket; }
        virtual int  GetSockOpt(int level, int optname, char* optval, int* optlen) const;
        virtual int  SetSockOpt(int level, int optname, const char* optval, int optlen) const;

        // Override these functions to monitor events
        virtual void OnAccept()     {}
        virtual void OnAddresListChange() {}
        virtual void OnDisconnect() {}
        virtual void OnConnect()    {}
        virtual void OnOutOfBand()  {}
        virtual void OnQualityOfService() {}
        virtual void OnReceive()    {}
        virtual void OnRoutingChange() {}
        virtual void OnSend()       {}

        // Allow CSocket to be used as a SOCKET
        operator SOCKET() const {return m_socket;}

    private:
        CSocket(const CSocket&);                // Disable copy construction
        CSocket& operator = (const CSocket&);   // Disable assignment operator
        static UINT WINAPI EventThread(LPVOID thread_data);

        SOCKET m_socket;
        HMODULE m_hWS2_32;
		CWinThread m_eventThread;	// A worker thread for the events
		CEvent m_stopRequest;	// A manual reset event to signal the event thread should stop
		CEvent m_stopped;		// A manual reset event to signal the event thread is stopped

        GETADDRINFO* m_pfnGetAddrInfo;      // pointer for the GetAddrInfo function
        FREEADDRINFO* m_pfnFreeAddrInfo;    // pointer for the FreeAddrInfo function
    };
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

namespace Win32xx
{

    inline CSocket::CSocket() : m_socket(INVALID_SOCKET), m_eventThread(EventThread, this),
		m_stopRequest(FALSE, TRUE), m_stopped(FALSE, TRUE)
    {
        // Initialise the Windows Socket services
        WSADATA wsaData;

        if (::WSAStartup(MAKEWORD(2,2), &wsaData) != 0)
            throw CNotSupportedException(_T("WSAStartup failed"));

        m_hWS2_32 = LoadLibrary(_T("WS2_32.dll"));
        if (m_hWS2_32 == 0)
            throw CNotSupportedException(_T("Failed to load WS2_2.dll"));

#ifdef _WIN32_WCE
        m_pfnGetAddrInfo = reinterpret_cast<GETADDRINFO*>( GetProcAddress(m_hWS2_32, L"getaddrinfo") );
        m_pfnFreeAddrInfo = reinterpret_cast<FREEADDRINFO*>( GetProcAddress(m_hWS2_32, L"freeaddrinfo") );
#else
        m_pfnGetAddrInfo = reinterpret_cast<GETADDRINFO*>( GetProcAddress(m_hWS2_32, "getaddrinfo") );
        m_pfnFreeAddrInfo = reinterpret_cast<FREEADDRINFO*>( GetProcAddress(m_hWS2_32, "freeaddrinfo") );
#endif

    }


    inline CSocket::~CSocket()
    {
        Disconnect();

        // Terminate the  Windows Socket services
        ::WSACleanup();

        ::FreeLibrary(m_hWS2_32);
    }


    // The accept function permits an incoming connection attempt on the socket.
    inline void CSocket::Accept(CSocket& rClientSock, struct sockaddr* addr, int* addrlen) const
    {
        rClientSock.m_socket = ::accept(m_socket, addr, addrlen);
        if (INVALID_SOCKET == rClientSock.GetSocket())
            TRACE("Accept failed\n");
    }


    // The bind function associates a local address with the socket.
    inline int CSocket::Bind(LPCTSTR addr, UINT port) const
    {
        int result = 0;

        if (IsIPV6Supported())
        {

#ifdef GetAddrInfo  // Skip the following code block for older development environments

            ADDRINFO hints;
            ZeroMemory(&hints, sizeof(hints));
            hints.ai_flags = AI_NUMERICHOST | AI_PASSIVE;
            ADDRINFO *AddrInfo;
            CString csPort;
            csPort.Format(_T("%u"), port);

			result = GetAddrInfo(addr, csPort, &hints, &AddrInfo);
            if (result != 0)
            {
                TRACE("GetAddrInfo failed\n");
                return result;
            }

            // Bind the IP address to the listening socket
			result =  ::bind( m_socket, AddrInfo->ai_addr, static_cast<int>(AddrInfo->ai_addrlen) );
            if (result == SOCKET_ERROR )
            {
                TRACE("Bind failed\n");
                return result;
            }

            // Free the address information allocated by GetAddrInfo
            FreeAddrInfo(AddrInfo);

#endif

        }
        else
        {
            sockaddr_in clientService;
            clientService.sin_family = AF_INET;
            clientService.sin_addr.s_addr = inet_addr( TtoA(addr) );
            clientService.sin_port = htons( (u_short)port );

			result = ::bind( m_socket, reinterpret_cast<SOCKADDR*>( &clientService), sizeof(clientService) );
            if ( 0 != result)
                TRACE("Bind failed\n");
        }

        return result;
    }


    // The bind function associates a local address with the socket.
    inline int CSocket::Bind(const struct sockaddr* name, int namelen) const
    {
        int result = ::bind (m_socket, name, namelen);
        if ( 0 != result)
            TRACE("Bind failed\n");
        return result;
    }


    // The Connect function establishes a connection to the socket.
    inline int CSocket::Connect(LPCTSTR addr, UINT port) const
    {
        int result = 0;

        if (IsIPV6Supported())
        {

#ifdef GetAddrInfo  // Skip the following code block for older development environments

            ADDRINFO hints;
            ZeroMemory(&hints, sizeof(hints));
            hints.ai_flags = AI_NUMERICHOST | AI_PASSIVE;
            ADDRINFO *AddrInfo;

            CString csPort;
            csPort.Format(_T("%u"), port);
			result = GetAddrInfo(addr, csPort, &hints, &AddrInfo);
            if (result != 0)
            {
                TRACE("getaddrinfo failed\n");
                return SOCKET_ERROR;
            }

            // Bind the IP address to the listening socket
			result = Connect( AddrInfo->ai_addr, static_cast<int>(AddrInfo->ai_addrlen) );
            if (result == SOCKET_ERROR )
            {
                TRACE("Connect failed\n");
                return result;
            }

            // Free the address information allocated by GetAddrInfo
            FreeAddrInfo(AddrInfo);

#endif

        }
        else
        {
            sockaddr_in clientService;
            clientService.sin_family = AF_INET;
            clientService.sin_addr.s_addr = inet_addr( TtoA(addr) );
            clientService.sin_port = htons( (u_short)port );

			result = ::connect( m_socket, reinterpret_cast<SOCKADDR*>( &clientService ), sizeof(clientService) );
            if ( 0 != result)
                TRACE("Connect failed\n");
        }

        return result;
    }


    // The Connect function establishes a connection to the socket.
    inline int CSocket::Connect(const struct sockaddr* name, int namelen) const
    {
        int result = ::connect( m_socket, name, namelen );
        if ( 0 != result)
            TRACE("Connect failed\n");

        return result;
    }


    // Creates the socket
    // Valid parameter values:
    //  family:     AF_INET or AF_INET6
    //  type:       SOCK_DGRAM, SOCK_SEQPACKET, SOCK_STREAM, SOCK_RAW
    //  protocol:   IPPROTO_IP, IPPROTO_TCP, IPPROTO_UDP, IPPROTO_RAW, IPPROTO_ICMP, IPPROTO_ICMPV6
    inline bool CSocket::Create( int family, int type, int protocol /*= IPPROTO_IP*/)
    {
        m_socket = socket(family, type, protocol);
        if(m_socket == INVALID_SOCKET)
        {
            TRACE("Failed to create socket\n");
            return FALSE;
        }

        return TRUE;
    }


    // Shuts down the socket.
    inline void CSocket::Disconnect()
    {
        ::shutdown(m_socket, SD_BOTH);
        StopEvents();
        ::closesocket(m_socket);
        m_socket = INVALID_SOCKET;
    }


    // Responds to network events.
    // These are the possible network event notifications:
    //  FD_READ     Notification of readiness for reading.
    //  FD_WRITE    Notification of readiness for writing.
    //  FD_OOB      Notification of the arrival of Out Of Band data.
    //  FD_ACCEPT   Notification of incoming connections.
    //  FD_CONNECT  Notification of completed connection or multipoint join operation.
    //  FD_CLOSE    Notification of socket closure.
    //  FD_QOS      Notification of socket Quality Of Service changes
    //  FD_ROUTING_INTERFACE_CHANGE Notification of routing interface changes for the specified destination.
    //  FD_ADDRESS_LIST_CHANGE      Notification of local address list changes for the address family of the socket.
    inline UINT WINAPI CSocket::EventThread(LPVOID thread_data)
    {
        WSANETWORKEVENTS networkEvents;
        CSocket* pSocket = reinterpret_cast<CSocket*>(thread_data);
		CEvent& stoppedEvent = pSocket->m_stopped;
		CEvent& stopRequestEvent = pSocket->m_stopRequest;
        SOCKET& sClient = pSocket->m_socket;

        WSAEVENT allEvents[2];
        allEvents[0] = ::WSACreateEvent();
        allEvents[1] = (WSAEVENT)(HANDLE)stopRequestEvent;
        long Events = FD_READ | FD_WRITE | FD_OOB | FD_ACCEPT | FD_CONNECT | FD_CLOSE;
        if (GetWinVersion() != 1400) // Win Version != Win95
            Events |= FD_QOS | FD_ROUTING_INTERFACE_CHANGE | FD_ADDRESS_LIST_CHANGE;

        // Associate the network event object (hNetworkEvents) with the
        // specified network events (Events) on socket sClient.
        if( SOCKET_ERROR == WSAEventSelect(sClient, allEvents[0], Events))
        {
            TRACE("Error in Event Select\n");
			stoppedEvent.SetEvent();
            ::WSACloseEvent(allEvents[0]);
            return 0;
        }

        // loop until the stop event is set
        for (;;) // infinite loop
        {
            // Wait 100 ms for a network event
            DWORD dwResult = ::WSAWaitForMultipleEvents(2, allEvents, FALSE, THREAD_TIMEOUT, FALSE);

            // Check event for stop thread
            if(::WaitForSingleObject(pSocket->m_stopRequest, 0) == WAIT_OBJECT_0)
            {
                ::WSACloseEvent(allEvents[0]);
				stoppedEvent.SetEvent();
                return 0;
            }

            if (WSA_WAIT_FAILED == dwResult)
            {
                TRACE("WSAWaitForMultipleEvents failed\n");
                ::WSACloseEvent(allEvents[0]);
				stoppedEvent.SetEvent();
                return 0;
            }

            // Proceed if a network event occurred
            if (WSA_WAIT_TIMEOUT != dwResult)
            {

                if ( SOCKET_ERROR == ::WSAEnumNetworkEvents(sClient, allEvents[0], &networkEvents) )
                {
                    TRACE("WSAEnumNetworkEvents failed\n");
                    ::WSACloseEvent(allEvents[0]);
					stoppedEvent.SetEvent();
                    return 0;
                }

                if (networkEvents.lNetworkEvents & FD_ACCEPT)
                    pSocket->OnAccept();

                if (networkEvents.lNetworkEvents & FD_READ)
                    pSocket->OnReceive();

                if (networkEvents.lNetworkEvents & FD_WRITE)
                    pSocket->OnSend();

                if (networkEvents.lNetworkEvents & FD_OOB)
                    pSocket->OnOutOfBand();

                if (networkEvents.lNetworkEvents & FD_QOS)
                    pSocket->OnQualityOfService();

                if (networkEvents.lNetworkEvents & FD_CONNECT)
                    pSocket->OnConnect();

                if (networkEvents.lNetworkEvents & FD_ROUTING_INTERFACE_CHANGE)
                    pSocket->OnRoutingChange();

                if (networkEvents.lNetworkEvents & FD_ADDRESS_LIST_CHANGE)
                    pSocket->OnAddresListChange();

                if (networkEvents.lNetworkEvents & FD_CLOSE)
                {
                    ::shutdown(sClient, SD_BOTH);
                    ::closesocket(sClient);
                    pSocket->OnDisconnect();
                    ::WSACloseEvent(allEvents[0]);
					stoppedEvent.SetEvent();
                    return 0;
                }
            }
        }
    }


    // Provides protocol-independent translation from host name to address.
    inline int CSocket::GetAddrInfo( LPCTSTR nodename, LPCTSTR servname, const struct addrinfo* hints, struct addrinfo** res) const
    {

#ifdef GetAddrInfo

        return m_pfnGetAddrInfo(TtoA(nodename), TtoA(servname), hints, res);

#else

        UNREFERENCED_PARAMETER(nodename);
        UNREFERENCED_PARAMETER(servname);
        UNREFERENCED_PARAMETER(hints);
        UNREFERENCED_PARAMETER(res);

        return WSAVERNOTSUPPORTED;

#endif

    }

    // Retrieves the most recent network error.
    inline CString CSocket::GetLastError() const
    {
        int errorCode = WSAGetLastError();
        LPTSTR message = NULL;
        CString errorMessage;

        FormatMessage(FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS |
                      FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_MAX_WIDTH_MASK,
                      NULL, errorCode, MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
                      reinterpret_cast<LPTSTR>(&message), 1024, NULL);

        if (message)
        {
            errorMessage = message;
            ::LocalFree(message);
        }

        return errorMessage;
    }


    // Retrieves the name of the peer to which the socket is connected.
    inline int  CSocket::GetPeerName(struct sockaddr* name, int* namelen) const
    {
        int result = ::getpeername(m_socket, name, namelen);
        if (result != 0)
            TRACE("GetPeerName failed\n");

        return result;
    }


    // Retrieves the local name for the socket.
    inline int  CSocket::GetSockName(struct sockaddr* name, int* namelen) const
    {
        int result = ::getsockname(m_socket, name, namelen);
        if (result != 0)
            TRACE("GetSockName Failed\n");

        return result;
    }


    // Retrieves the socket option.
    inline int  CSocket::GetSockOpt(int level, int optname, char* optval, int* optlen) const
    {
        int result = ::getsockopt(m_socket, level, optname, optval, optlen);
        if (result != 0)
            TRACE("GetSockOpt Failed\n");

        return result;
    }


    // Frees address resources allocated by the GetAddrInfo function.
    inline void CSocket::FreeAddrInfo( struct addrinfo* ai ) const
    {

#ifdef GetAddrInfo

        m_pfnFreeAddrInfo(ai);

#else

        UNREFERENCED_PARAMETER(ai);

#endif

    }


    // Controls the I/O mode of the socket.
    inline int CSocket::ioCtlSocket(long cmd, u_long* argp) const
    {
        int result = ::ioctlsocket(m_socket, cmd, argp);
        if (result != 0)
            TRACE("ioCtlSocket Failed\n");

        return result;
    }


    // Returns true if this system supports IP version 6.
    inline bool CSocket::IsIPV6Supported() const
    {
        bool isIPV6Supported = FALSE;

#ifdef GetAddrInfo

        if (m_pfnGetAddrInfo != 0 && m_pfnFreeAddrInfo != 0)
            isIPV6Supported = TRUE;

#endif

        return isIPV6Supported;
    }


    // Places the socket in a state in which it is listening for an incoming connection.
    inline int CSocket::Listen(int backlog /*= SOMAXCONN*/) const
    {
        int result = ::listen(m_socket, backlog);
        if (result != 0)
            TRACE("Listen Failed\n");

        return result;
    }


    // Receives data from the connected or bound socket.
    inline int CSocket::Receive(char* buf, int len, int flags) const
    {
        int result = ::recv(m_socket, buf, len, flags);
        if (SOCKET_ERROR == result)
            TRACE(_T("Receive failed\n"));
        return result;
    }


    // Receives a datagram and stores the source address.
    inline int CSocket::ReceiveFrom(char* buf, int len, int flags, struct sockaddr* from, int* fromlen) const
    {
        int result = ::recvfrom(m_socket, buf, len, flags, from, fromlen);
        if (SOCKET_ERROR == result)
            TRACE(_T("ReceiveFrom failed\n"));
        return result;
    }


    // Sends data on the connected socket.
    inline int CSocket::Send(const char* buf, int len, int flags) const
    {
        int result = ::send(m_socket, buf, len, flags);
        if (SOCKET_ERROR == result)
            TRACE(_T("Send failed\n"));
        return result;
    }


    // Sends data to a specific destination.
    inline int CSocket::SendTo(const char* buf, int len, int flags, const struct sockaddr* to, int tolen) const
    {
        int result =  ::sendto(m_socket, buf, len, flags, to, tolen);
        if (SOCKET_ERROR == result)
            TRACE(_T("SendTo failed\n"));
        return result;
    }


    // Sends data to a specific destination.
    inline int CSocket::SendTo(const char* send, int len, int flags, LPCTSTR addr, UINT port) const
    {
        int result = 0;

        if (IsIPV6Supported())
        {

#ifdef GetAddrInfo  // Skip the following code block for older development environments

            ADDRINFO hints;
            ZeroMemory(&hints, sizeof(hints));
            hints.ai_flags = AI_NUMERICHOST | AI_PASSIVE;
            ADDRINFO *addrInfo;
            CString csPort;
            csPort.Format(_T("%u"), port);

			result = GetAddrInfo(addr, csPort, &hints, &addrInfo);
            if (result != 0)
            {
                TRACE("GetAddrInfo failed\n");
                return SOCKET_ERROR;
            }

			result = ::sendto(m_socket, send, len, flags, addrInfo->ai_addr, static_cast<int>(addrInfo->ai_addrlen) );
            if (result == SOCKET_ERROR )
            {
                TRACE("SendTo failed\n");
                return result;
            }

            // Free the address information allocated by GetAddrInfo
            FreeAddrInfo(addrInfo);

#endif

        }
        else
        {
            sockaddr_in clientService;
            clientService.sin_family = AF_INET;
            clientService.sin_addr.s_addr = inet_addr( TtoA(addr) );
            clientService.sin_port = htons( (u_short)port );

			result = ::sendto( m_socket, send, len, flags, reinterpret_cast<SOCKADDR*>( &clientService ), sizeof(clientService) );
            if ( SOCKET_ERROR != result)
                TRACE("SendTo failed\n");
        }

        return result;
    }


    // Sets the socket option.
    inline int CSocket::SetSockOpt(int level, int optname, const char* optval, int optlen) const
    {
        int result = ::setsockopt(m_socket, level, optname, optval, optlen);
        if (result != 0)
            TRACE("SetSockOpt failed\n");

        return result;
    }


    // This function starts the thread which monitors the socket for events.
    inline void CSocket::StartEvents()
    {
        StopEvents();   // Ensure the thread isn't already running
		m_eventThread.CreateThread();
    }


    // Terminates the event thread gracefully (if possible)
    inline void CSocket::StopEvents()
    {
		// Ask the event thread to stop
		m_stopRequest.SetEvent();

		while(m_eventThread.IsRunning() &&
			(WAIT_TIMEOUT == ::WaitForSingleObject(m_stopped, THREAD_TIMEOUT * 10)))
		{
			// Note: An excessive delay in processing any of the notification functions
			// can cause us to get here. (Yes one second is an excessive delay. Its a bug!)
			TRACE("*** Error: Event Thread won't die ***\n");
		}

		m_stopRequest.ResetEvent();
		m_stopped.ResetEvent();
    }
}

// Work around a bugs in older versions of Visual Studio
#ifdef _MSC_VER
  #if _MSC_VER < 1500
	#pragma warning (default : 4355)     // 'this' : used in base member initializer list
  #endif
#endif

#endif // #ifndef _WIN32XX_SOCKET_H_

