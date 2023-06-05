def pow(b:int,e:int) -> float:
    if e < 0:
        return 1/power(b,abs(e))
    else:
        return power(b,e)

def power(b:int,e:int) -> int:
    if e == 1:
        return b
    if e % 2 == 0:
        return power(b,e//2) * power(b,e//2)
    else:
        return b * power(b,(e-1)//2) * power(b,(e-1)//2)


print(pow(3,-3))
