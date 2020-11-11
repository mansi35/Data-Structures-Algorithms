#include <iostream>
#include <vector>

using namespace std;

int next_number(int n) {
    if (n & 1){
        return 3 * n + 1;
    }
    return n / 2;
}

vector<int> collatz(int number) {
    vector<int> sequence;
    sequence.push_back(number);
    while (number != 1) {
        number = next_number(number);
        sequence.push_back(number);
    }
    return sequence;
}

int main(int argc, char* argv[]) {
    int number;
    vector<int> sequence;
    cout << "Enter a number: ";
    cin >> number;
    sequence = collatz(number);
    for (auto j = sequence.begin(); j != sequence.end(); j++) {
        cout << *j << " ";
    }
    cout << endl;
    return 0;
}
