def quick_sort(arr: list) -> list:
    return sort(arr,0,len(arr))

def sort(arr:list,start,stop):
    if start < stop:
        loc =  partition(arr,start,stop)
        sort(arr,0,loc-1)
        sort(arr,loc+1,stop)
    return arr


def partition(arr:list, start, stop):
    pivot = arr[stop-1]
    pivot_loc = start
    for i in range(start,stop):
        if arr[i] < pivot:
            arr[i],arr[pivot_loc] = arr[pivot_loc],arr[i]
            pivot_loc += 1

    arr[stop-1],arr[pivot_loc]= arr[pivot_loc],arr[stop-1]
    return pivot_loc
