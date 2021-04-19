#include<iostream>

int add(int a, int b){
    return a + b;
}

int whichfun(int (*f)(int, int), int a, int b) {
    return f(a, b);
}

int main(){
    std::cout<<whichfun(add, 123, 654)<<std::endl;

}