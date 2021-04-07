const fs = require('fs')

// 加个 async 让 原有的东西变 pending
const myReadSync = async () => {
    // 加个 await 让 Promise 执行完
    const value = await new Promise((resolve, reject) => {
        fs.readFile('./promise_base.js', (err, data) => {
            resolve(data.toString().substring(0, 27))
        })
    })
    console.log(value) // 打印出来了 // 因为 await 使原有的 pending 向后推进
    return value
}

console.log(myReadSync())  // pending // 因为加了 async, 返回 Promise 对象
console.log("next")

// ------------------- //

const run = async () => {
    console.log(await myReadSync())
}

run()  // 不想用 then, 为了用 await 推进状态, 要套一层 async 适配语法.