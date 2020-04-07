#include <iostream>
#include <vector>

using namespace std;

#define SIZE 1002
int check[SIZE] = {0};

class Solution {
public:
    int countElements(vector<int>& arr) {
        fill(check, check + SIZE, 0);

        for(int i = 0; i<arr.size(); ++i) check[arr[i]]++;
        int cnt = 0;
        for(int i = 0; i<arr.size(); ++i) if(check[arr[i]+1] > 0) cnt++;

        return cnt;
    }
    
};

int main() {
    int n;
    cin >> n;
    vector<int> inp(n);
    for(int i = 0; i<n; ++i) cin >> inp[i];

    cout << (new Solution())->countElements(inp) << endl;
}