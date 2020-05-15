#pragma once

#include <functional>

#include "skunk/utility.h"

namespace skunk{

  /**
   * RAII Pattern to manage the socket fd 
   * Socket object's lifecycle will be managed by Connection object 
   * 
   */
  class Socket: noncopyable{

    public:
      explicit Socket(int fd):socket_fd_(fd){}

      /// release the socket fd
      ~Socket();

      /**
       * return the socket fd which maintain in this obejct 
       */
      int Getfd(){return socket_fd_};

      /**
       * will close the outbound write
       */
      void CloseOutbound();

      /**
       * disable Nagle use TCP_NONDELAY 
       */
      void UseNagle(bool on = true);

      /**
       * use SO_REUSEPORT
       */
      void ReusePort(bool on = true);

      /**
       * use SO_REUSEADDR
       */
      void ReuseAddress(bool on = true);

      /**
       * SO_KEEPALIVE
       */
      void KeepAlive(bool on = true);

    private:
      // the Linux fd of a socket
      int socket_fd_;
  };

} // namespace skunk
