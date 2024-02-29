fn main (){
    let mut v: Vec<i32> = Vec::new();
    v.push(1);
    v.push(2);
    v.push(2);

    let third = v[2];
    println!("{}", &v[2]);
}
