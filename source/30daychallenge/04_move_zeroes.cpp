#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    void swap(vector<int>& nums, int i, int j) {
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }

public:
    void moveZeroes(vector<int>& nums) {
        int fz = 0, fnz;
        
        while(fz < nums.size() && nums[fz] != 0) fz++;
        fnz = fz;
        while(fnz < nums.size() && nums[fnz] == 0) fnz++;
        
        while(fnz < nums.size()) {
            swap(nums, fz, fnz);
            
            while(fz < nums.size() && nums[fz] != 0) fz++;
            while(fnz < nums.size() && nums[fnz] == 0) fnz++;
        }

    }
};

int main() {
    int n;
    cin >> n;
    vector<int> inp(n, 0);
    for(int i = 0; i<n; ++i) cin >> inp[i];

    Solution* sol = new Solution();
    sol->moveZeroes(inp);

    for(int i = 0; i<n; ++i) cout << inp[i] << " ";
    cout << endl;

}