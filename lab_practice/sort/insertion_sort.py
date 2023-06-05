def insertion_sort(arr) -> list:
    for i in range(1,len(arr)):
        for j in range(i-1,0,-1):
            if arr[j] < arr[j-1]:
                (arr[j-1],arr[j]) = (arr[j],arr[j-1])
            else:
                break 

    return arr
