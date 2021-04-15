#include<iostream>

// 函数模板
template <typename T>
std::string f1(T a){
    if(a.size()){
        return "has size";
    }else{
        return "hasn't size";
    }
}

// 类模板
template <typename T>
class AS{
    public:
    T aa;
    AS(T a){
        this->aa = a;
    }
};

// 总结：用T前加行T的声明
int main(){
    std::cout<<f1<std::string>("adsfsaADSFVFDSAS")<<std::endl;
    AS<std::string> dd("ads");
    std::cout<<dd.aa<<std::endl;
}