var longestPalindrome = function(s) {
    response = s[0]
    
    for (var i = 0; i < s.length; i++) {
        var l = i - 1;
        var r = i;
        
        while (l >= 0 && r < s.length && s[l] == s[r]) {
            l--;
            r++;
        }
        
        substr = s.substring(l + 1, r);
        if (substr.length > response.length) response = substr;

        l = i - 1;
        r = i + 1;
        
        while (l >= 0 && r < s.length && s[l] == s[r]) {
            l--;
            r++;
        }
        
        substr = s.substring(l + 1, r);
        if (substr.length > response.length) response = substr;
    }
    
    return response;
};