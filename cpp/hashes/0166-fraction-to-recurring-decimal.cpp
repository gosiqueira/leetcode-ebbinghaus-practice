#include <map>

using namespace std;


string fractionToDecimal(int numerator, int denominator) {
    bool sign = (numerator <= 0 && denominator < 0) || (numerator >= 0 && denominator > 0);
    
    long long num = numerator; 
    long long den = denominator;
    
    num = abs(num); 
    den = abs(den); 
    
    string real = to_string(num / den);
    
    if (!sign) 
        real = '-' + real;
    
    string decimal = ".";
    
    map<int, int> mp;
    mp.clear();
    
    long long rem = num % den;
    
    if (rem == 0) 
        return real;
    
    while (rem != 0 && (mp.find(rem) == mp.end())) {
        mp[rem] = decimal.length();
        rem = rem * 10;
        decimal += (char)('0' + rem / den);
        rem = rem % den;
    }
    
    if (rem == 0)
        return real + decimal;
    
    return real + decimal.substr(0, mp[rem]) + '(' + decimal.substr(mp[rem]) + ')';
}