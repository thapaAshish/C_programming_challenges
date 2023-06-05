def merge_sort(arr) -> list:
    return sort(arr,0,len(arr))


def sort(arr: list,start: int,stop: int) -> list: 
    if start < stop:
        mid = (start + stop) // 2
        sort(arr,start,mid)
        sort(arr,mid+1, stop)
        merge(arr, start, mid, stop)
    return arr

def merge(arr:list, start:int, mid:int, stop:int) -> list:
    left = arr[start:mid]
    right = arr[mid:stop]
    left_pointer = 0;
    right_pointer = 0;

    copy_remaining_stuff_from_left = False;
    position = 0;

    for i in range(start,stop):
        if left_pointer >= len(left): 
            position = i
            copy_remaining_stuff_from_left = False 
            break
        elif right_pointer >= len(right):
            position = i
            copy_remaining_stuff_from_left = True 
            break


        if left[left_pointer] < right[right_pointer]:
            arr[i] = left[left_pointer]
            left_pointer += 1
        else:
            arr[i] = right[right_pointer]
            right_pointer += 1
    
    if (copy_remaining_stuff_from_left):
        for i in range(left_pointer,len(left)):
            arr[position] = left[i];
            position += 1
    elif (copy_remaining_stuff_from_left == False):
        for i in range(right_pointer,len(right)):
            arr[position] = right[i];
            position += 1

    return arr
