#pragma once 

// some usefull macro 
#include <iostream>

// TODO: should use the https://github.com/gearfactory/kangaroo project to print log
#define LOG(log) do{std::cout << "[file: " << __FILE__ << " at: " << __LINE__ << " ]" << log << std::endl }while(0)

namespace skunk{

  // copy from boost 
  class noncopyable{
   protected:
      noncopyable() {}
      ~noncopyable() {}
   private:  // emphasize the following members are private
      noncopyable( const noncopyable& );
      const noncopyable& operator=( const noncopyable& );
  };
} // namespace skunk
