use std::io;
fn main() {
    println!("Enter 5 numbers in a single line:");
    let mut arr = String::new();
    io::stdin()
        .read_line(&mut arr).expect("Failed to read line");
    let mut x : [u8; 6] = [0; 6];
    let mut count = 0;
    for i in arr.split_whitespace(){
        if count >= 6 {
            break;
        }
        if let Ok(i) = i.parse::<u8>(){ //type annotations not allowed in if let syntax so use
                                         //turbofish syntax.
            x[count] = i;
            count += 1;
        }
    }
    let result = my_fn(&x);
    println!("{}", result);

}

fn my_fn(x: &[u8; 6]) -> u8{
    let mut sum = 0;
    for num in x{
        sum += num;
    }
    sum
}
