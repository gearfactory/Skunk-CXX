#pragma once

namespace skunk{
  class InetAddress;

  /**
   * Skunk Socket representation 
   */
  class Socket{
    public:
      explicit Socket(int fd): fd_(fd){}

      Socket(Socket&) = delete;
      Socket(Socket&&) = delete;

      // in the implementation will close the fd_
      ~Socket();

      // return the fd 
      int fd(){
        return fd_;
      }

      void bind(const InetAddress& addres);

      int accept(InetAddress * clientAddress);

      void listen();

      void set_noblock();
      void set_reuseaddr();
      void set_reuseport();
      

    private: 
      int fd_;

  };
} // namespace skunk
