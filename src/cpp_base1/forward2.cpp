#include<iostream>
#include<utility>

struct Test1
{
    std::string left_v = "left";
    std::string right_v = "right";
    std::string& Name() & {
        return left_v;
    }
    std::string Name() && {
        return right_v;
    }
};

struct Mt
{
    Mt(const std::string& n){
        std::cout<<"copy"<<n<<std::endl;
    }
    Mt(std::string&& n){
        std::cout<<"move"<<n<<std::endl;
    }
};

template<typename T>
Mt Fm(T&& a){
    return Mt{
        // std::forward<decltype(a.Name())>(a.Name())  // 當我們寫下 a 這個字的瞬間，他就是左值了 (named value)
        //                      move                        right
        // std::forward<decltype(std::forward<T>(a).Name())>(std::forward<T>(a).Name())  // std::forward 保留 fd 的左右調性
        std::forward<decltype(std::declval<T>().Name())>(std::forward<T>(a).Name())
    };
};

int main(){
    Test1 t1;
    Fm(t1);
    Fm(Test1{});
}