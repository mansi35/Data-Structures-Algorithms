#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;
int next(int);
vector<int> seq(int);

int main(int argc, char* argv[]) {

    int START = stoi(argv[1]);

    vector<int> collatz = seq(START);
    
    for (const int c: collatz) {
        cout << setw(6) << c;
    }
    cout << endl;
    return 0;
}

int next(int n) {
    return n % 2 == 0 ? n/2 : 3 * n + 1;
}

/* 
 * takes advantage of insert at a location
 *
vector<int> seq(int n) {
    vector<int> collatz = {4, 2, 1};
    for (; n != 4; n = next(n)) {
        collatz.insert(collatz.end() - 3, n);
    }
    return collatz;
}
*/

/* 
 * takes advantage of insertng an array 
 */
vector<int> seq(int n) {
    vector<int> collatz;
    for (; n != 4; n = next(n)) {
        collatz.push_back(n);
    }
    collatz.insert(collatz.end(), {4, 2, 1});
    return collatz;
}
