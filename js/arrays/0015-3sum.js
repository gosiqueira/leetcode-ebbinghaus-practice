var threeSum = function(nums) {
    nums.sort(function(a, b) {
        return a - b;
    });
    
    response = [];
    
    for (var i = 0; i < nums.length; i++) {
        if (i > 0 && nums[i] == nums[i - 1]) continue;
        
        var l = i + 1;
        var r = nums.length - 1;
          
        while (l < r) {
            var sum = nums[i] + nums[l] + nums[r];
            
            if (sum > 0) r--;
            else if (sum < 0) l++;
            else {
                response.push([nums[i], nums[l], nums[r]]);
                l++;
                while (nums[l] == nums[l - 1] && l < r) l++;
            }
        }
    }
    
    return response;
};