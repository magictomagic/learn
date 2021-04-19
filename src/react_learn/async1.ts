const getItems = ({a, b}) => {
    return a + b;
}

async function aa(){
    const store =  await getItems({a: String, b: String});
    for (const asd of store){
        console.log(asd);
    }
}
aa();
// console.log()