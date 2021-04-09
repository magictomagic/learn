#include <thread>
#include <iostream>
#include <chrono>
#include <mutex>
 
std::timed_mutex test_mutex;
 
void f()
{
    std::lock_guard<std::timed_mutex> l(test_mutex);
    auto now=std::chrono::steady_clock::now();
    test_mutex.try_lock_until(now + std::chrono::seconds(3));
    std::cout << "hello world\n";
}
 
int main()
{
    std::thread t(f);
    t.join();
}