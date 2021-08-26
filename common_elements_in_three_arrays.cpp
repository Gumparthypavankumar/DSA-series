#include <bits/stdc++.h>
using namespace std;

/*
    Algorithm is to find intersection of arrays and add it to array since the result must not contain duplicates I used set
*/
class Solution {
public:
    vector<int> commonElements(int A[], int B[], int C[], int n1, int n2, int n3) {
        vector<int> ans;
        set<int> res;
        int i = 0, j = 0, k = 0;
        while (i < n1 && j < n2 && k < n3) {
            if (A[i] == B[j] && B[j] == C[k]) {
                if (res.find(A[i]) == res.end()) {
                    ans.push_back(A[i]);
                }
                res.insert(A[i]);
                i++;
                j++;
                k++;
            } else if (A[i] > B[j])
                j++;
            else if (B[j] > C[k])
                k++;
            else
                i++;
        }
        return ans;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n1, n2, n3;
        cin >> n1 >> n2 >> n3;
        int A[n1];
        int B[n2];
        int C[n3];

        for (int i = 0; i < n1; i++)
            cin >> A[i];
        for (int i = 0; i < n2; i++)
            cin >> B[i];
        for (int i = 0; i < n3; i++)
            cin >> C[i];

        Solution ob;

        vector<int> res = ob.commonElements(A, B, C, n1, n2, n3);
        if (res.size() == 0)
            cout << -1;
        for (int i = 0; i < res.size(); i++)
            cout << res[i] << " ";
        cout << endl;
    }
}