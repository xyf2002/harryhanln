pub fn yes() {
    println!("START OF YES HASHMAP");
    use std::collections::HashMap;

    let mut scores = HashMap::new();

    scores.insert(String::from("Blue"), 10);
    scores.insert(String::from("Yellow"), 50);
    println!("{}", scores.get(&String::from("Blue")).copied().unwrap_or(0));

    for (key, value) in &scores {
        println!("{key}: {value}");
    }

    println!("{:?}", scores);
    println!("END OF YES HASHsAP SESSION");
}
