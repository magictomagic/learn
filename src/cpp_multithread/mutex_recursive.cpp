#include<iostream>
#include<vector>
#include<thread>
#include<mutex>

// The recursive_mutex class is a synchronization primitive that can be used to protect shared data from being simultaneously accessed by multiple threads.

class Test{
    private:
        std::recursive_mutex rm;
        std::string shared_data;
    public:
        void fun1(){
            std::lock_guard<std::recursive_mutex> lock(rm);
            shared_data = "dfghjhgfddfghj";
            std::cout<<"hello recursive mutex: "<<shared_data<<std::endl;
        }
        void fun2(){
            std::lock_guard<std::recursive_mutex> lock(rm);
            shared_data = "5678765456789";
            std::cout<<"hello again: "<<shared_data<<std::endl;
        }
};


int main(){
    Test test;
    std::thread t1(&Test::fun1, &test);
    std::thread t2(&Test::fun2, &test);
    t1.join();
    t2.join();

    return 0;
}