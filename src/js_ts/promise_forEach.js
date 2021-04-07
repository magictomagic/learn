const fs = require('fs');

const myReadSync = async () => {
    return await new Promise((resolve, reject) => {
        setTimeout(() => {
            fs.readFile('./promise_base.js', (err, data) => {
                resolve(data.toString().substring(0, 27))
            })    
        }, 1000);
    })
}

// ------------------- //

// 等 forEach 里每个都执行完了再执行后面的操作，相当于模拟一个 stake

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
    // console.log("next")
}

const parcelRun = async () => {
    console.log(await run())
    console.log("next 1")
}

// run()
parcelRun()

