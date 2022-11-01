impl Solution {
    pub fn subsets(mut nums: Vec<i32>) -> Vec<Vec<i32>> {
        if nums.is_empty(){
            return vec![vec![]];
        }

        let last = nums.pop().unwrap();
        let remain_subsets = Self::subsets(nums);
        let mut answers = remain_subsets.clone();
        for mut set in remain_subsets {
            set.push(last);
            answers.push(set);
        }

        answers
    }
}