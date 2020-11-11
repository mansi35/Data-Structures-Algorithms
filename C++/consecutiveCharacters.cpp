class Solution {
public:
    int maxPower(string s) {
        int n = s.length();
        if (n == 0)
            return 0;
        int length = 0, maxlength = 0;
        for (int i = 0; i < n - 1; i++) {
            if (s[i] == s[i+1]) {
                cout << s[i] << " ";
                length++;
            }
            
            if (s[i] != s[i+1])
                length = 0;
            
            else if (length > maxlength)
                maxlength = length;
        }
        return maxlength + 1;
    }
};
