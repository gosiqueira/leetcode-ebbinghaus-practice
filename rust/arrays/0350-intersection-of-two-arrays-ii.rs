use std::collections::HashMap;
fn intersect(nums1: Vec<i32>, nums2: Vec<i32>) -> Vec<i32> {
    let (nums1, nums2) = if nums1.len() < nums2.len() {
        (nums1, nums2)
    } else {
        (nums2, nums1)
    };

    let mut freq = nums1.iter().fold(HashMap::new(), |mut h, n| {*h.entry(*n).or_insert(0) += 1; h});
    let mut ans = vec![];
    for num in nums2 {
        if let Some(count) = freq.get_mut(&num) {
            if *count > 0 {
                ans.push(num);
                *count -= 1;
            }
        }
    }

    ans
}