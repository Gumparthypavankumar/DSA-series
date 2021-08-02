#include <bits/stdc++.h>
using namespace std;

/*
    Problem Link: https://practice.geeksforgeeks.org/problems/minimize-the-heights3351/1
*/
class Solution {
public:
    int getMinDiff(int arr[], int n, int k) {
        sort(arr, arr + n); // Sort the array since we had to pick smallest element and largest element
        int ans = arr[n - 1] - arr[0];
        /*
            while calculating minimum difference between two numbers after adding or subtracting k is obvious that
            we add k to smallest Element and subtract k from largest element that is why we do it here 
        */
        int smallest = arr[0] + k;
        int largest = arr[n - 1] - k;
        int minElem, maxElem;

        for (int i = 0; i < n - 1; i++) {
            minElem = min(smallest, arr[i + 1] - k); // Everytime check for smallest between smallest and nextElement - k because the next element might be smallest if subtracted similarly for maxElem
            maxElem = max(largest, arr[i] + k);
            if (minElem < 0)
                continue; // if minElem is negative there is no point in computing ans since maxElem - (-) returns out to be positive
            ans = min(ans, maxElem - minElem);
        }
        return ans;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> k;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.getMinDiff(arr, n, k);
        cout << ans << "\n";
    }
    return 0;
}