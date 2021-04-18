#include<iostream>

// 定义边界条件，重载

template<typename T>
T test1(const T& a){
    return a;
}

template<typename T, typename... Args>
T test1(const T& a, const Args&... args){
    // puts(args...);
    return a + test1(args...);  // test1(a, b, c, ...)
    // 若test1(args)... 则是 test1(a), test(b), test(c), ...
}

template <typename... Ts>
struct T2
{
    /* data */
};


int main(){
    std::cout<<test1(12, 34, 56);
    std::cout<<test1((std::string)"asd", (std::string)"Adasd", (std::string)"52354235");  // (std::string) 使 const char[n] 转换
    T2<int, double> asd;
}