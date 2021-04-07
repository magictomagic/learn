// https://nodejs.org/api/esm.html#esm_mandatory_file_extensions
// Node.js treats JavaScript code as CommonJS modules by default. Authors can tell Node.js to treat JavaScript code as ECMAScript modules via the .mjs file extension, the package.json "type" field, or the --input-type flag. See Modules: Packages for more details.

// The file extension is always necessary for these.
import {addTwo} from './mymodule.mjs'

const asyncMsg = await Promise.resolve('WORKS!');
console.log(asyncMsg); // "WORKS!"

console.log(addTwo(34, 45)) // 79

// 总结: 这功能目前还是实验阶段，还是躺着等他们继续完善吧。