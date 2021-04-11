// 泛型 
// 多个
function asd<T, K>(a: T, b: K):[T, K] {
    return [a, b]
}
const aa =  asd("asas", 12321)  // 类型自动推导
console.log(aa)
const bb = asd<string, number>("dasda", 123) // 手动指定
console.log(bb)

// 对模板作限制
interface DFG{
    length: number
}
function sdf<T extends DFG>(a: T){
    console.log(a)
}

sdf("dasfs")



// 类
class fgh<T>{
    hjk:T;
    constructor(a: T){
        this.hjk = a
    }
}

const ghj = new fgh<string>("dsafs") 
console.log(ghj.hjk)