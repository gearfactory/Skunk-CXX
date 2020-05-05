#pragma once

#include <memory>

namespace skunk{
  class Socket;
  class Buffer;
  class Channel;
  class InetAddress;
  class EventLoop;
  /**
   * this is a simple Connection of TCP  
   */
  class Connection{

    public:

    public:
      bool IsConnected();
      void Shutdown();
      void Close();


    private:
      std::unique_ptr<Socket> socket_;
      std::unique_ptr<Channel> channel_;

      std::shared_ptr<EventLoop> eventloop_;

      Buffer * inbound_;
      Buffer * outbound_;

      const InetAddress localaddr_;
      const InetAddress peeraddr_;
  };

} // namespace skunk
