use rand::Rng;
use std::cmp::Ordering;
use std::io;

fn main() {
    println!("Guess The number: ");
    let randnum = rand::thread_rng().gen_range(1..=100);
    println!("{randnum}");

    loop {
        let mut guess = String::new();
        io::stdin()
            .read_line(&mut guess)
            .expect("Failed to Read line");

        let guess: u32 = match guess.trim().parse() {
            Ok(num) => num,
            Err(_) => {
                println!("Please Enter a number!");
                continue;
            }
        };
        match guess.cmp(&randnum) {
            Ordering::Less => println!("Too small!"),
            Ordering::Greater => println!("Too Big!"),
            Ordering::Equal => {
                println!("You win!");
                break;
            }
        }
    }
}
