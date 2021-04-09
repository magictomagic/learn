// https://baptiste-wicht.com/posts/2012/03/cpp11-concurrency-part1-start-threads.html#

#include<iostream>

// All the threads utilities are located in the thread header
#include<thread>

void hello_world(){
    std::cout<<"hello world";
}

int main(){

    // When you create a thread you have to give it the code it will execute.
    std::thread t1(hello_world);   

    // Calling this function forces the current thread to wait for the other one 
    // in this case, the main thread has to wait for the thread t1 to finish
    t1.join();



    return 0;
}