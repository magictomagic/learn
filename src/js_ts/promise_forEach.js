const fs = require('fs');

const myReadSync = async () => {
    return await new Promise((resolve, reject) => {
        setTimeout(() => {
            fs.readFile('./promise_forEach.js', (err, data) => {
                resolve(data.toString().substring(0, 27))
            })    
        }, 1000);
    })
}

// ------------------- // 等 forEach 里每个都执行完了再执行后面的操作，相当于模拟一个 stake

// await 把异步变为同步
// const run =  () => {
//     [1, 2, 3, 4, 5].forEach(async (item) => {  // 在这一行加 await 可控制 forEach 同步(顺序)执行, 否则异步(乱序)
//         console.log(item.toString() + " : " + await myReadSync())
//     })
//     console.log("next")
// }

const run = async () => {
    return new Promise((resolve, reject) => {
        [1, 2, 3, 4, 5].forEach(async (item) => {  
            resolve(item.toString() + " : " + await myReadSync())
            // console.log(item.toString() + " : " + await myReadSync())
        })
    })
}

const parcelRun = async () => {
    // https://stackoverflow.com/questions/37576685/using-async-await-with-a-foreach-loop
    // you cannot use forEach indeed. Each of the async callback function calls does return a promise, but you're throwing them away instead of awaiting them. Just use map instead
    console.log(await run()) // 只返回一个
    console.log("next 1")
}


parcelRun()

// 解决方案1: Just use a modern for … of loop instead, in which await will work as expected
// 解决方案2: map +  Promise.all
