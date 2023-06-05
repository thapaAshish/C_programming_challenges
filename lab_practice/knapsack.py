p = [45,30,45,10]
w = [3,5,9,5]

max_w = 16
n = 4

permutation = [bin(i)[2:].rjust(4,'0') for i in range(2**n)]

cost = [0 for i in range(2**n)]
weight = [0 for i in range(2**n)]

print(permutation)

def knapsack():
    for i,choice in enumerate(permutation):
        for j,c in enumerate(choice):
            if c == '1':
                cost[i] += w[j] 
                weight[i] += p[j]

knapsack()

filtered_cost = list(filter(lambda x: x <= max_w,cost))
filtered_weight = list(filter(lambda x : x != -1,
                         [(x if cost[i] <= max_w else -1) 
                          for i,x in enumerate(weight) ]))

filtered_perm = list(filter(lambda x : x != -1,
                         [(x if cost[i] <= max_w else -1) 
                          for i,x in enumerate(permutation) ]))

max_is = filtered_weight.index(max(filtered_weight))
print(filtered_weight[max_is])
print(filtered_cost[max_is])
print(filtered_perm[max_is])



