#include <iostream>
using namespace std;

int main(int argc, char* argv[]) {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < n / 2; i++) {
        arr[i] = arr[i] + arr[n - i - 1];
        arr[n - i - 1] = arr[i] - arr [n - i - 1];
        arr[i] = arr[i] - arr [n - i - 1];
    }

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
