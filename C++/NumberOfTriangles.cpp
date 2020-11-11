#include <iostream>
#include <vector>
using namespace std;

int noOfTrianglesInSubset(vector<int> sides, int left, int current, int right) {
    int count = 0;
    while (left < right) {
        if (sides[left] + sides[right] > sides[current]) {
            count += right - left;
            right--;
        }
        else
            left++;
    }
    return count;
}

int noOfTriangles(int a, int b) {
    vector<int> sides;
    int count = 0;
    for (int i = a; i <= b; i++) {
        sides.push_back(i);
    }
    int n = sides.size();
    for (int i = n - 1; i >= 1; i--) {
        int left = 0, right = i - 1;
        count += noOfTrianglesInSubset(sides, left, i, right);
    }
    return count;
}

int main() {
    int a, b;
    cin >> a;
    cin >> b;
    cout << noOfTriangles(a, b) << endl;
    return 0;
}
