#pragma once

namespace skunk{
  class Future;
  /**
   * EventLoop will run on a thread pool 
   * use Acceptor to accept the socket from the server fild descriptor 
   */ 
  class EventLoop{
    public: 
      Future start();
  };
} // namespace skunk

/**
 * eventloop .start() -> Future.Get();
 */