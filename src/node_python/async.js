const spawn = require("child_process").spawn;
const path = require("path")
pythonFile = path.join(__dirname, "first.py")
const pythonProcess = spawn('python',[pythonFile, "data send to python as a param"]);
pythonProcess.stdout.on('data', (data) => {
    // Do something with the data returned from python script
    console.log(data.toString())
});

console.log("Callback function is pushed to task queue, so this job on execution context stack will print first")