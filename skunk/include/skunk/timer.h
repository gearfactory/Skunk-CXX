#ifndef __SKUNK_TIMER_H__
#define __SKUNK_TIMER_H__

namespace skunk{
  
  class Timer{
    public: 
      Timer();
      ~Timer();
    
    public:
      void OnTimeout();
      void OnInterval();
  };

  class TimeWheel{

  };

} // namespace skunk

#endif // !__SKUNK_TIMER_H__