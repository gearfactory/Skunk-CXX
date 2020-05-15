
#include "skunk/eventloop.h"
#include "channel.h"
#include "epoller.h"


void skunk::EventLoop::Loop(){
  
  assert(!looping_);
  
  // TODO: should assert if this function call from the io thread

  while(quit_){
    
  }

}