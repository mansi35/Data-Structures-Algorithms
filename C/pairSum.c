#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {
    return ( *(int*)a - *(int*)b);
}

int main(int argc, char* argv[]) {
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int sum;
    scanf("%d", &sum);

    qsort(arr, n, sizeof(int), compare);

    int i = 0, j = n - 1;
    while (i < j) {
        if (arr[i] + arr[j] == sum) {
            printf("%d %d\n", arr[i], arr[j]);
            i++;
            j--;
        }

        else if (arr[i] + arr[j] < sum) {
            i++;
        }

        else {
            j--;
        }
    }
    return 0;
}