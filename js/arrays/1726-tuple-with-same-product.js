var tupleSameProduct = function(nums) {
    prods = {}
    for (var i = 0; i < nums.length; i++) {
        for (var j = i + 1; j < nums.length; j++) {
            key = nums[i] * nums[j];
            if (prods[key] == undefined) prods[key] = 1;
            else prods[key] += 1;
        }
    }
    
    var total = 0;
    for (const [key, value] of Object.entries(prods)) {
        if (value > 1) total += (value * (value - 1)) / 2;
    }
    
    return total * 8;
};