#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getPairsCount(int arr[], int n, int k) {
        unordered_map<int, int> m;
        for (int i = 0; i < n; i++) {
            m[arr[i]]++;
        }
        int twice_count = 0;
        for (int i = 0; i < n; i++) {
            twice_count += m[k - arr[i]];
            if (k - arr[i] == arr[i])
                twice_count--;
        }
        /*
            Since for each element we are actually adding the frequency count for repeating elements we will add frequency twice to avoid it we return result by 2

            EX: {1, 5, 7, 1}

            k = 6

            map = { {1, 2}, {5, 1}, {7, 1} };

            each i in arr[i]:

                1 -> map[k - 1] => count += m[5] => count = 0 + 1 = 1
                5 -> map[k - 5] => count += m[1] => count = 1 + 2 = 3 -> here you need to ignore one 1 since it is already added when pair is (1, 5) as above
                7 -> map[k - 7] => count += m[-1] => count = 3 + 0 = 3
                1 -> map[k - 1] => count += m[5] => count = 3 + 1 = 4 -> here you need to ignore 5 since it is already added when pair is (5, 1)

                This is why divide by 2

            the last condition k-a[i] == a[i] to check whether the pair that we are checking is not for the same number at same index 
        */
        return twice_count / 2;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.getPairsCount(arr, n, k);
        cout << ans << "\n";
    }

    return 0;
}