#include <bits/stdc++.h>
using namespace std;

/*
Problem Link: https://leetcode.com/problems/find-the-duplicate-number/

We maintain two pointers slow and fast initially they are placed at first position and slow pointer moves 1 step ahead in each iteration and fast pointer moves 2 steps ahead when the both pointers meet we will make fast pointer point to the first position and then move both the pointers one step and iterate till both meet the point where they meet is the starting point of loop.
Intuition:
// Proof that they meet:
At the point when a slow pointer enters the cycle fast pointer will already be in a cycle.
Now if consider movements of slow and fast pointers, we can notice that distance between them (from slow to fast) increase by one after every iteration. After one iteration (of slow = next of slow and fast = next of next of fast), distance between slow and fast becomes k+1, after two iterations, k+2, and so on. When distance becomes n, they meet because they are moving in a cycle of length n.
*/
int findDuplicate(vector<int> &nums) {
    int slow = nums[0], fast = nums[0];
    do {
        slow = nums[slow];
        fast = nums[nums[fast]];
    } while (slow != fast);

    fast = nums[0];
    while (slow != fast) {
        slow = nums[slow];
        fast = nums[fast];
    }
    return slow;
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    cout << findDuplicate(nums) << "\n";
    return 0;
}