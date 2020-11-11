#include <iostream>
#include <vector>
#include <string>

using namespace std;

pair<bool, bool> divisor_combo(int n) {
    return make_pair(n % 5 == 0, n % 3 == 0);
}

vector<string> fizzbuzz() {
    vector<string> series;
    for (int i = 1; i< 101; i++){
        pair<bool, bool> divisors = divisor_combo(i);
        series.push_back(divisors.first and divisors.second ? "FIZZBUZZ" : (divisors.first ? "FIZZ" : (divisors.second ? "BUZZ" : to_string(i))));
    }
    return series;
}

int main(int argc, char* argv[]) {
    vector<string> series = fizzbuzz();
    for (string n: series) {
        cout << n << " ";
    }
    cout << endl;
}