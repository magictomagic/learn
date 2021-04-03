const spawn = require("child_process").spawn;
const pythonProcess = spawn('python',["first.py", "data send to python as a param"]);
pythonProcess.stdout.on('data', (data) => {
    // Do something with the data returned from python script
    console.log(data.toString())
});

console.log("callback function is pushed to task queue, so this job on execution context stack will print first")