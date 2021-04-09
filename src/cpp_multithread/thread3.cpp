#include<iostream>
#include<chrono>
#include<thread>

void dissociativeThread(){
    std::cout<<"start dissociativeThread"<<std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout<<"end dissociativeThread"<<std::endl;
}

void manipulateThread(){
    std::cout<<"start manipulateThread"<<std::endl;
    std::thread td(dissociativeThread);
    // std::this_thread::sleep_for(std::chrono::seconds(2));
    std::cout<<td.joinable()<<std::endl;
    td.detach();
    std::cout<<td.joinable()<<std::endl;
    // td.join();
    std::cout<<"end manipulateThread"<<std::endl;
}


int main(){
    manipulateThread();
    std::this_thread::sleep_for(std::chrono::seconds(2));
    return 0;
}