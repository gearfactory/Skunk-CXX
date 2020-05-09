#pragma once

#include <functional>

#include "skunk/utility.h"

namespace skunk{

  class Socket: noncopyable{

    public:
      explicit Socket(int fd):socket_fd_(fd){}

      /// release the socket fd
      ~Socket();

    private:
      // the Linux fd of a socket
      int socket_fd_;
  };

} // namespace skunk
