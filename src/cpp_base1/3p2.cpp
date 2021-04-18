#include <iostream>
// 所有需要用到 , (comma operator) 的地方，就可以展開 parameter pack

template<typename T> struct C { };

template<>
struct C<int> {
  void say_hi(int) { puts("int hi"); }
};

template<>
struct C<double> {
  void say_hi(double) { puts("double hi"); }
};

template<>
struct C<char> {
  void say_hi(char) { puts("char hi"); }
};

template<typename... Args>
struct D {
  void say_hi();
};

// C++11
// template<typename First, typename... Args> 
// struct D<First, Args...> : C<First>, D<Args...> { // 相当于宣告递归，最终还是由边界条件承担，类似于js中reduce
//   using C<First>::say_hi;
//   using D<Args...>::say_hi;
// };

//C++17
// template<typename ...Args>
// struct D: C<Args>...{
//     using C<Args>::say_hi...;
// };


template<typename... Args>
struct D : C<Args>... {
  using C<Args>::say_hi...;
};

int main()
{
  D<int, double, char> d;
  d.say_hi(1);    // int hi
  d.say_hi(2.1);  // double hi
  d.say_hi('a');  // char hi
}