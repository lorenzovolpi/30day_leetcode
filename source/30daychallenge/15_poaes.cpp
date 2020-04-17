#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> out(nums.size(), 1);

        int prod = 1;
        for(int i=0; i<nums.size()-1; ++i) {
            prod *= nums[i];
            out[i+1] *= prod;
        }   
        prod = 1;     
        for(int i=nums.size()-1; i>0; --i) {
            prod *= nums[i];
            out[i-1] *= prod;
        }

        return out;
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> inp(n);
    for(int i=0; i<n; ++i) cin >> inp[i];

    vector<int> out = (new Solution())->productExceptSelf(inp);
    for(int i=0; i<n; ++i) cout << out[i] << " ";
    cout << endl;
}
