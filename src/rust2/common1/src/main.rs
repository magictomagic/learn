#![allow(unused)]
fn main() {
    // 元组 解构赋值，取index，限定值
    let asd = (1,2,3);
    let sdf:(u8, f64, i32) = (4,5.0,6);
    println!("{}", asd.0);
    let (s, d, f) = sdf;
    println!("{}", s);

    // Array 初始化 限定值
    let a:[i32; 3] = [123, 345, 56];
    let b = [2345; 2]; 
    println!("{}", b[0]);

    fn1(2345);
}

fn fn1(x: i32){
    println!("dasfsdsdasds: {}", x);
}