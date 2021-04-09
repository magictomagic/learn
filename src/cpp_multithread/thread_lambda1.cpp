#include<iostream>
#include<thread>
#include<vector>

int main(){
    std::vector<std::thread> tv;

    // Initialize thread vector
    for(int i = 0; i < 4; i++){
        tv.push_back(std::thread(
            [](){
                 std::cout<<"hello again: "<<std::this_thread::get_id()<<std::endl;
            }
        ));
    }

    // A thread can be preempted at any moment 
    for(auto& t:tv){
        t.join();
    }

    return 0;
}