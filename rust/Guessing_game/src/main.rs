use std::io;
use std::cmp::Ordering;
use rand::Rng;
use colored::*;

fn main(){

    println!("Guessing Game:");
    
    let sec_num = rand::thread_rng().gen_range(1, 101); //thread_rng is a number generator and
                                                        //gen_range gives range.

    loop{
        let mut guess = String::new(); //guess is immut by default so mut kw is req, String::new() is
                                       //a fn new of string type.
    
        println!("Enter a number between 1 to 100:");

        io::stdin().read_line(&mut guess).expect("Failed to read line"); //read_line gives an enum
                                                                         //result with types ok or
                                                                         //err where err needs to
                                                                         //be handled.

        let guess : u32 = match guess.trim().parse(){
            Ok(num) => num,
            Err(_) => continue,
            };

        match guess.cmp(&sec_num){
            Ordering::Less => println!("{}", "TOO SMALL".red().bold()),
            Ordering::Greater => println!("{}", "TOO BIG".red().bold()),
            Ordering::Equal => {
                println!("{}", "You Win".green().bold());
                break;
            },
        }
    }

}
