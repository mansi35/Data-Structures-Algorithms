#include <iostream>
#include <string>
#include <set>
using namespace std;

int main(int argc, char* argv[]) {
    string known_letters, latin;
    cin >> known_letters;
    int n;
    cin >> n;
    set<char> letters(begin(known_letters), end(known_letters));
    for (int i = 0; i < n; i++) {
        cin >> latin;
        set<char> latinLetters(begin(latin), end(latin));
        if (latinLetters == letters) {
            cout << "Yes" << endl;
        }
        else {
            cout << "No" << endl;
        }
    }
}