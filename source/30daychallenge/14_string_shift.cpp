#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string stringShift(string s, vector<vector<int>>& shift) {
        vector<int> r = shift[0];
        for(int i=1; i<shift.size(); ++i) {
            if(shift[i][0] == r[0]) r[1] += shift[i][1];
            else r[1] -= shift[i][1];
        }
        if(r[1] < 0) {
            r[0] = (r[0] + 1) % 2;
            r[1] = -r[1];
        }

        string out(s);
        int ind;
        r[1] %= s.length();
        if(r[0] == 0) ind = r[1];
        else ind = (s.length() - r[1]) % s.length();

        int j=0;
        for(int i=ind; i<s.length(); ++i, ++j) out[j] = s[i];
        for(int i=0; i<ind; ++i, ++j) out[j] = s[i];

        return out;
    }
};

int main() {
    string s;
    cin >> s;
    int n;
    cin >> n;
    vector<vector<int>> shift(n, vector<int>(2, 0));

    for(int i=0; i<n; ++i) cin >> shift[i][0] >> shift[i][1];

    cout << (new Solution())->stringShift(s, shift) << endl;
}
