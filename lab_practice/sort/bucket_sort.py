# also uses counting radix sort 
def bucket_sort(arr: list) -> list:
    b_arr = [int(str((a - int(a)) * 100)[0]) for a in arr]
    bucket = [[] for _ in range(10)]
    for (count,i) in enumerate(b_arr):
        bucket[i].append(arr[count])
     
    sorted_array = []
    for values in bucket:
        values.sort()
        for v in values:
            sorted_array.append(v)



    return sorted_array
