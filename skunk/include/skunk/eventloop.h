#pragma once

#include <memory>

#include "skunk/utility.h"

namespace skunk{
  class Future;
  class ThreadPool;
  /**
   * EventLoop will run on a thread pool 
   * use Acceptor to accept the socket from the server fild descriptor 
   */ 
  class EventLoop: noncopyable{
    public: 
      Future Loop();
      std::unique_ptr<ThreadPool> GetThreadPool();

    private: 
      std::unique_ptr<ThreadPool> threadpool_;

  };
} // namespace skunk

/**
 * eventloop .start() -> Future.Get(); will suspend the Main function to wait the result of Future 
 * 
 */