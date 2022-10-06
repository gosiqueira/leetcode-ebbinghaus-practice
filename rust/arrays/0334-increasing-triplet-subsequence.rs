fn increasing_triplet(nums: Vec<i32>) -> bool {
    let (mut i, mut j) = (i32::MAX, i32::MAX);
    for num in nums {
        if num <= i {
            i = num;
        } else if num <= j {
            j = num;
        } else {
            return true;
        }
    }

    false
}