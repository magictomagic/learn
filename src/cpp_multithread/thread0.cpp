#include<iostream>
#include<thread>

void hello_world(){
    std::cout<<"hello world";
}

int main(){
    std::thread t1(hello_world);
    t1.join();
    return 0;
}