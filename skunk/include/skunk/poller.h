#pragma once

#include <sys/types.h>

namespace skunk{
  /**
   * The abstraction of the EventPoll 
   */
  class Poller{
    public:
      // poll call will reaturn the availiable socket to reaturn use pointer 
      virtual size_t poll() = 0;
  };
} // namespace skunk
