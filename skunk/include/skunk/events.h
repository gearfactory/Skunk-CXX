#ifndef __SKUNK_EVENTS_H__
#define __SKUNK_EVENTS_H__

namespace skunk{
  
  enum Event: int{
    EV_IN = 0x00001,
    EV_OUT = 0x00010,
    EV_TIMEOUT = 0x00100
  };

} // namespace skunk


#endif // !__SKUNK_EVENTS_H__