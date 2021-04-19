#include<iostream>
#include<functional>

void fun_1(int a, int b){
    std::cout<<"fun_1"<<" "<<a<<" "<<b<<std::endl;
}

void fun_2(int &a, int &b){
    a++;b++;
    std::cout<<"fun_2"<<" "<<a<<" "<<b<<std::endl;
}

int main(){
    auto f1 = std::bind(fun_1, 2, 3);
    f1();

    auto f2 = std::bind(fun_1, 5, std::placeholders::_1);
    f2(1);

    auto f3 = std::bind(fun_1, std::placeholders::_1, std::placeholders::_2);
    f3(7, 8);

    auto f4 = std::bind(fun_1, std::placeholders::_2, std::placeholders::_1);
    f4(7, 8);

    int a = 1, b = 1;
    auto ff1 = std::bind(fun_2, std::placeholders::_1, a); 
    ff1(b);

    std::cout<<a<<" "<<b<<std::endl;
    // bind对于不事先绑定的参数，通过std::placeholders传递的参数是通过引用传递的
    // bind对于预先绑定的函数参数是通过值传递的
}