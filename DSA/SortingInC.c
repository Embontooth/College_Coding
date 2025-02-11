#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    int arr[] = {5, 2, 9, 1, 5, 6};
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    qsort(arr, arr_size, sizeof(int), compare);

    for (int i = 0; i < arr_size; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}