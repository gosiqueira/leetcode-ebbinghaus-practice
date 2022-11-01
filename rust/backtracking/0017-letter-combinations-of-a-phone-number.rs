use std::collections::HashMap;

impl Solution {
    pub fn letter_combinations(digits: String) -> Vec<String> {
                if digits.is_empty() {return vec![]};

        let phone_mapping: HashMap<char, &str> = [
            ('2', "abc"),
            ('3', "def"),
            ('4', "ghi"),
            ('5', "jkl"),
            ('6', "mno"),
            ('7', "pqrs"),
            ('8', "tuv"),
            ('9', "wxyz")
        ].into();

        let mut results: Vec<String> = vec![];
        for digit in digits.chars() {
            let letters = phone_mapping[&digit];
            let mut cur_results = vec![];

            for letter in letters.chars() {
                if results.len() == 0 {
                    cur_results.push(letter.to_string());
                    continue;
                }

                for res in &results {
                    cur_results.push(res.to_owned() + &letter.to_string());
                }
            }

            results = cur_results;
        }

        results
    }
}