#include <iostream>
#include <vector>
using namespace std;

int factorial(int n) {
    return (n == 1 || n == 0) ? 1 : n * factorial(n - 1);
}

bool is_strong(string number) {
    int digitsum = 0;
    for (int i = 0; i < number.length(); i++) {
        digitsum += factorial(number[i] - '0');
    }
    return to_string(digitsum) == number;
}

int main(int argc, char* argv[]) {
    int limit = stoi(argv[1]);
    for (int z = 0; z < 300; z++) {
        for (int j = 0; j < limit; j++) {
            string number = to_string(j);
            vector<string> strong;
            if (is_strong(number)) {
                strong.push_back(number);
            }
        }
    }
    return 0;
}