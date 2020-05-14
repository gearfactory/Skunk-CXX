#ifndef __SKUNK_EPOLLER_H__
#define __SKUNK_EPOLLER_H__

#include <vector>

namespace skunk{

  class Event;
  
  class Poller{
    public: 
      Poller(int fd):epoll_fd_(fd){
        fd_sets_ = vector<int>();
      }
      ~Poller();
    public:
      /// poll the fd and return the events list
      void Poll(vector<Event>& events);

      /// add a fd to the poller to poll 
      void Add(int fd);

      /// remove a fd to remove the fd 
      void Remove(int fd);
    private:
      int epoll_fd_;
      std::vector<int> fd_sets_;
  };
  
} // namespace skunk


#endif // !__SKUNK_EPOLLER_H__