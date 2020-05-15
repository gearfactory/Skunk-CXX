#ifndef __SKUNK_BOOTSTRAP_H__
#define __SKUNK_BOOTSTRAP_H__

#include <future>
#include <functional>
#include <memory>

namespace skunk{
  
  class EventLoop;
  class Connection;
  class Buffer;
  

  class BootStrap{
    public:
      void OnClose();
      void OnError();
      /// will read from the TCP stream use the function 
      void OnInbound();
      /// will write to the TCP stream;
      void OnOutbound();

      std::future<void> Start() noexcept;
  };

  class ServerBootstrap{
    public:
      std::future<void> Start() noexcept;
  };
} // namespace skunk

#endif // !__SKUNK_BOOTSTRAP_H__

// per server loop per acceptor 

/**
 * should use this to solve thunder herd 
 * for(;;){
 *  std::lock_guard<std::mutex> lock(mutex_);
 *  cond_.wait(lock);
 *    accept();
 *  cond.notify_one()
 * }
 */