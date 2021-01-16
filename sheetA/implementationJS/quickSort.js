//quicksort implementation

let arr = [23, 11, 3, 2, 244, 133, 3433, 1, 2, 3, 100, 99];

function quickSort(start, stop) {
    if (start === stop) return;
    if (start > stop) return;

    let pivot = start;

    for (let i = start + 1; i <= stop; i++) {
        if (arr[i] < arr[pivot]) {
            //swap arrays XOR style
            arr[i] = arr[pivot] ^ arr[i];
            arr[pivot] = arr[i] ^ arr[pivot];
            arr[i] = arr[i] ^ arr[pivot];
            pivot = i;
        }
    }

    if (pivot < stop && start != pivot) quickSort(pivot, stop);
    if (start < pivot && start != pivot) quickSort(start, pivot);
    return 0;
}

quickSort(0, arr.length);
document.write(arr);