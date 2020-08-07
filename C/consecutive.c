#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int count = 0, maxcount = 0, end = 0;
    for (int i = 0; i < n - 1; i++) {
        if (arr[i+1] - arr[i] == 1) {
            count += 1;
        }

        if (count > maxcount) {
                end = i + 1;
                maxcount = count;
            }
        else {
            count = 0;
        }
    }

    for (int i = end - maxcount; i <= end; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}