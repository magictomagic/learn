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

// ------------------- //

const run = () => {
    // https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Promise/all
    // The Promise.all() method takes an iterable of promises as an input, and returns a single Promise that resolves to an array of the results of the input promises. 
    // Promise.all(iterable);
    // async return a Promise
    return Promise.all([1, 2, 3, 4, 5].map(async (item) => { // 若这一行加 await, 则套它的函数要加 async
        return item + " : " + await myReadSync()
    }))
}

const parcelRun = async () => {
    // 套一层 async 很难受。先是 Promise 解决 回调地狱，出现了 then地狱；接着 await 解决前者，出现了 套套地狱
    // 解决方案：TS3.8 支持 Top-Level await
    // https://www.typescriptlang.org/docs/handbook/release-notes/typescript-3-8.html#top-level-await
    console.log(await run())
    console.log("next 1")
}

parcelRun()

// Output:
// [
//     "1 : const fs = require('fs');\r\n",
//     "2 : const fs = require('fs');\r\n",
//     "3 : const fs = require('fs');\r\n",
//     "4 : const fs = require('fs');\r\n",
//     "5 : const fs = require('fs');\r\n"
// ]
// next 1
  