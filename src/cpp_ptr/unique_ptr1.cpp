// auto_ptr 已经弃用，谁再问我就骂他
#include<iostream>
#include<memory>  // 智能指针需要
#include<utility> // move 需要
// 通过 make_unique 创建，move转移


std::unique_ptr<std::string> mymove(const std::string& fgh){
    std::unique_ptr<std::string> ghj = std::make_unique<std::string>(fgh);
    return ghj;
}

// 用智能指针封装大型对象指针, 需要new一下。在堆上开辟一块区域拿一个unique_ptr指针就是封装了
class LargeObj{
    public: 
    void adfsf(){
        std::cout<<"0925847203-"<<std::endl;
    }
};


int main(){
    auto asd = std::make_unique<std::string>("asas");
    std::cout<<*asd<<std::endl;
    std::unique_ptr<std::string> sdf = std::move(asd);
    std::cout<<*sdf<<std::endl;
    // std::cout<<*asd<<std::endl;
    auto dfg = mymove("ddfsafdssfderqwrdg");
    std::cout<<*dfg<<std::endl;

    std::unique_ptr<LargeObj> hjk(new LargeObj());
    hjk->adfsf();

    // 初始化数组
    auto jkl = std::make_unique<int[]>(3);
    for(int i = 0; i < 3; i++){
        jkl[i] = 234;
    }

}