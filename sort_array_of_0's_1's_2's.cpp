#include <bits/stdc++.h>
using namespace std;

/*
    Algorithm: Dutch National Flag 
        This algorithm uses three pointers (low,mid and high) assuming all the 2's are from [high+1 to n], 0's from [0 to low-1] and 1's from [low +1 to mid]
        This operates on three Conditions
            1. nums[mid] == 0 then swap(nums[low],nums[mid]) and increment low and mid(low++,mid++)
            2. nums[mid] == 1 then mid++
            3. nums[mid] == 2 then swap(nums[mid],nums[high]) and decrement high(high--)

*/
void sort012(vector<int> &nums) {
    if (nums.size() == 0)
        return;
    int high = nums.size() - 1, low = 0, mid = 0;
    while (mid <= high) {
        if (nums[mid] == 0) {
            swap(nums[low++], nums[mid++]);
        } else if (nums[mid] == 1) {
            mid++;
        } else {
            swap(nums[mid], nums[high--]);
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }
        sort012(nums);
        for (int i = 0; i < n; i++) {
            cout << nums[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}