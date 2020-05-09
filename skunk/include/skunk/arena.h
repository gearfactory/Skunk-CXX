#ifndef __SKUNK_ARENA_H__
#define __SKUNK_ARENA_H__

#include <mutex>

namespace skunk{
  
  enum class Aligned{
    _32 = 1,
    _64
  };

  class Allocator{
    public: 

      void * Alloc(size_t size);
      void * Alloc(Aligned aligned, size_t size);

    private: 
      std::mutex mutex_;
  };
} // namespace skunk

#endif // !__SKUNK_ARENA_H__