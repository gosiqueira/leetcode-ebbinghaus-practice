use std::collections::HashMap;

pub fn tuple_same_product(nums: Vec<i32>) -> i32 {
    let mut prods = HashMap::new();
    let mut count = 0;
    for i in 0..nums.len() {
        for j in i+1..nums.len() {
            let prod = nums[i]*nums[j];
            
            count += 8 * prods.get(&prod).unwrap_or(&0);
            *prods.entry(nums[i] * nums[j]).or_insert(0) += 1;
        }
    }

    count
}