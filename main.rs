use std::collections::LinkedList;
use std::env;

fn main() {
    //let mut l: Vec<u32> = Vec::new();
    let mut l: LinkedList<u32> = LinkedList::new();
    let args: Vec<String> = env::args().collect();
    l.push_back(2);
    // println!("{}", 2);
    for i in 3..(if args.len() == 2 {
        args[1].parse::<u32>().unwrap()
    } else {
        u32::MAX
    }) {
        let mut is_prime = true;
        for j in l.iter() {
            if j * j <= i {
                if i % j == 0 {
                    is_prime = false;
                    break;
                }
            } else {
                break;
            }
        }
        if is_prime {
            l.push_back(i);
            // println!("{}", i);
        }
    }
}
