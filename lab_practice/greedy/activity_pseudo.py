s = [1,3,0,5,3,5,6,8,8,2,12]
f = [4,5,6,7,9,9,10,11,12,14,16]
n = len(s) 

def activity_recursive(s,f,k,n):
    m = k + 1
    while m < n and s[m] < f[k]:
        m += 1

    if m <= n:
        print(f"{k} activity is selected")
        activity_recursive(s,f,m,n)

activity_recursive(s,f,0,n)



