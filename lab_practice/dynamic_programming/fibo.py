memo = {} 
def fibonacci(n):
    if n == 0: 
        return 1
    if n == 1:
        return 1
    
    if n not in memo:
        memo[n] = fibonacci(n-1) + fibonacci(n-2)

    return memo[n]


print(fibonacci(48))
print(memo)

