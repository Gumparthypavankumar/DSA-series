#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long merge(long long arr[], long long temp[], int start, int m, int end) {
        int i = start;
        int j = m;
        int k = start;
        long long invCount = 0;
        while ((i <= m - 1) && (j <= end)) {
            if (arr[i] <= arr[j]) {
                temp[k] = arr[i];
                i++;
            } else {
                temp[k] = arr[j];
                j++;
                invCount += (m - i);
            }
            k++;
        }
        while (i <= m - 1) {
            temp[k] = arr[i];
            i++;
            k++;
        }
        while (j <= end) {
            temp[k] = arr[j];
            k++;
            j++;
        }
        for (int i = start; i <= end; i++)
            arr[i] = temp[i];
        return invCount;
    }

    long long mergeSort(long long arr[], long long temp[], int low, int high) {
        long long invCount = 0;
        if (low == high) {
            return 0;
        }
        int mid = (low + high) / 2;
        invCount += mergeSort(arr, temp, low, mid);
        invCount += mergeSort(arr, temp, mid + 1, high);
        invCount += merge(arr, temp, low, mid + 1, high);
        return invCount;
    }

    long long int inversionCount(long long arr[], long long N) {
        long long temp[N];
        return mergeSort(arr, temp, 0, N - 1);
    }
};

int main() {

    long long T;
    cin >> T;

    while (T--) {
        long long N;
        cin >> N;

        long long A[N];
        for (long long i = 0; i < N; i++) {
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A, N) << endl;
    }

    return 0;
}