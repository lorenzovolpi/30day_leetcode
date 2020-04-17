#include <iostream>

using namespace std;

class Solution {
public:
    bool checkValidString(string s) {
        int lo = 0, ho = 0;
        for(int i=0; i<s.length(); ++i) {
            if(s[i] == '(') lo++, ho++;
            else if(s[i] == ')') lo--, ho--;
            else if(s[i] == '*') lo--, ho++;
            if(ho < 0) break;
            lo = lo < 0 ? 0 : lo;
        }

        return lo == 0;
    }
};

int main() {
    string s;
    cin >> s;

    cout << (new Solution()) ->checkValidString(s) << endl;
}