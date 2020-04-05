#include <iostream>
#include <math.h>
#include <set>

class Solution {
private:
    int digit_sqr_sum(int n) {
        int sum = 0;
        while(n > 0) {
            sum += std::pow(n % 10, 2);
            n /= 10;
        }
        return sum;
    }

public:
    bool isHappy(int n) {
        if(n == 1) return true;

        std::set<int> seen;
        seen.insert(n);
        while(true) {
            n = digit_sqr_sum(n);
            if (n == 1) return true;
            else if(seen.find(n) != seen.end()) return false;
            else seen.insert(n);
        }
    }
};

int main() {
    int n;
    std::cin >> n;

    Solution* sol = new Solution();
    std::cout << (sol->isHappy(n) ? "true" : "false") << std::endl;
}