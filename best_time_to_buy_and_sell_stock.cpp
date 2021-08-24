#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int minTillNow = INT_MAX, maxProfit = 0;
        for (int i = 0; i < prices.size(); i++) {
            minTillNow = min(minTillNow, prices[i]);
            maxProfit = max(maxProfit, prices[i] - minTillNow);
        }
        return maxProfit;
    }
};

int main() {
    Solution sol;
    int n;
    cin >> n;
    vector<int> prices(n);
    for (int i = 0; i < n; i++) {
        cin >> prices[i];
    }
    cout << sol.maxProfit(prices) << "\n";
}