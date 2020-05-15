
#include <sys/epoll.h>
#include <errno.h>

#include "epoller.h"
#include "skunk/events.h"


using namespace skunk;

Poller::Poller{
  fd_sets_ = vector<int>();
  epoll_fd_ = epoll_create1(EPOLL_CLOEXEC);
  //FIXME: if the epoll_fd_ is -1 then abort the process to exit the skunk bootstrap
}

void skunk::Poller::Poll(vector<Event>& events)){
  epoll_event events[fd_sets_.size()];

  auto event_num = epoll_wait(epoll_fd_, events, fd_sets_.size(), 0);

  if (event_num < 0){
    // print the errno 
  }

  for (auto i = 0; i < event_num; i++){
    Event event;
    event.SetFileDescriptor(events[i].data.fd);
   //
  }
}

void skunk::Poller::Add(int fd){
  if (fd < 0){
    // TODO: should thorw a new exception or return result with status
    return ;
  }

  epoll_event ev;
  ev.event = EPOLLIN | EPOLLOUT | EPOLLERR | EPOLL_NONBLOCK | EPOLLPRI | EPOLLHUP;
  ev.data.fd = fd;

  epoll_ctl(epoll_fd_, EPOLL_CTL_ADD, fd, &ev);
  fd_set_.push_back(fd);
}

void Poller::Remove(int fd){
  if (fd < 0){
    // TODO: should thorw a new exception or return result with status
    return ;
  }

  epoll_ctl(epoll_fd_, EPOLL_CTL_DEL, fd, nullptr);
  fd_set_.erase(fd);
}

