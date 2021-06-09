def countAndSay(n: int) -> str:
    if n == 1:
        return '1'

    say = countAndSay(n-1)

    if len(say) > 1:
        response = []
        
        cur = say[0]
        count = 1
        i = 1

        while i < len(say):
            if say[i] == cur:
                count += 1
            else:
                response.append(str(count))
                response.append(cur)
                cur = say[i]
                count = 1
            i += 1

        response.append(str(count))
        response.append(cur)

        response = ''.join(response)

    else:
        response = ''.join(['1', *say])

    return response
