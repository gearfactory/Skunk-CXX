#ifndef __SKUNK_BOOTSTRAP_H__
#define __SKUNK_BOOTSTRAP_H__

#include <future>

namespace skunk{
  

  class BootStrap{
    public:
      void OnConnection();
      void OnClose();
      void OnError();
      void OnMessage();

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