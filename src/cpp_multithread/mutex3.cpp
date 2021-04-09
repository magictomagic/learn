#include<iostream>
#include<vector>
#include<thread>
#include<mutex>

struct SaveCounter{
    std::mutex mutex;
    // Counter counter;
    int value = 0;
    SaveCounter(): value(0){}
    void plus_one(){
        mutex.lock();
        value ++;
        mutex.unlock();
    }
    void minus_one(){
        mutex.lock();
        try{
            value --;
        }catch(std::string e){
            mutex.unlock();
            throw e;
        }
        mutex.unlock();
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