def isAnagram(s: str, t: str) -> bool:
    response = True
    if len(s) != len(t):
        response = False
    else:
        s_dict, t_dict = {}, {}
        for i in range(len(s)):
            s_dict[s[i]] = s_dict.get(s[i], 0) + 1
            t_dict[t[i]] = t_dict.get(t[i], 0) + 1

        for key in s_dict.keys():
            if key not in t_dict or s_dict[key] != t_dict[key]:
                response = False
        
    return response
