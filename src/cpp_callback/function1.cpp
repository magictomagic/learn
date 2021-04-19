#include<iostream>
#include<functional>

// 函数指针不安全，套一层后变成std::function就安全了
typedef std::function<int(int, int)> triint;  

int funadd(int a, int b){
    return a + b;
}

auto lamadd = [](int a, int b) -> int {
    return a + b;
};

struct functoradd
{
    int operator()(int a, int b){
        return a + b;
    }
};

int main(){
    triint a = funadd;  // 获得函数，延时执行
    triint b = lamadd;  // 获得函数，延时执行
    triint c = functoradd();    // 闭包 // 获得函数，延时执行
    std::cout<<a(12345, 9876)<<std::endl;
    std::cout<<b(12345, 9876)<<std::endl;
    std::cout<<c(12345, 9876)<<std::endl;
}