#include <string>

using namespace std;


string longestPalindrome(string s) {
    int start = 0;
    int len = 0;
    for (int i = 0; i < s.length(); i++) {
        int left = i - 1;
        int right = i;
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            left--;
            right++;
        }
        if (right - (left + 1)> len) {
            start = left + 1;
            len = right - (left + 1);
        }
        
        left = i - 1;
        right = i + 1;
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            left--;
            right++;
        }
        if (right - (left + 1) > len) {
            start = left + 1;
            len = right - (left + 1);
        }
    }
    return s.substr(start, len);
}
