#pragma once 

#include <mutex>
#include <deque>
#include <condition_variable>

#include "skunk/utility.h"

namespace skunk{
  
  /**
   * BlockQueue simple implementation
   */
  template<typename T>
  class BlockQueue: noncopyable{
    public:
      BlockQueue(): queue_(), mutex_(), cond_(){}

      void put(const T & val){
        std::unique_lock<std::mutex> lock (mutex_);
        queue_.emplace(val);
        cond_.notify_all();
      }

      void put(T && val){
        std::unique_lock<std::mutex> lock (mutex_);
        queue_.push_back(std::move(val));
        cond_.notify_all();
      }

      T take(){
        std::unique_lock<std::mutex> lock (mutex_);
        while(queue_.empty()){
          cond_.wait(lock);
        }
        // the T should implement the move constructor 
        // FIXME: should use some useful traits from STL to handle this trais 
        T front(std::move(queue_.front()));
        queue_.pop_front();
        return front;
      }

    private: 
      std::deque<T> queue_;
      std::mutex mutex_;
      std::condition_variable cond_;
  };
} // namespace skunk