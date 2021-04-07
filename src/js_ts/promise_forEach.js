const redis = require("redis");
const client = redis.createClient();

client.on("error", function(error) {
  console.error(error);
});


db_name = 'if_del';


// client.hget(db_name, 'test1', (err, res) => {
//     console.log(res);
// });

// client.hget(db_name, 'test', (err, res) => {
//     console.log(res);
// });
let fish_dragon = ['234343324', '32434324543']
let delete_set = new Set()
let ss = {}
fish_dragon.forEach(  (item) => {
    client.hget(db_name, item, (err,  res) =>  {
        // let aa = await res
        if (res) {
            delete_set.add(item)
        }else{
            // del_store[item] = data_test[item]
            ss[item] = 'd'
            console.log(ss)
        }
        
    });
    // ss[item] = 'd'
    // return await 
})

console.log(ss)
client.quit()


