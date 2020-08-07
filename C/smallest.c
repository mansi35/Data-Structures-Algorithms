#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {
    return ( *(int*)a - *(int*)b);
}

int smallest(int* arr, int n) {
    int smallest = 1;
    for (int i = 0; i < n; i++) {
        if (arr[i] <= smallest) {
            smallest += arr[i];
        }

        else {
            break;
        }
    }
    return smallest;
}

int main(int argc, char* argv[]) {
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    qsort(arr, n, sizeof(int), compare);

    printf("%d\n", smallest(arr, n));
    return 0;
}