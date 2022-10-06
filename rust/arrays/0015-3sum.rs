fn three_sum(nums: &mut [i32]) -> Vec<Vec<i32>> {
    let mut ans = vec![];

    nums.sort();
    for (i, &num) in nums.iter().enumerate() {
        if i > 0 && num == nums[i-1] { continue };

        let target = -num;
        if target < 0 { break; }

        let (mut left, mut right) = (i+1, nums.len()-1);
        while left < right {
            let sum = nums[left] + nums[right];
            if sum > target {
                right -= 1;
            } else if sum < target {
                left += 1;
            } else {
                ans.push(vec![num, nums[left], nums[right]]);
                left += 1;

                while nums[left] == nums[left-1] && left < right {
                    left += 1;
                }
            }
        }
    }

    ans
}