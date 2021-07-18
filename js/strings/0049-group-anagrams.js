var groupAnagrams = function(strs) {
    var anagrams = {};
    
    for (const str of strs) {
        var key = str.split('').sort().join('');
        if (anagrams[key] === undefined) anagrams[key] = [];
        anagrams[key].push(str);
    }
    
    return Object.values(anagrams);
};