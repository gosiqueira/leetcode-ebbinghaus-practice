fn move_zeroes(nums: &mut Vec<i32>) {
    let (mut last_non_zero, mut cur) = (0, 0);
    while cur < nums.len() {
        if nums[cur] != 0 {
            nums.swap(last_non_zero, cur);
            last_non_zero += 1;
        }

        cur += 1;
    }
}