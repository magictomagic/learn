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
  