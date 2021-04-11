
## TODO
>should contain key words below

promise 

async

future 

join

future_status

shared_future 

packaged_task 

thread 

launch

unique_lock 

## 学习路线

### thread

### evolution

> Tag: `scoped block` `RAII`

#### mutex

```mermaid
graph TD;

   %% std::lock(mutex1, mutex2) 一个锁获得不了就释放已经获得的锁，避免死锁相互等待
   mutex --> lock
   
   %% Tries to lock the mutex. Returns immediately. On successful lock acquisition returns true, otherwise returns false.
   lock --> try_lock
   
   %% Blocks until specified timeout_duration has elapsed or the lock is acquired, whichever comes first. On successful lock acquisition returns true, otherwise returns false.
   try_lock --> try_lock_for  %% 类似 setTimeout
   %% If timeout_duration is less or equal timeout_duration.zero(), the function behaves like try_lock().
   
   %% Tries to lock the mutex. Blocks until specified timeout_time has been reached or the lock is acquired, whichever comes first. On successful lock acquisition returns true, otherwise returns false.
   try_lock --> try_lock_until
   %% If timeout_time has already passed, this function behaves like try_lock().

   %% thread 第二参数
   %% RAII；scoped block；防止 mutex 因中途break而未被释放
   lock --> lock_guard
   mutex --> lock_guard  
   
   
   %% 自动析构，不用unlock
   lock --> adopt_lock
   
   lock --> try_to_lock
   
   lock --> defer_lock
   
   %% 单线程重复进入mutex避免死锁；保护 shared data 单线程 exclusive
   mutex --> recursive_mutex
%%    lock_guard --> recursive_mutex 
   
   %% timed_mutex provides the ability to attempt to claim ownership of a timed_mutex with a timeout via the try_lock_for() and try_lock_until() methods.
   mutex --> timed_mutex
   
   timed_mutex --> try_lock_for
   timed_mutex --> try_lock_until
   
   %% 函数，传参，如何？待看源码。构造函数被调几次，是如何调的。传引用，指针。。。右值引用？？？mutable???
   thread
   %% std::ref 能把 真引用 弄进去，之后不能detach
   %% 类的成员函数是有地址的，成员变量是位移
   
   %% Separates the thread of execution from the thread object, allowing execution to continue independently. Any allocated resources will be freed once the thread exits. After calling detach *this no longer owns any thread.
   thread --> detach
   
   %% Checks if the std::thread object identifies an active thread of execution. Specifically, returns true if get_id() != std::thread::id(). So a default constructed thread is not joinable. A thread that has finished executing code, but has not yet been joined is still considered an active thread of execution and is therefore joinable.
   thread --> joinable  %% 没有被detach或join
   
   thread --> join
   
 
```

```mermaid
graph TD;

   %% sleep_for 让线程休眠
   this_thread --> sleep_for --> `time`
   
   chrono --> steady_clock
   
   %% Returns a time point representing the current point in time.
   steady_clock --> now
   
   %% Class template std::chrono::duration represents a time interval.
   chrono --> duration
   
   %% returns the count of ticks(嘀嗒)
   duration --> count
   
   chrono --> `time`
   
   `time`--> nanoseconds
   `time`--> microseconds
   `time`--> milliseconds
   `time`--> seconds
   `time`--> minutes
   `time`--> hours
```

```mermaid
graph TD
%% Each std::call_once is matched to a std::once_flag variable. 
call_once 
```

```mermaid
graph TD;

	%% The class unique_lock is a general-purpose mutex ownership wrapper allowing deferred locking, time-constrained attempts at locking, recursive locking, transfer of lock ownership, and use with condition variables.
	unique_lock
	%% 转移所有权：std::move
	
	scoped_lock
	
	lock_guard
```

