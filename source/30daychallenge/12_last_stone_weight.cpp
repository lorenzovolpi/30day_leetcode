#include <iostream>
#include <vector>

using namespace std;


class Solution {
private:
    int leftc(int i) {
        return 2*i + 1;
    }

    int rightc(int i) {
        return 2*i+2;
    }
    
    int par(int i) {
        return (i-1)/2;
    }

    void swap(vector<int>& v, int i, int m) {
        int t = v[i];
        v[i] = v[m];
        v[m] = t;
    }

    void heapify(vector<int>& v, int n, int ind) {
        int maxi = ind, l = leftc(ind), r = rightc(ind);
        
        if(l < n && v[l] > v[maxi]) maxi = l;
        if(r < n && v[r] > v[maxi]) maxi = r;

        if(ind != maxi) {
            swap(v, ind, maxi);
            heapify(v, n, maxi);
        }
    }

    void mkheap(vector<int>& v, int n) {
        for(int i = n - 1; i>=0; --i) heapify(v, n, i);
    }

    int rmax(vector<int>& v, int& n) {
        if(n == 0) return 0;
        
        int r = v[0];
        swap(v, 0, n-1);
        --n;

        heapify(v, n, 0);

        return r;
    }

    void insert(vector<int>& v, int& n, int e) {
        ++n;
        if(v.size() < n) v.push_back(e);
        else v[n-1] = e;

        int i = n-1, p;
        while(i>0 && v[i] > v[(p=par(i))]) {
            swap(v, i, p);
            i = p;
        }
    }

public:
    int lastStoneWeight(vector<int>& stones) {
        int n = stones.size();
        mkheap(stones, n);

        while(n >= 2) {
            int a = rmax(stones, n), b = rmax(stones, n);
            int r = a - b;
            if(r != 0) insert(stones, n, r);
        }

        return rmax(stones, n);
    }
};


int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i=0; i<n; ++i) cin >> v[i];

    cout << (new Solution())->lastStoneWeight(v) << endl;
}

