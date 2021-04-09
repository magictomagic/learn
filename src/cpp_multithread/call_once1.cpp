#include <thread>
#include <iostream>
#include <chrono>
#include <mutex>

std::once_flag flag;

void test(){
    std::call_once(flag, [&](){
        std::cout<<"called once"<<std::endl;
    });
    std::cout<<"called each time"<<std::endl;
    

};

int main(){

    std::thread t1(test);
    std::thread t2(test);
    std::thread t3(test);
    std::thread t4(test);

    t1.join();
    t2.join();
    t3.join();
    t4.join();

}