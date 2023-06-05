from counting_sort import counting_radix_sort
def radix_sort(arr:list)->list:
    for i in range(len(str(max(arr))),0,-1):
        arr = counting_radix_sort(arr, i)

    return arr 



