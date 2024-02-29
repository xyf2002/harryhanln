pub mod yes;

pub fn hello(){
    let mut lan : Vec<String> = Vec::new();

    lan.push("Hello".to_string());
    lan.push(String::from("你好"));
    lan.push(String::from("السلام عليكم"));

    lan[0].push_str(", and welcome!");
    for i in &lan {
        println!("{}", i);
    }
}
