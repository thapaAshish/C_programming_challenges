from typing import List 
def counting_sort(arr: list) -> list:
    # initialize count array
    count_array = [0 for _ in range(max(arr)+1)]
    sorted_array = [ 0 for _ in range(len(arr)+1)] 
    for el in arr:
        count_array[el] += 1

    for i in range(1,max(arr)+1):
        count_array[i] += count_array[i-1]
    
    for j in range(len(arr)-1,-1,-1):
        sorted_array[count_array[arr[j]]] = arr[j]
        count_array[arr[j]] -= 1
    # first map the elements
    return sorted_array[1:]

def counting_radix_sort(arr : list, which_digit) -> list:
    # initialize count array
    org_arr = arr[:]
    max_len = len(str(max(arr)))
    arr = [int(str(a).rjust(max_len,'0')[which_digit-1]) for a in arr] 
    count_array = [0 for _ in range(max(arr)+1)]
    sorted_array = [ 0 for _ in range(len(arr)+1)] 
    for el in arr:
        count_array[el] += 1

    for i in range(1,max(arr)+1):
        count_array[i] += count_array[i-1]
    
    for j in range(len(arr)-1,-1,-1):
        sorted_array[count_array[arr[j]]] = org_arr[j]
        count_array[arr[j]] -= 1
    # first map the elements
    return sorted_array[1:]

