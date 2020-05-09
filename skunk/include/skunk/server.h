#ifndef __SKUNK_SERVER_H__
#define __SKUNK_SERVER_H__

#include <memory>
#include <future>
#include <atomic>

#include "skunk/utility.h"


namespace skunk{

  // forward declared 
  class EventLoopGroup;
  class InetAddress4;

  class TcpServer: noncopyable{
    public: 

      TcpServer(std::unique_ptr<EventLoopGroup> bossGroup, std::unique_ptr<EventLoopGroup> workerGroup);

      ~TcpServer();

      /// start the server and then will wait at the future 
      /// will register the Signal on SIGKILL in linux 
      std::future<void> Start();

      /// this method will create a Acceptor to accept the socket 
      /// will create a ServerSocket and then bind the address and port on this socket 
      /// and then start a acceptor 
      int Listen(const InetAddress4 * address);

    public: 
      // OnConnected();
      // OnInbound();
      // OnOutbound();

    private: 
      std::atomic_bool running_;

  };
}

#endif // !__SKUNK_SERVER_H__