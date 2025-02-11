#include <stdio.h>

void sliding_window(int arr[], int n, int k) {
    if (n < k) {
        return;
    }

    int window_sum = 0;
    for (int i = 0; i < k; i++) {
        window_sum += arr[i];
    }

    printf("%d ", window_sum);

    for (int i = 0; i < n - k; i++) {
        window_sum = window_sum - arr[i] + arr[i + k];
        printf("%d ", window_sum);
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int k = 3;
    int n = sizeof(arr) / sizeof(arr[0]);

    sliding_window(arr, n, k);

    return 0;
}