#ifndef __SKUNK_ARENA_H__
#define __SKUNK_ARENA_H__

#include <mutex>

namespace skunk{
  
  /// user interface 
  /// will alloc memory by the Block , MiniBlock 1024 SmallBlock 256K BigBlock 512K 
  class Allocator{
    public:
      Allocator();
      ~Allocator();

    public:
      void * Alloc(size_t size);
      void Free(void * mem);

  };
} // namespace skunk

#endif // !__SKUNK_ARENA_H__