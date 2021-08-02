def fractionToDecimal(self, numerator: int, denominator: int) -> str:
    res = '-' if numerator * denominator < 0 else ''
        
    denominator, numerator = abs(denominator), abs(numerator)
    
    if numerator % denominator == 0: 
        return res + str(numerator // denominator)
    
    integ = numerator // denominator
    res += str(integ) + '.'

    numerator = numerator - integ * denominator
    
    rem = numerator % denominator
    hmap = defaultdict(lambda: None)
    frac = ''
    ctr = 0
    while(rem and rem not in hmap):
        hmap[rem] = ctr
        rem *= 10
        frac += str(rem // denominator)
        ctr += 1
        rem %= denominator
    if not rem :
        return res + frac
    else:
        ct = hmap[rem]
        return res + frac[:ct] + '(' + frac[ct:] + ')'