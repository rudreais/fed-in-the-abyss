extern crate noise;

use noise::{Perlin, NoiseFn};
use std::fs::File;
use std::io::Write;
use std::error::Error;
use std::fs::OpenOptions;
use std::path::Path;
use std::env;
use std::process::exit;

fn write_in_file(file_name: String, content: String) {
    let mut file = OpenOptions::new()
        .create(true)
        .append(true)
        .open(Path::new(&file_name.trim()))
        .unwrap();
    if let Err(why) = writeln!(file, "{}", content) {
        eprintln!("Could not write to file : {}", why.description());
    }
}

fn generate_map(file: String, seed: i32, size: i32) {
    let perlin = Perlin::new();

    let _file = File::create(file.as_str());

    let mut line: String = String::new();

    for i in 0..size {
        for j in 0..size {
            let x = i as f64 / 10.0;
            let y = j as f64 / 10.0;
            let z = seed as f64 / 1000.0;
            let value = (perlin.get([x, y, z])).abs();

            line.push(parser(value));
            line.push(' ');
        }
        write_in_file(file.clone(), line);
        line = String::new();
    }
}

fn parser(value: f64) -> char {
    if value < 0.025 {
        '~' // Water
    } else if value >= 0.025 && value <= 0.7 {
        '.' // Dirt
    } else {
        '%' // Grass
    }
}

fn main() {

    let args: Vec<String> = env::args().collect();

    /*
        Args list:
        0 - path
        1 - file path
        2 - seed
        3 - size
    */

    if args.len() != 4 {
        println!("Not enought arguments : \n Usage: <command> <file.txt> <seed (from 1 to 999)> <size>");
        exit(1);
    }

    println!("Created a map : {} with seed : {} and size : {size} * {size}", args[1], args[2], size=args[3]);

    let passed_seed: i32 = args[2].trim().parse().expect("Couldn't parse from String to Int");
    let passed_size: i32 = args[3].trim().parse().expect("Couldn't parse from String to Int");
    let file = &args[1];

    generate_map(file.to_string(), passed_seed, passed_size);
}
