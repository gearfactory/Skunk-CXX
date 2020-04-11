#pragma once 

namespace skunk{
  /**
   * IP and Port object 
   */
  class InetAddress{
    
  };

  // some useful function copy from UNP 
  
  /// bind the addresss to the fd
  int bind_address(int, const InetAddress&);

  // set the S_NONBLOCK on fd
  int setnoblock(int);

  //int 
} // namespace skunk
