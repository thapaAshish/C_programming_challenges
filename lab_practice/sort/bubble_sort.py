def bubble_sort(arr: list) -> list:
    for i in range(0,len(arr)-1):
        for j in range(0,len(arr)-1-i):
            if arr[j+1] < arr[j]:
                arr[j+1], arr[j] = arr[j],arr[j+1]

    return arr

