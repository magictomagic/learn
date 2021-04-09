#include<iostream>
#include<vector>
#include<thread>
#include<mutex>

std::recursive_mutex mutex;

struct SaveCounter{
    int value = 0;
    SaveCounter(): value(0){}
    void plus_one(){
        std::lock_guard<std::recursive_mutex> lock(mutex);
        value ++;
    }
    void minus_one(){
        std::lock_guard<std::recursive_mutex> lock(mutex);
        value --;
    }

    // recursive can acquire the same mutex repeatedly by same thread so it avoid deadlock in this situation
    void both(){
        std::lock_guard<std::recursive_mutex> lock(mutex);
        minus_one();
        plus_one();
    }
};


int main(){
    SaveCounter counter;
    std::vector<std::thread> tp;
    for(int i = 0; i < 5; i++){
        tp.push_back(std::thread([&counter](){
            for(int i = 0; i < 500; i++){
                counter.both();
            }
        }));
    }

    for(auto &t: tp){
        t.join();
    }
    std::cout << counter.value << std::endl;
    return 0;
}