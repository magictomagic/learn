#include<iostream>
#include<vector>
#include<thread>
#include<mutex>

// The class lock_guard is a mutex wrapper that provides a convenient RAII-style mechanism for owning a mutex for the duration of a scoped block.
struct SaveCounter{
    std::mutex mutex;
    // Counter counter;
    int value = 0;
    SaveCounter(): value(0){}
    void plus_one(){
        std::lock_guard<std::mutex> lock(mutex);
        value ++;
    }
    void minus_one(){
        std::lock_guard<std::mutex> lock(mutex);
        value --;
    }
};


int main(){
    SaveCounter counter;
    std::vector<std::thread> tp;
    for(int i = 0; i < 5; i++){
        tp.push_back(std::thread([&counter](){
            for(int i = 0; i < 500; i++){
                counter.plus_one();
            }
        }));
    }

    for(auto &t: tp){
        t.join();
    }
    std::cout << counter.value << std::endl;
    return 0;
}