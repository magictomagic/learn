### 可调用对象
+ 函数
+ 函数指针 -> 高阶函数

bind 相当于：函数柯里化&&延迟执行
bind对于不事先绑定的参数，通过std::placeholders传递的参数是通过引用传递的
bind对于预先绑定的函数参数是通过值传递的