pub mod back_of_house {
    pub fn fix_incorrect_order() {
        cook_order();
        super::front_of_house::serving::deliver_order();
    }
    fn cook_order() {}
}
