use std::fs;

fn main(){
    let flag = fs::read_to_string("/flag").expect("error in reading /flag");
    println!("{flag}");
}
