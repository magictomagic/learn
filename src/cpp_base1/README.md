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

所有需要用到 , (comma operator) 的地方，就可以展開 parameter pack

Note that if the name of an object is parenthesized, it is treated as an ordinary lvalue expression, thus decltype(x) and decltype((x)) are often different types.


**decltype**: 不需要计算表达式就可以推导出表达式所得值的类型。
当你需要某个表达式的返回值类型而又不想实际执行它时用decltype。

**std::declval**
Converts any type T to a reference type, making it possible to use member functions in decltype expressions **without the need to go through constructors.**