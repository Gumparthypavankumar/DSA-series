#include <bits/stdc++.h>
using namespace std;

/*
    Time Complexity : O(n ^ 2) since we are maintaining order otherwise it can be done in O(n)
    Maintain 3 indices i, j, index 
    1. i is responsible for finding negative element
    2. j is responsible for finding positive element
    3. index is responsible for traversing the array

    This algorith is based on assumption that every even index will have -ve number and every odd index will have positive number if something is misplaced then we will use i and j to find numbers according to their signs

    We will shift the array to maintain order instead of swapping
*/

void rotate(vector<int> &nums, int from, int to) {
    int temp = nums[to];
    for (int i = to; i >= from; i--) {
        nums[i] = nums[i - 1];
    }
    nums[from] = temp;
}

void rearrange_array(vector<int> &nums) {
    int size = nums.size();
    int i = 0, j = 0, index = 0;
    while (i < size && j < size && index < size) {
        if (index % 2 == 0) {
            if (nums[index] >= 0) {
                j = index;
                i = index;
                while (i < size && nums[i] >= 0)
                    i++;
                if (i >= size)
                    break;
                rotate(nums, index, i);
            }
        } else {
            if (nums[index] < 0) {
                j = index;
                i = index;
                while (j <= size && nums[j] < 0)
                    j++;
                if (j >= size)
                    break;
                rotate(nums, index, j);
            }
        }
        index++;
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    rearrange_array(nums);
    for (int i = 0; i < n; i++) {
        cout << nums[i] << " ";
    }
    return 0;
}