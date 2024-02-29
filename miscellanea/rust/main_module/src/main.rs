mod hello;
use hello::yes;
use std::fs::File;
use std::io::ErrorKind;
use std::io::{self, Read};

fn main() {
    panic_fun();
    yes::yes();
    hello::hello();
}

fn panic_fun() {
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
