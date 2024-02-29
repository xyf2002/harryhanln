mod back_of_house;
mod front_of_house;

static MAX_ORDER: u32 = 100;
use crate::front_of_house::hosting;


pub fn go_to_resturant() {
    // Absolute path
    // crate::front_of_house::hosting::add_to_waitlist();
    
    // Relative path
    hosting::add_to_waitlist();
    hosting::place_seat();
}


pub fn read_menu() {
    println!("Reading menu");
}
