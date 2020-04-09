#include <iostream>
#include <string>

using namespace std;

class Solution {
private:
    void find_valid(string &S, int &i) {
        int dc = 0;
        while(i >= 0) {
            if(S[i] == '#') {
                ++dc;
            } else {
                if(dc == 0) break;
                else --dc;
            }
            --i;
        }
    }
public:
    bool backspaceCompare(string S, string T) {
        int i = S.length() - 1, j = T.length() - 1;

        bool res = true;
        while( res ) {
            find_valid(S, i);
            find_valid(T, j);
            
            if( i>=0 && j>=0 ) res = res && S[i] == T[j];
            else if ( i<0 && j<0 ) break;
            else res = false;

            --i, --j;
        }
        
        return res;
    }
};

int main() {
    string S, T;
    cin >> S >> T;
    cout << (new Solution)->backspaceCompare(S, T) << endl;
}
