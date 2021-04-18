#include<iostream>
#include<utility>
// static_cast<T&&>(x)  losing r-value references 
// perfect forwarding allows to pass both r-value references and l-value references. This is done via reference collapsing:


// 万能引用(T&& param): 既能接受左值类型的参数，也能接受右值类型的参数。

// 引用折叠: 
// （引用折叠规则）：如果间接的创建一个引用的引用，则这些引用就会“折叠”。在所有情况下（除了一个例外），引用折叠成一个普通的左值引用类型。一种特殊情况下，引用会折叠成右值引用，即右值引用的右值引用， T&& &&。

// “引用的引用”是非法的。像auto& &rx = x;（注意两个&之间有空格）这种直接定义引用的引用是不合法的，但是编译器在通过类型别名或模板参数推导等语境中，会间接定义出“引用的引用”，这时引用会形成“折叠”。
// 引用折叠会发生在模板实例化、auto类型推导、创建和运用typedef和别名声明、以及decltype语境中。

// （二）引用折叠规则

// 　　1. 两条规则

// 　　　　（1）所有右值引用折叠到右值引用上仍然是一个右值引用。如X&& &&折叠为X&&。

// 　　　　（2）所有的其他引用类型之间的折叠都将变成左值引用。如X& &, X& &&, X&& &折叠为X&。可见左值引用会传染，沾上一个左值引用就变左值引用了。根本原因：在一处声明为左值，就说明该对象为持久对象，编译器就必须保证此对象可靠（左值）。

// 　　2. 利用引用折叠进行万能引用初始化类型推导

// 　　　　（1）当万能引用（T&& param）绑定到左值时，由于万能引用也是一个引用，而左值只能绑定到左值引用。因此，T会被推导为T&类型。从而param的类型为T& &&，引用折叠后的类型为T&。

// 　　　　（2）当万能引用（T&& param）绑定到右值时，同理，右值只能绑定到右值引用上，故T会被推导为T类型。从而param的类型就是T&&（右值引用）。

struct HeavyData{
};

struct ExtractData{
    ExtractData(const HeavyData&){
        puts("copy");
    }

    ExtractData(HeavyData&&){
        puts("move");
    }

};


template<typename T>
ExtractData Extract(T&& fd){
    return ExtractData{std::forward<T>(fd)};
    // return ExtractData{fd};
}

int main(){
    HeavyData h1;

    ExtractData{h1};
    ExtractData{std::move(h1)};

    Extract(h1);
    Extract(std::move(h1));  // 使用forward, 输出的 copy 变 move

}