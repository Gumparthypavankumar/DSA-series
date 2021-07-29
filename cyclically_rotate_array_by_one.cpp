#include <bits/stdc++.h>
using namespace std;

/*
    General Approach:
        Initialize lastelement with arr[n-1]
        iterate from n-1 to 1 and assign current element with previous element after all the iterations assign arr[0] = lasteelement
        for(int i=n-1; i>= 1; i++){
            arr[i] = arr[i-1];
        }
        arr[0] = lastelement
    Approach Using Two pointer technique  
    steps: Initially first starts at 0, last at n-1
           In every Single Iteration we will swap the first element with last element and increment first at the end when first exceeds or becomes equal to the last we will break loop
*/
void rotate(int arr[], int n) {
    int first = 0, last = n - 1;
    while (first != last) {
        swap(arr[first], arr[last]);
        first++;
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n], i;
        for (i = 0; i < n; i++)
            cin >> a[i];
        rotate(a, n);
        for (i = 0; i < n; i++)
            cout << a[i] << " ";
        cout << "\n";
    }
    return 0;
}
