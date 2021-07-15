var countAndSay = function(n) {
    if (n == 1) return "1";
    if (n == 2) return "11"
    
    var say = countAndSay(n-1)
    return count(say);
};

var count = function(str) {
    var response = "";
    var cur = str[0];
    var counter = 1;
    
    for (var i = 1; i < str.length; i++) {
        if (str[i] == cur) counter++;
        else {
            response += counter + cur;
            counter = 1;
            cur = str[i];
        }
    }
    response += counter + cur;
    
    return response;
};