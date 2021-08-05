#include <bits/stdc++.h>
using namespace std;

/*
    The algorithm and intuition:
    Algorithm has 4 steps:
    1. Traverse the array from the end and iterate till a[i] >= a[i+1] and if there is a element such that a[i]<a[i+1] then mark that is index1
    2. Traverse through the array from end and iterate till a[j] <= a[i] and if there exists a element such that a[j] > a[i] then mark that is index2
    3. Swap elements at index1 and index2
    4. Reverse the array from index+1 to end of the array
    Intution:
    Intuition is basically the dictionary order if you observe the pattern of elements the elements are increasing to a certain point and then decreasing so the point where the element decreases is considered as break point and operated
    Ex:
        2 4 5 is increasing order and 5 3 1 is decreasing order so the break point is 3  because that is where the decreasing happening so 1 will be our index1 and again iterate from end 4 < 3 false so swap 3 and 4 the array looks like after swapping [1 4 5 3 2] now reverse the array from position 2 to 4 (i.e 5 3 2 to 2 3 5) and you have the permutation that is [1 4 2 3 5]
                5
            3		4
        1				2
*/
void nextPermutation(vector<int> &nums) {
    int n = nums.size();
    if (n == 0 || n == 1)
        return;

    int i = n - 2;

    while (i >= 0 && nums[i] >= nums[i + 1])
        i--;
    if (i >= 0) {
        int j = n - 1;
        while (nums[j] <= nums[i])
            j--;
        swap(nums[i], nums[j]);
    }
    reverse(nums.begin() + i + 1, nums.end());
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    nextPermutation(nums);
    for (auto num : nums) {
        cout << num << " ";
    }
    return 0;
}