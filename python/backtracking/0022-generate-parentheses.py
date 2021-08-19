from typing import List

def generate(p, left, right):
        if right >= left >= 0:
            if not right:
                yield p
                
            yield from generate(p + '(', left-1, right)
            yield from generate(p + ')', left, right-1)


def generateParenthesis(self, n: int) -> List[str]:
    return list(generate('', n, n))