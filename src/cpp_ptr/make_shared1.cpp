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
}