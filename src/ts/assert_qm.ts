let str: any = "dfssadss"
let num = (str as string).length

console.log(num)

// 1、as和!用于属性的读取，都可以缩小类型检查范围，都做判空用途时是等价的。只是!具体用于告知编译器此值不可能为空值（null和undefined），而as不限于此。! 是 非null和非undefined的类型断言
// 2、?可用于属性的定义和读取，读取时告诉编译器此值可能为空值（null和undefined），需要做判断。


interface Cat {
    action: string;
}
interface Dog {
    action: string;
}
type Animal = Cat | Dog;
let action:Animal = {} as Cat;


//------ ? 用法  ------//
// https://github.com/e2tox/blog/issues/9

// 这里的 ？表示这个参数 field 是一个可选参数
function getUser(user: string, field?: string) {
}

// 这里的？表示这个name属性有可能不存在
class A {
    name?: string
}
  
interface B {
    name?: string
}

// 这里 Error对象定义的stack是可选参数，如果这样写的话编译器会提示
// 出错 TS2532: Object is possibly 'undefined'.
new Error().stack.split('\n');

// 我们可以添加?操作符，当stack属性存在时，调用 stack.split。若stack不存在，则返回空
new Error().stack?.split('\n');

// 以上代码等同以下代码
const err = new Error();
err.stack && err.stack.split('\n');


//------ ! 用法  ------//
// https://github.com/e2tox/blog/issues/9

// 因为接口B里面name被定义为可空的值，但是实际情况是不为空的，那么我们就可以
// 通过在class里面使用！，重新强调了name这个不为空值
class C implements D {
    name!: string
}

interface D {
  name?: string
}

// 这里 Error对象定义的stack是可选参数，如果这样写的话编译器会提示
// 出错 TS2532: Object is possibly 'undefined'.
new Error().stack.split('\n');

// 我们确信这个字段100%出现，那么就可以添加！，强调这个字段一定存在
new Error().stack!.split('\n');