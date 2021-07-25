//Initial function template for C++

#include <bits/stdc++.h>
using namespace std;

int kthSmallest(int *, int, int, int);

int main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

    int test_case;
    cin >> test_case;
    while (test_case--) {
        int number_of_elements;
        cin >> number_of_elements;
        int a[number_of_elements];

        for (int i = 0; i < number_of_elements; i++)
            cin >> a[i];

        int k;
        cin >> k;

        cout << kthSmallest(a, 0, number_of_elements - 1, k) << endl;
    }
    return 0;
} // } Driver Code Ends

//User function template for C++

// arr : given array
// l : starting index of the array i.e 0
// r : ending index of the array i.e size-1
// k : find kth smallest element and return using this function
int kthSmallest(int arr[], int l, int r, int k) {
    // using counting sort
    int frequency[100001] = {0}, output[r + 1] = {0};

    for (int i = l; i <= r; i++) {
        frequency[arr[i]]++;
    }
    for (int i = 1; i < 100000; i++) {
        frequency[i] += frequency[i - 1];
    }
    for (int i = 0; i <= r; i++) {
        frequency[arr[i]]--;
        output[frequency[arr[i]]] = arr[i];
    }

    return output[k - 1];
}