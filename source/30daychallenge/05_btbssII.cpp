#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ind = prices.size() - 2, sell = prices.size() - 1, sum = 0;

        while(ind >= 0) {
            while(ind >= 0 && prices[ind] <= prices[ind+1]) ind--;
            sum += prices[sell] - prices[ind+1];
            sell = ind;
            ind--;
        }

        return sum;
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> inp(n);
    for(int i = 0; i<n; ++i) cin >> inp[i];

    int res = (new Solution)->maxProfit(inp);

    cout << res << endl;
}