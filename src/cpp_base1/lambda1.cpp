#include<iostream>
#include<functional>  // to use std::function
#include<string>  // to_string

int main(){
    auto fun1 = [&](int a, int b){
        auto asd = a + b;
        return asd;
    };

    std::cout<<fun1(1234, 7654)<<std::endl;

    std::function<std::string(int, int)> f2 = [&](int a, int b){
        auto asd = a + b;
        return std::to_string(asd);
    };
    std::cout<<f2(1234, 7654)<<std::endl;

}