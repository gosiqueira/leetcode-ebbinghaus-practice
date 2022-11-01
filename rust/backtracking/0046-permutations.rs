impl Solution {
    pub fn permute(nums: Vec<i32>) -> Vec<Vec<i32>> {
        fn per(answers: &mut Vec<Vec<i32>>, nums: Vec<i32>, begin: usize) {
            if begin >= nums.len() {
                answers.push(nums);
                return
            }

            for i in begin..nums.len() {
                let mut nums = nums.clone();
                nums.swap(begin, i);
                per(answers, nums, begin + 1);
            }
        }

        let mut answers: Vec<Vec<i32>> = vec![];
        per(&mut answers, nums, 0);
        answers
    }
}