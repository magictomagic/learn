use std::io;
use rand::Rng;
use std::cmp::Ordering;

fn main() {
    // --snip--
    println!("Guess the number!");

    let sn = rand::thread_rng().gen_range(1, 101);

    // println!("The secret number is: {}", sn);

    loop{
        println!("Please input your guess,");
        let mut guess = String::new();
        io::stdin()
        .read_line(&mut guess)
        .expect("Failed to read line");

        println!("You guessed: {}", guess);

        // let guess: u32 = guess.trim().parse().expect("please enter a number");

        let guess: u32 = match guess.trim().parse(){
            Ok(num) =>num,
            Err(_) => continue,
        };


        match guess.cmp(&sn){
            Ordering::Less => println!("Too small"),
            Ordering::Greater => println!("Too big"),
            Ordering::Equal => {
                println!("You win");
                break;
            }
        }
    }
    

}
