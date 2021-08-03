#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minJumps(int arr[], int n) {
        if (n <= 1)
            return 0;

        if (arr[0] == 0)
            return -1;

        int ladder = arr[0];
        int stairs = arr[0];

        int jump = 1;
        int level = 1;
        for (level = 1; level < n; level++) {
            if (level == n - 1) {
                return jump;
            }
            ladder = max(ladder, level + arr[level]);
            stairs--;
            if (stairs == 0) {
                jump++;
                if (level >= ladder)
                    return -1;
                stairs = ladder - level;
            }
        }
        return jump;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i, j;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        Solution obj;
        cout << obj.minJumps(arr, n) << endl;
    }
    return 0;
}