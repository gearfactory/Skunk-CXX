#pragma once

#include <mutex>
#include <condition_variable>

namespace skunk{
  class Condition;

  class Mutex{
    friend Condition;

    

  };

  class MutexGuard{

  };

  class Condition{

    private: 
      Mutex mutex_;

  };
} // namespace skunk
