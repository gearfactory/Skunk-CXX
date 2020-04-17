#pragma once 

// some usefull macro 
#include <iostream>
#include <endian.h>
#include <stdint.h>

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

  /// 
  namespace endian{
     inline uint16_t Host2NetUint16(uint16_t data){
        return htobe16(data);
     }
     inline uint32_t Host2NetUint32(uint32_t data){
        return htobe32(data);
     }
     inline uint64_t Host2NetUint64(uint64_t data){
        return htobe64(data);
     }
     inline uint16_t Host2NetUint16(int16_t data){
        return htobe16((unsigned)data);
     }
     inline uint32_t Host2NetUint32(int32_t data){
        return htobe32((unsigned)data);
     }
     inline uint64_t Host2NetUint64(int64_t data){
        return htobe64((unsigned)data);
     }

     inline uint16_t Net2HostUint16(uint16_t data){
        return be16toh(data);
     }
     inline uint32_t Net2HostUint32(uint32_t data){
        return be32toh(data);
     }
     inline uint64_t Net2HostUint64(uint64_t data){
        return be64toh(data);
     }
     inline int16_t Net2HostInt16(int16_t data){
        return (int16_t)be16toh((unsigned)data);
     }
     inline int32_t Net2HostInt32(uint32_t data){
        return (int32_t)be32toh((unsigned)data);
     }
     inline int64_t Net2HostInt64(uint64_t data){
        return (int64_t)be64toh((unsigned)data);
     }

  } // namespace endian
  
} // namespace skunk
