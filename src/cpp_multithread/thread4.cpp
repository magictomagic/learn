#include<iostream>
#include<chrono>
#include<thread>

void dissociativeThread(const std::string &a, std::string b){
    std::cout<<"start dissociativeThread  "<<a + b<<std::endl;
    // std::this_thread::sleep_for(std::chrono::seconds(1));
    // std::cout<<"end dissociativeThread"<<std::endl;
}

int main(){
    // dissociativeThread();
    char mybuf[] = "test";
    // 需要读 thread 源码
    // std::thread t1(dissociativeThread, string(mybuf), "ASD");

    std::this_thread::sleep_for(std::chrono::seconds(2));
    return 0;
}