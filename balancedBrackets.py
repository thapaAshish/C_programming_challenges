items = input()
Brackets=[]
for x in range(0,int(items)):
        Brackets.append(input())
Buffer=[]
changeFace = {'}':'{',']':'[',')':'('}
for x in Brackets:
    for p in list(x):
        if len(Buffer):
            if p == "]" or p == "}" or p == ")":
                if Buffer[-1] == changeFace[p]:
                    Buffer.pop()
                else:
                    Buffer.append(p)
            else:
                Buffer.append(p)
        else:
            Buffer.append(p)
    
    if not len(Buffer):
        print("YES")
    else:
        print("NO")
    Buffer=[]