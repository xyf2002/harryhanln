#[derive(Debug)]
struct Rect {
    width: u32,
    height: u32,
}


fn main() {
    let rect = Rect {
        width: 10,
        height: 20,
    };
    
    println!("The area of the rectangle is {}", rect.area());
    dbg!(&rect);
    println!("{:?}", rect);

    let square = Rect::square(3);
    println!("The area of the square is {}", square.area());
}

impl Rect {
    fn area(&self) -> u32 {  // this is a method
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
