#include<iostream>
#include<memory>
#include<utility>

class Class1;

class Class2{
    public:
    Class2(){
        std::cout<<"class2 construct"<<std::endl;
    }
    ~Class2(){
        std::cout<<"class2 destruct"<<std::endl;
    }
    std::weak_ptr<Class1> cl1;  // if 改成 shared_ptr 则 destruct 不了
};

class Class1{
    public:
    Class1(){
        std::cout<<"class1 construct"<<std::endl;
    }
    ~Class1(){
        std::cout<<"class1 destruct"<<std::endl;
    }
    std::weak_ptr<Class2> cl2;
};

int main(){
    std::shared_ptr<Class1> c1 = std::make_shared<Class1>();
    std::shared_ptr<Class2> c2 = std::make_shared<Class2>();

    c1->cl2 = c2;
    c2->cl1 = c1;

}