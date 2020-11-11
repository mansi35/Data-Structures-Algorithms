#include <iostream>
#include <stack>
using namespace std;

int duplicates(string equation, stack<char> braces) {
    int flag = 0;
    for (int i = 0; i < equation.size(); ++i) { 
        if (equation[i] != ')'){
            if (!isalpha(equation[i]))
                braces.push(equation[i]);
        }
        if (equation[i] == ')') {
            if (braces.empty())
                break;
            if (braces.top() == '(')
                flag = 1;
            else {
                while(braces.top() != '(') {
                    braces.pop();		
                }
                braces.pop();
            }
        }
    }
    return flag;
}

int main(int argc, char *argv[]) {
	stack<char> braces;
    int t;
    cin >> t;
	string equation;
    while (t--) {
        cin >> equation;
        cout << duplicates(equation, braces) << endl;
    }
	return 0;
}