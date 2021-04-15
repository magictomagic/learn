#include<iostream>
#include<algorithm>  // lower_bound upper_bound
#include<vector>

int main(){
    std::vector<int> v = {2, 3, 6, 7, 8};
    auto a = std::lower_bound(v.begin(), v.end(), 6);  // [
    auto b = std::upper_bound(v.begin(), v.end(), 6);  // )

    std::cout<<(a - v.begin())<<std::endl;
    std::cout<<(b - v.begin())<<std::endl;
}