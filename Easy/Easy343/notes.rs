fn main() {
    let mut buffer = String::new();

    println!("Enter a note to get the scale of: ");
    std::io::stdin().read_line(&mut buffer).expect("Error reading input");
    let buffer = buffer.trim();
    println!("You input: {}", buffer);

    let mut note : i32 = -1;
    let mut result : [std::string::String; 7] = ["".to_string(), "".to_string(), "".to_string(), "".to_string(), "".to_string(), "".to_string(), "".to_string()];
    let steps : [i32; 7] = [0, 2, 4, 5, 7, 9, 11];

    match buffer.as_ref() {
        "A"     =>  note = 0,
        "A#"    =>  note = 1,
        "B"     =>  note = 2,
        "C"     =>  note = 3,
        "C#"    =>  note = 4,
        "D"     =>  note = 5,
        "D#"    =>  note = 6,
        "E"     =>  note = 7,
        "F"     =>  note = 8,
        "F#"    =>  note = 9,
        "G"     =>  note = 10,
        "G#"    =>  note = 11,
        _       =>  panic!("Invalid input...")
    }

    for i in 0..7 {
        let mut this_note = note + steps[i];
        if this_note > 11 {
            this_note -= 12;
        }
        match this_note {
            0   =>  result[i] = "A".to_string(),
            1   =>  result[i] = "A#".to_string(),
            2   =>  result[i] = "B".to_string(),
            3   =>  result[i] = "C".to_string(),
            4   =>  result[i] = "C#".to_string(),
            5   =>  result[i] = "D".to_string(),
            6   =>  result[i] = "D#".to_string(),
            7   =>  result[i] = "E".to_string(),
            8   =>  result[i] = "F".to_string(),
            9   =>  result[i] = "F#".to_string(),
            10  =>  result[i] = "G".to_string(),
            11  =>  result[i] = "G#".to_string(),
            _   =>  panic!("Invalid note step...")
        }
    }

    println!("The scale is: {} {} {} {} {} {} {}", result[0], result[1], result[2], result[3], result[4], result[5], result[6]);

}