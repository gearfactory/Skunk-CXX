#pragma once 

#include <stdint.h>
#include <string.h>
#include <future>
#include <thread>
#include <mutex>

namespace skunk{
  /**
   * Buffer will be used as the only interface to read/write data from the application layer
   */
  class Buffer {

    public:
      // with the explicit size constructor 
      explicit Buffer(size_t size){

      }

      // copy constructor
      Buffer(Buffer & buffer){

      }

      // move constructor 
      Buffer(Buffer&& buffer){

      }

    public:
      void skip(size_t len);
      void back(size_t len);

    public:
      uint8_t readUint8();
      int8_t readInt8();

      uint16_t readeUint16();
      int16_t readInt16();

      uint32_t readUint32();
      int32_t readInt32();

      uint64_t readUint64();
      int64_t readInt64();

    public: 
      size_t append(const void* data, size_t len);
      size_t append(const char* data, size_t len);
      //size_t append()

    private: 


  };
} // namespace skunk
