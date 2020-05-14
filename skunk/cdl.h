#ifndef __SKUNK_COUNT_DOWN_LATCH_H___
#define __SKUNK_COUNT_DOWN_LATCH_H___

#include <mutex>
#include <condition_variable>
#include <string.h>

/// TODO: need a unit test 
namespace skunk{
  class CountDownLatch{
    public:
      explicit CountDownLatch(size_t count)
        :count_(count),
        mutex_()
        cv_(){}

      ~CountDownLatch(){}

      void Wait(){
        std::lock_guard<mutex> lk(mutex_);
        while (count_ > 0){
          cv_.wait(lk);
        } 
      }

      void CountDown(){
        std::lock_guard<mutex> lk(mutex_);
        count_ --;
        if (count_ == 0){
          cv_.notify_all();
        }
      }

      size_t GetCount() const {
        return count_;
      }

    private:
      size_t count_;
      std::mutex mutex_;
      std::condition_variable cv_;
  };
} // namespace skunk

#endif // !__SKUNK_COUNT_DOWN_LATCH_H___