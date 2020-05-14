#ifndef __SKUNK_EVENTS_H__
#define __SKUNK_EVENTS_H__

namespace skunk{
  
  class Event{
    public:
      Event();
      ~Event();

      int GetFileDescriptor();

      int AddEvent(int evnet);

      int RemoveEvent(int event);

      int GetActives();

      void * GetData();

    private:
      int fd_;
      int events_;
      int active_;
      void * data_;
  };

} // namespace skunk
#endif // !__SKUNK_EVENTS_H__