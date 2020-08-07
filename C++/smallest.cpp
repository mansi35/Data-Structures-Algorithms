#include <bits/stdc++.h>
using namespace std;

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
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + n);

    cout << smallest(arr, n) << endl;
    return 0;
}