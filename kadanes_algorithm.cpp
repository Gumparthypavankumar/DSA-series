#include <bits/stdc++.h>
using namespace std;

int maxSubarraySum(vector<int> &nums) {
    int maxSum = INT_MIN, sum = 0, n = nums.size();
    for (int i = 0; i < n; i++) {
        sum = max(nums[i], sum + nums[i]);
        maxSum = max(maxSum, sum);
    }
    return maxSum;
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    cout << maxSubarraySum(nums) << "\n";
    return 0;
}