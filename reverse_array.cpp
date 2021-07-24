#include <bits/stdc++.h>
using namespace std;

/*
    Print Reverse of a Given Array
*/

void reverse_array(vector<int> &nums) {
    if (nums.size() == 0) {
        return;
    }
    int start = 0, end = nums.size() - 1;
    while (start < end) {
        swap(nums[start++], nums[end--]);
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    reverse_array(nums);
    for (int i = 0; i < n; i++) {
        cout << nums[i] << " ";
    }
    return 0;
}