#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        vector<int> a(n*2+1, -2);
        int *mp = &(a[n]);
        int max = 0;

        mp[0] = -1;
        int c = 0;
        for(int i=0; i<nums.size(); ++i) {
            c += nums[i] ? 1 : -1;
            if(mp[c] < -1) mp[c] = i;
            else if(i - mp[c] > max) max = i - mp[c];
        }

        return max;
        
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> inp(n);
    for(int i=0; i<n; ++i) cin >> inp[i];

    cout << (new Solution())->findMaxLength(inp) << endl;
}
