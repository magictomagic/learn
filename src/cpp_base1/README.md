### TODO
move 左值强制转右值，语义移动而不复制
forward 通过引用折叠的方式不改变原来的左右值
源码分析 上面两个
```c++
auto z1 {99};   // z1 is an int
auto z2 = {99}; // z2 is std::initializer_list<int>
auto z3 = 99;   // z3 is an int
```
Conclusion
Prefer {} initialization over alternatives unless you have a strong reason not to.