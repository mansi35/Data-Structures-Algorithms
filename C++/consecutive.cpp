#include <iostream>
using namespace std;

int main(int argc, char* argv[]) {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int count = 0, maxcount = 0, end = 0, i;
    for (i = 0; i < n - 1; i++) {
        if (arr[i+1] - arr[i] == 1) {
            count += 1;
        }

        else {
            if (count > maxcount) {
                end = i + 1;
            }
            maxcount = max(maxcount, count);
            count = 0;
        }
    }

    if (max(maxcount, count) == 0) {
        maxcount = 0;
    }
    
    else {
        if (count > maxcount) {
                end = i + 1;
        }
        maxcount = max(maxcount, count) + 1;
    }

    for (int i = end - maxcount; i < end; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}