fn main() {
    let y = 5;
    println!("{}", y);
    //y is immutable
    let mut x = 5;
    println!("{}", x);
    x = 6;
    println!("{}", x);
    //x is mutable
    
    const NUMBER : i32 = 10_000; //consts should be uppercase and with underscore for space, also
                                //type inference does not work on const hence, type should be
                                //specified. they are IMMUTABLE. they cannot be set as a value
                                //computed during run time eg : return val of fn ,etc.

    let x = 5;
    println!("{}", x);
    let x = "six";
    println!("{}", x);
    //x is shadowed!
    

    //scalar vs compound data types.
    //scalar -> represent a single value.
    //compound -> represent a grp of values.
    //
    //4 main scalar datatypes :
    // 1)Integers
    let a = 98_222; //decimal
    let b = 0xff; //octal
    let c = 0o77; //hex
    let d = 0b1111_0000; //binary
    let e = b'A'; //Byte (u8 only) will give the ascii value of A as a byte.

    //overflow
    //let a : u8 = 256; will either produce a panic or wrap around to produce mod 256 values.

    // 2)Floating point numbers
    let a: f32 = 2.0;
    let b: f64 = 3.0;

    // 3)Booleans
    let t = true;
    let f: bool = false;
    // 4)Characters
    let c = 'z';
    let d:char = 'Z';

    //compound types
    let tup = ("let me go", 98_222);
    //destructuring a tuple
    let (channel, subcount) = tup;
    //or
    let sub_count = tup.1;

    //arrays are fixed length bracketed in rust unlike vectors which can change size.
    let err = [1, 2, 3];
    let not_found = err[1];
    let byte = [0; 8]; //create an array with 8 indices all set to zero.

    let x = my_fn(1, 2);
    println!("{}", x);

    if x < 0 { //condition should be explicitly a boolean so something like if(1) wont work
        println!("{}", x);
    }
    else if x == 3{
        println!("9");
    }
    else{
        println!("7");     
    }

    //can replace a ternary operator
    let x = if x == 3 {4} else {5};

    //3 types of loops
    //loop
    loop{
        println!("x");
        break;
    }

    // could also return values from this type of loop
    let counter = 0;
    let result = loop{
        println!("x");
        break counter;
    };
    //while loop
    while true {
        break;
    }

    //for loop
    for ele in err.iter(){
        println!("{}", ele);
    }
    //or
    for num in 1..40 { //exvlusive
        println!("{}", num);
    }
    /*
     *comments are same as c and cpp;
     */


}

fn my_fn(x: i32, y:i32) -> i32{ //all lowercase with underscore for space
    println!("another fn");
    //let sum = x + y;
    //return sum;
    //the last expression is implicitly return in rust so instead of return sum you can do 
    //just "sum"(omitting semicolon is allowed for last expr) or even:
    x + y
}
