m = "Architect"
n = "technology"

memo = {} 

def lcs(i,j):
    if i == len(m) or j == len(n):
        return 0

    if m[i] == n[j]:
        if (i,j) in memo:
            return 1 + memo[(i,j)]
        memo[(i,j)] = 1 + lcs(i+1,j+1) 
        return memo[(i,j)]

    else:
        return max(lcs(i+1,j),lcs(i,j+1))

print(lcs(0,0))

print(memo)

