#pragma once

#include <functional>
#include <memory>

namespace skunk{

  class Epoller;
  class EventLoop;

  class Channel{

    public:
      Channel(EventLoop* eventloop, int fd): fd_(fd){}
      
      /**
       * DTOR of Channel do things
       * 1. unregister self from EventLoop object
       */
      ~Channel();

    public:

    
    private: 
      friend class Epoller;
      /// the fd could be timerfd eventfd signalfd socketfd
      int fd_;

      /// EPOLLIN EPOLLOUT EPOLLERR event mask on linux 
      int interest_;
      /// now active event 
      int active_;

      /// read callback function
      std::function<void()> readCallback_;
      /// write callback
      std::function<void()> writeCallback_;
      /// close callback 
      std::function<void()> closeCallback_;
      /// error callback 
      std::function<void()> errorCallback_;
  };

} // namespace skunk
