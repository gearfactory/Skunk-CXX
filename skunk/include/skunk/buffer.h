#ifndef __SKUNK_BUFFER_H__
#define __SKUNK_BUFFER_H__

#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include <memory>

#include "skunk/utility.h"

namespace skunk{
  class Condition;
  /**
    * DirectBuffer will be used as the only interface to read/write data from the application layer
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
  template<class DerivedBuffer>
  class Buffer: noncopyable {
    public: 
      Buffer(size_t size){}
      ~Buffer(){};
    public: 
      /**
       * Get the readable size of this buffer
       * @return return the readable size
       */
      size_t GetReadableSize() const{
        return (static_cast<DerivedBuffer&>(*this).GetReadableSize());
      }

      /**
       * Get the writeable size of this buffer
       * @return writeable size
       */
      size_t GetWriteableSize() const{
        return (static_cast<DerivedBuffer&>(*this).GetWriteableSize());
      }

      /**
       * Get the buffer capcity
       * @return capcity of this buffer 
       */
      size_t GetCapcity() const{
        return (static_cast<DerivedBuffer&>(*this).GetCapcity());
      }

      /**
       * Back the pointer of read pointer
       * @param size the size to back  
       */
      void Back(size_t size){
        static_cast<DerivedBuffer&>(*this).Back(size);
      }

      /**
       * Skip size length data from read pointer 
       * @param size the size to skip
       */
      void Skip(size_t size){
        static_cast<DerivedBuffer&>(*this).Skip(size);
      }

      /**
       * Peek the current pointer of read pointer
       * @return current read pointer of this buffer  
       */
      char * Peek() const{
        return (static_cast<DerivedBuffer&>(*this).Peek());
      }

      void Swap(DerivedBuffer& rhs){
        static_cast<DerivedBuffer&>(*this).Swap(rhs);
      }
      
      char * Read(size_t size){
        return (static_cast<DerivedBuffer&>(*this).Read(size));
      }

      size_t Write(const char * data, size_t length){
        return (static_cast<DerivedBuffer&>(*this).Write(data, length));
      }

      void Append(char ch){
        static_cast<DerivedBuffer&>(*this).Append(ch);
      }
      
      // These Reader should return the host byte order data
      /// euqals char type
      inline uint8_t ReadUint8(){
        return (uint8_t)*(Read(sizeof(uint8_t)));
      }
      inline int8_t ReadInt8(){
        return (int8_t)*(Read(sizeof(int8_t)));
      }

      /// 16bits integer
      inline uint16_t ReadUint16(){
        return endian::Net2HostUint16((uint16_t)*Read(sizeof(uint16_t)));
      }
      inline int16_t ReadInt16(){
         return endian::Net2HostInt16((int16_t)*Read(sizeof(int16_t)));
      }

      /// 32bits integer
      inline uint32_t ReadUint32(){
        return endian::Net2HostUint32((uint32_t)*Read(sizeof(uint32_t)));
      }
      inline int32_t ReadInt32(){
        return endian::Net2HostInt16((int32_t)*Read(sizeof(int32_t)));
      }

      /// 64bits integer
      inline uint64_t ReadUint64(){
        return endian::Net2HostUint64((uint64_t)*Read(sizeof(uint64_t)));
      }
      inline int64_t ReadInt64(){
        return endian::Net2HostUint64((int64_t)*Read(sizeof(int64_t)));
      }

      // These writer will write from host to network byteorder
      /// 8bits like 
      inline void WriteUint8(uint8_t data){
        Append((char)data);
      }
      inline void WriteInt8(int8_t data){
        Append((char)data);
      }

      /// 16bits integer
      inline void WriteInt16(uint16_t data){
        uint16_t tmp = endian::Host2NetUint16(data);
        Write((char*)&tmp, sizeof(uint16_t));
      }
      inline void WriteUint16(int16_t data){
        uint16_t tmp = endian::Host2NetUint16(data);
        Write((char*)&tmp, sizeof(uint16_t));
      }

      /// 32bits integer
      inline void WriteUint32(uint32_t data){
        uint32_t tmp = endian::Host2NetUint32(data);
        Write((char*)&tmp, sizeof(uint32_t));
      }
      inline void WriteInt32(int32_t data){
        uint32_t tmp = endian::Host2NetUint32(data);
        Write((char*)&tmp, sizeof(uint32_t));
      }

      /// 64bits integer
      inline void WriteUint64(uint64_t data){
        uint64_t tmp = endian::Host2NetUint64(data);
        Write((char*)&tmp, sizeof(uint64_t));
      }
      inline void WriteInt64(int64_t data){
        uint64_t tmp = endian::Host2NetUint64(data);
        Write((char*)&tmp, sizeof(uint64_t));
      }
  };
} // namespace skunk

#endif // !__SKUNK_BUFFER_H__
