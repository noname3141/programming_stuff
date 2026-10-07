use std::io;
use rand::Rng;

fn main() {
    let sec = rand::thread_rng().gen_range(1..=100);

    println!("Enter your number:");
    
    let mut guess = String::new();

    io::stdin()
        .read_line(&mut guess)
        .expect("Failure");

    println!("The Secret Number is: {sec}");

    println!("the number was {guess}");
}
