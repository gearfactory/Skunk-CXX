#pragma once 

#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include <string>

namespace skunk{
  /**
    * Buffer will be used as the only interface to read/write data from the application layer
    *+------------+-------------+------------+
    *|            |             |            |
    *| prependable|  readable   | writeable  |
    *|            |             |            |
    *+---------------------------------------+
    *|            |             |            |
    *v            v             v            v
    *0           rp            wp          size
    * 
    * the wp - rp is the readable data
    * the size - wp is the writeable data
    * we can make rp to move to a new poisiton and the rp - 0 is the prependable data 
    * 
    * the Buffer could not be copied 
   */
  class Buffer {

    public:
      // with the explicit size constructor 
      explicit Buffer(size_t size): length_(size), read_pointer_(0), write_pointer_(0){
        data_ = new char[size];
      }

      // destructor 
      ~Buffer(){
        delete[] data_;
      }

      // copy constructor
      Buffer(Buffer & buffer){
        data_ = new char[buffer.length_];
        length_ = buffer.length_;
        read_pointer_ = buffer.read_pointer_;
        write_pointer_ = buffer.write_pointer_;
        memcpy(data_, buffer.data_, length_); 
      }

      // move constructor 
      Buffer(Buffer&& buffer) = default;

    public: __always_inline
      // skip some byte 
      void skip(size_t len){
        read_pointer_ += len;
      }

      // back some byte 
      void back(size_t len){
        read_pointer_ -= len;
      }

      // swap two buffer 
      void swap(const Buffer & buffer){

      }

      bool is_eol(){
        return *(data_ + read_pointer_) == '\n';
      }

      bool is_eof(){
        return *(data_ + read_pointer_) == EOF;
      }

      


    public: __always_inline

      uint8_t readUint8(){
        
      }

      int8_t readInt8(){
        skip(1);
      }

      uint16_t readeUint16();
      int16_t readInt16();

      uint32_t readUint32();
      int32_t readInt32();

      uint64_t readUint64();
      int64_t readInt64();

      int readInt();
      unsigned int readUint();

      float readFloat();
      double readDouble();

      void* readLen(size_t len);

    public: __always_inline
      size_t append(const void* data, size_t len);
      size_t append(uint8_t data){
        *(data_ + write_pointer_) = data;
        return length_ - (write_pointer_ += sizeof(uint8_t));
      }
      size_t append(uint16_t data){
        *(data_ + write_pointer_) = data;
        return length_ - (write_pointer_ += sizeof(uint16_t));
      }
      size_t append(uint32_t data){
        *(data_ + write_pointer_) = data;
        return length_ - (write_pointer_ += sizeof(uint32_t));
      }
      size_t append(uint64_t data){
        *(data_ + write_pointer_) = data;
        return length_ - (write_pointer_ += sizeof(uint64_t));
      }
      

    private: 
      friend class Buffer;
      char * data_;
      size_t length_;
      size_t read_pointer_;
      size_t write_pointer_;

  };
} // namespace skunk
