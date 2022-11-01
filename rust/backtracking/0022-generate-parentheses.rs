impl Solution {
    pub fn generate_parenthesis(n: i32) -> Vec<String> {
        fn gen(s: String, open: i32, closed: i32) -> Vec<String> {
            let mut answers = vec![];
            if open == 0 && closed == 0 {
                return vec![s];
            }

            if open > 0 {
                answers.append(&mut gen(s.clone()+"(", open-1, closed+1));
            }

            if closed > 0 {
                answers.append(&mut gen(s.clone()+")", open, closed-1));
            }

            answers
        }

        gen("".to_string(), n, 0)
    }
}