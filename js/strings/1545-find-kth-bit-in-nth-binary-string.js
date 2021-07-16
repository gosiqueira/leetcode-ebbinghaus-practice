var findKthBit = function(n, k) {
    const S = (n) => {
        if (n === 1) {
            return '0';
        }
        const str = S(n - 1);
        return str + '1' + str.split('').map(char => char === '0' ? '1' : '0').reverse().join('');
    }
    
    return S(n)[k - 1];
};