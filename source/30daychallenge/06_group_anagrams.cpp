#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for(int i = 0; i<strs.size(); i++) {
            string s = strs[i];
            sort(strs[i].begin(), strs[i].end());
            mp[strs[i]].push_back(s);
        }
        
        vector<vector<string>> res;
        for(auto& vec : mp) {
            res.push_back(vec.second);
        }

        return res;
    }
};

int main(){
    int n;
    cin >> n;
    vector<string> inp(n);
    for(int i = 0; i<n; ++i) cin >> inp[i];

    vector<vector<string>> res = (new Solution)->groupAnagrams(inp);

    for(int i = 0; i<res.size(); ++i) {
        for(int j = 0; j<res[i].size(); ++j) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
}