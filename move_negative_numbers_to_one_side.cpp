#include <bits/stdc++.h>
using namespace std;

/*
    NOTE: The order is not important
    Approach: Two Pointer Approach
    Problem Link: https://www.geeksforgeeks.org/move-negative-numbers-beginning-positive-end-constant-extra-space/
    EX: 
    step 1 : -12 11 -13 -5 6 -7 5 -3 -6 left = 0, right = 8
    step 2 : -12 -6 -13 -5 6 -7 5 -3 11 left = 1, right = 8 swap
    step 3 : -12 -6 -13 -5 6 -7 5 -3 11 left = 2, right = 7
    step 4 : -12 -6 -13 -5 6 -7 5 -3 11 left = 3, right = 7
    step 5 : -12 -6 -13 -5 -3 -7 5 6 11 left = 4, right = 6
    step 6 : -12 -6 -13 -5 -3 -7 5 6 11 left = 5, right = 6
    step 6 : -12 -6 -13 -5 -3 -7 5 6 11 left = 5, right = 5
*/
void rearrangeNegativeNumbersInArray(vector<int> &nums) {
    if (nums.size() == 0)
        return;
    int left = 0, right = nums.size() - 1;

    while (left <= right) {
        if (nums[left] < 0) {
            left++;
        } else if (nums[left] > 0 && nums[right] > 0) {
            right--;
        } else if (nums[left] > 0 && nums[right] < 0) {
            swap(nums[left++], nums[right--]);
        } else {
            left++;
            right--;
        }
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    rearrangeNegativeNumbersInArray(nums);
    for (int i = 0; i < n; i++) {
        cout << nums[i] << " ";
    }
    cout << "\n";
    return 0;
}