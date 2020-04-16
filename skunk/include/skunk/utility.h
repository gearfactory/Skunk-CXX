#pragma once 

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
