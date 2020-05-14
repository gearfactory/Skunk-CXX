#pragma once

#include <functional>
#include <memory>
#include <stdint.h>

namespace skunk{

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
      
      void EnableReading();
      void DisableReading();

      void EnableWriting();
      void DisableWriting();

      void EnableAll();
      void DisableAll();

      bool IsWriteable();
      bool IsReadable();
    
    private:
      friend class EventLoop;

      /// will dispatch the event which occur on the timestamp 
      void Dispatch(int64_t timestamp);
    private: 
      /// the fd could be timerfd eventfd signalfd socketfd
      int fd_;

      /// EPOLLIN EPOLLOUT EPOLLERR event mask on linux 
      int interest_;
      /// now active event 
      int active_;

      /// keep the eventloop in class to use the eventloop internal method 
      EventLoop * eventloop_;

      /// read callback function
      std::function<void> readCallback_;
      /// write callback
      std::function<void> writeCallback_;
      /// close callback 
      std::fucntion<void> closeCallback_;
      /// error callback 
      std::function<void> errorCallback_;
  };

} // namespace skunk
