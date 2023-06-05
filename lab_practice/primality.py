def probably_prime(n):
    for i in range(2,n-1):
        if (i ** (n-1)) % n != 1:
            return False

    return True



def probably_prime_recursive(n,index):
    if index == 1: 
        return True

    if (index ** (n-1)) % n != 1:
        return False

    return probably_prime_recursive(n,index-1)



for i in range(3,100):
    print(f'{i} = {probably_prime_recursive(i,i-1)}')

