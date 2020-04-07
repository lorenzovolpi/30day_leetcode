#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0x0;

        for(int i = 0; i<nums.size(); ++i) {
            res ^= nums[i];
        }

        return res;
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> input(n, 0);
    for(int i = 0; i<n; ++i) {
        cin >> input[i];
    }
    Solution* sol = new Solution();

    cout << sol->singleNumber(input) << endl;
}