#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int* decode(string sequence, int* digits) {
    for (int j = 0; j <= sequence.length(); ++j) {
        for (int i = 0; i <= sequence.length() - j; ++i) {
            if (sequence[i] == 'D') {
                if (digits[i] < digits[i+1]) {
                    swap(digits[i], digits[i+1]);
                }
            }
            else if (sequence[i] == 'I') {
                if (digits[i] > digits[i+1]) {
                    swap(digits[i], digits[i+1]);
                }
            }
        }
    }
    return digits;
}

int main(int argc, char* argv[]) {
    string sequence;
    cin >> sequence;
    int digits[1000];
    for (int i = 0; i <= sequence.length(); ++i) {
        digits[i] = i + 1;
    }
    int* ans = decode(sequence, digits);
    for (int i = 0; i <= sequence.length(); ++i ) {
        cout << ans[i];
    }
    cout << endl;
    return 0;
}