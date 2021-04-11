#include<iostream>
#include<algorithm>
#include<vector>

// 仿函数，隔离运行时函数环境，相当于js, python中的闭包
template <class T>
class myprint{
    public:
    operator()(const T& x){
        std::cout<<x<<std::endl;
    }
};

int main(){
    std::vector<int> a = {3,5,6,7,8,4,3,9};

    std::for_each(a.begin(), a.end(), myprint<int>());
}