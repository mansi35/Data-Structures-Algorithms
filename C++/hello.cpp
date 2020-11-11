#include <iostream>
using namespace std;

int main(int argc, char* argv[]) {
    string name;
    cout << "Let us get started " << endl;
    cout << "What is your name? ";
    getline(cin, name);
    cout << "Hello " << name << endl;
    cout << "Welcome to c++" << endl;
    return 0;
}
