#pragma once

#include <memory>
#include <vector>

#include "skunk/utility.h"

namespace skunk{
  /// Channel will be private in Skunk , which carry the callback
  class Channel;
  /// Epoller implement the poll 
  class Epoller;

  /**
   * EventLoop will run on a thread pool 
   * use Acceptor to accept the socket from the server fild descriptor 
   */ 
  class EventLoop: noncopyable{
    public: 
      EventLoop();
      ~EventLoop();
    public: 
      /**
       * will start this EventLoop in Thread 
       */
      void Loop();

      /**
       * add a channel to this eventloop 
       */
      void AddChannel(Channel * channel);

      /**
       * remove a channel from this eventloop
       */
      void RemoveChannel(Channel * channel);

      /**
       * check if this eventloop contain the channel 
       */
      bool HaveChannel(channel * channel); 

    private: 
      /// specify this eventloop started 
      bool looping_;
      /// specify this eventloop should quiet
      bool quit_;

      /// epoller
      std::unique_ptr<Epoller> epoller_;

      /// current active channel to trigger the event to user space
      Channel * currentChannel;
      /// active channel will be setted by Epoller 
      std::vector<Channel*> activeChannels_;

  };
} // namespace skunk