#include <thread>
#include <iostream>
#include <chrono>
#include <mutex>
 
std::timed_mutex test_mutex;
 
void f()
{
    std::lock_guard<std::timed_mutex> l(test_mutex);
    test_mutex.try_lock_for(std::chrono::seconds(5));
    std::cout << "hello world\n";
}
 
int main()
{
    std::thread t(f);
    t.join();
}