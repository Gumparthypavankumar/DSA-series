#include <bits/stdc++.h>
using namespace std;

/*
    The idea is to maintain a set and insert the elements since set does not allow duplicates we can be sure that final answer will only contain distinct elements
*/

class Solution {
public:
    int doUnion(int A[], int N, int B[], int M) {
        set<int> unionofarrays;
        for (int i = 0; i < N; i++) {
            unionofarrays.insert(A[i]);
        }
        for (int i = 0; i < M; i++) {
            unionofarrays.insert(B[i]);
        }
        return unionofarrays.size();
    }
};

// { Driver Code Starts.

int main() {

    int t;
    cin >> t;

    while (t--) {

        int n, m;
        cin >> n >> m;
        int a[n], b[m];

        for (int i = 0; i < n; i++)
            cin >> a[i];

        for (int i = 0; i < m; i++)
            cin >> b[i];

        Solution ob;
        cout << ob.doUnion(a, n, b, m) << endl;
    }

    return 0;
}