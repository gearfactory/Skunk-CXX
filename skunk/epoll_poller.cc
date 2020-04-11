#include "skunk/poller.h"

namespace skunk{
  /**
   * Will implement the Epoll Poller 
   */
  class EpollPoller: public virtual Poller{
    public: 
      size_t poll() override{
        return 0;
      }
  };
} // namespace skunk
