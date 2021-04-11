#include<iostream>

class Asd{
    public:
    int a;
    int b;

    Asd(): a(1), b(2){}

    Asd(int a, int b){
        this->a = a;
        this->b = b;
    }

    Asd operator+(const Asd & aa){
        Asd tmp;
        tmp.a = this->a + aa.a;
        tmp.b = this->b + aa.b;
        return tmp;
    }
};

int main(){
    Asd a1(2, 3), a2(5, 6), a3;
    std::cout<<a1.a<<" "<<a1.b<<std::endl;
    std::cout<<a3.a<<" "<<a3.b<<std::endl;
    a3 = a1 + a2;
    std::cout<<a3.a<<" "<<a3.b<<std::endl;
}