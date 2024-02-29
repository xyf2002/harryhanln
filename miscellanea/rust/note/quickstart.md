# Rust Quick Start

Hello, World!

```rust
// main.rs
fn main() {
    println!("Hello, world!"); // println! macro does not take ownership
}
```

Compile with `rustc main.rs -o a.out`

Or you can use cargo, rust's package manager and build system. 

```
cargo new hello-world
cd hello-world
cargo build  # cargo run
cargo run
cargo build --release # build with optimisation 
cargo check # only check, not build
cargo update # update the crates. Will only update minor version
cargo doc --open # build and open the documentation.
```

To use a creates, add it to Cargo.toml like this
```
[dependencies]
rand = "0.9.0"
```

## Comman Functionalities

###  Variable

Rust varaible are immutable by default.

```
let a = 1;
let mut b = 2;
const a :u32 = 3;
```

Rust variable can are in curly bracket scope and can be shadowed.

```
fn main() {
    let x = 5;
    let x = x + 1;  // x = 6. x is a new variable  
    {
        let x = x * 2; // x = 12
    }

    println!("The value of x is: {x}"); // x = 6
}
```

### Data Types

Rust has scaler data type, compound data type, and array data type.

Integer: `u8, u32, u64, i32, i64`.
Floating point: `f32, f64`.
Boolean: `bool`
Char: 4 byte unicode, uses single quote.
Array type is inmutable, vector type is mutable.

```
let yes: bool = true // false
let heart_eyed_cat = '😻';
let a: [i32; 5] = [1, 2, 3, 4, 5];
```

### Expression and Statement

A statement is an imperative line ending with `;`. A expression is a declartive line, that is evaluted into a something. Expression can be part of a statment

```
let a = 5; // This line is a statement. 5 is expression
let y = {
    let x = 3;
    x + 1
}; // y = 4. {} constitutes an expression
```

### Function

Function are also expressions.

```
fn print(x :u32, unit :char) -> u32{
    println!("The value of x is {x}{unit}");
    x + 1  // the return value
}
```
### Control Flow

`if`, `loop`, `for`, `while` are expression in rust.

```rust
let number = 3;

if number < 5 {
    println!("condition was true");
} else {
    println!("condition was false");
}

let condition = true;
let number = if condition { 5 } else { 6 };  // must be of same type
```

Loop in rust is like while true. Loop can be labeled to control breaking behaviour:

```
'counting_up: loop {
    println!("count = {count}");
    let mut remaining = 10;

    loop {
        println!("remaining = {remaining}");
        if remaining == 9 {
            break;
        }
        if count == 2 {
            break 'counting_up;
        }
        remaining -= 1;
    }

    count += 1;
}
```

This is while in rust

```
while number != 0 {
    println!("{number}!");

    number -= 1;
}
```

For in rust 

```
let a = [10, 20, 30, 40, 50];

for element in a {
    println!("the value is: {element}");
}
```

## Rust Ownership, Reference, and Borrowing.

Here is the simple rule: 

-    Each value in Rust has an owner.
-    There can only be one owner at a time.
-    When the owner goes out of scope, the value will be dropped.

For all things that exists in stack, rust behave exactly the same as C.

Complex type, such as String, are stored both in stack and in heap. When reasigning, are passing to function, the owner ship changes to the function or the reassigned variable. When a function returns a value, it also returns the ownership.

```
fn main() {
    let s1 = String::from("hello");
    let s2 = s1;  // s1 no longer valid.

    let s = String::from("hello");  // s comes into scope

    takes_ownership(s);             // s's value moves into the function...
                                    // ... and so is no longer valid here
} // Here, x goes out of scope, then s. But because s's value was moved, nothing
  // special happens.
fn takes_ownership(some_string: String) { // some_string comes into scope
    println!("{}", some_string);
} // Here, some_string goes out of scope and `drop` is called. The backing
  // memory is freed.
``` 

If you do not want to change the ownership, pass a referece with `&`.

Multiple immutable reference can exist at the same time. Only one mutable reference can exist, and it can not coexist with immutable reference.

The scope of immutable reference is between their first apperance and the last.

```
let s1 = String::from("Yes");
printStr(& s1); // pass unmutable reference.
modstring(&mut s1); // pass a mutable reference
```

You can also pass part of the array reference as slice:

```
let s = String::from("hello world");

let hello = &s[0..5];
let world = &s[6..11];

let a = [1, 2, 3, 4, 5];

let slice = &a[1..3];  // type is &[i32]

fn first_word(s: &String) -> &str  //&str is String slice type
```

## Struct

```
#[derive(Debug)]  // this line can be ignore if you are not printing the struct
struct Rect { 
    width: u32,
    height: u32,
}

fn main() {
    let mut rect = Rect {
        width: 10,
        heithg: 10,    
    }
    rect.area();
}

fn area(rect: &Rect) -> u32 {
    rect.width * rect.height
}

impl Rect { 
    fn area(&self) -> u32 {  // this is a method. The first param must be $self
        self.width * self.height
    }
    // an associated function, first param not self
    // call with React::square(2);
    fn square(side: u32) -> Self { 
        Self {
            width:side,
            height: side,
        }
    }
}
```

Struct can have method, whose first param is an object of itself, and associated function that is not method, whose first param is not an object of itself.

Call method with `rect.area()`. Call other associated function with `Rect::square(2)`.

## Package Management and Build System

Rust package is organised into:

-    Packages: A Cargo feature that lets you build, test, and share crates
-    Crates: A tree of modules that produces a library or executable
-    Modules and use: Let you control the organization, scope, and privacy of paths
-    Paths: A way of naming an item, such as a struct, function, or module

When using cargo to compile rust code, cargo look for `src/main.rs` and `src/lib.rs`.  These two can coexist.

Rust's exportable code are organised into module. To use a module, the name of the module needs to be declared.

There can also be submodule. Submodule, `yes`, of module `hello` must be placed in the directory `src/hello`.
```
// file: src/main.rs
mod hello; // declare mod hello

use hello::yes; // bring yes into scope
fn main() {
    hello::hi_from_hello_mod();
    yes::yes(); // or hello::yes::yes();
}
```

```
// file: src/hello.rs
// The name of the file shall fit name of the module

pub mod yes //declare yes module as public
pub fn hi_from_hello_mod() {
    println!("Hi!");
}
```

```
//file src/hello/yes.rs
pub fn yes() {
    println!("yes!");
}
```

## Error Handling

Rust's error handling relies on the enum
```
fn panic_fun() {
    // let mut res = read_username_from_file().unwrap().expect("yes");
    match read_username_from_file() {
        Ok(content) => {println!("{}", content);}
        Err(e) => {println!("{:?}", e);}
    }
}

fn read_username_from_file() -> Result<String, io::Error> {
    let username_file_result = File::open("hello.txt");

    let mut username_file = match username_file_result {
        Ok(file) => file,
        Err(e) => return Err(e),
    };

    let mut username = String::new();

    match username_file.read_to_string(&mut username) {
        Ok(_) => Ok(username),
        Err(e) => Err(e),
    }
}
```
