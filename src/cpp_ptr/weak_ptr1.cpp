#include<iostream>
#include<memory>
#include<utility>

class Obj{
    public:
    std::string ddafs(){
        return "23322";
    }
};

int main(){
    auto asd = std::make_shared<std::string>("dafsdasfs");
    std::shared_ptr<Obj> sdf(new Obj());

    auto dfg = asd;
    auto fgh(asd);
    std::cout<<*asd<<std::endl;
    std::cout<<sdf->ddafs()<<std::endl;

    std::cout<<sdf.use_count()<<std::endl;
    std::cout<<asd.use_count()<<std::endl;

    asd.reset();  // 全部扔掉，扔掉！
    std::cout<<asd.use_count()<<std::endl;

    // 当我们创建一个weak_ptr时，需要用一个shared_ptr实例来初始化weak_ptr
    auto sss = std::make_shared<std::string>("2132312");

    // weak_ptr不会改变shared_ptr，但是会和shared_ptr的引用保持一致
    std::weak_ptr<std::string> wk = sss;

    std::cout<<wk.expired();

    wk.reset();
    std::cout<<wk.expired();

}