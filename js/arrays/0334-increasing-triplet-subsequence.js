var increasingTriplet = function(nums) {
    var m = Infinity;
    var n = Infinity;
    for (const num of nums) {
        if (num <= m) m = num;
        else if (num <= n) n = num;
        else return true;
    }
    
    return false;
};