import string

def isPalindrome(s: str) -> bool:
    response = True
    
    s = s.translate(str.maketrans('', '', string.punctuation)).replace(' ', '').lower()

    lim = len(s) // 2 if len(s) % 2 == 0 else len(s) // 2 + 1
    
    for i in range(lim):
        print(s[i], s[-(i+1)])
        if s[i] != s[-(i+1)]:
            response = False
            break
            
    return response
        