#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0, max = 0, max_el = INT_MIN;
        for(int i=0; i<nums.size(); ++i) {
            sum += nums[i];
            if(sum < 0) sum = 0;
            if(sum > max) max = sum;
            if(nums[i] > max_el) max_el = nums[i];
        }

        return max > 0 ? max : max_el;
    }
};

int main() {
    int n = 0;
    cin >> n;
    vector<int> inp(n, 0);
    for(int i = 0; i<n; ++i) cin >> inp[i];

    Solution* sol = new Solution();

    cout << sol->maxSubArray(inp) << endl;

}