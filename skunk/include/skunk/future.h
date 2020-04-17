#pragma once

namespace skunk{
  
  template<typename T>
  class Future{
    public: 
      bool IsCompleted();
      bool IsCanceled();

      T Get();    

  };
} // namespace skunk
