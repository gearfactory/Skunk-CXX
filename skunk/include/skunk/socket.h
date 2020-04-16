#pragma once

#include <functional>


namespace skunk{
  class noncopyable;
  class Socket: private noncopyable{

    private:
      // the Linux fd of a socket
      int fd_;
  };

} // namespace skunk
