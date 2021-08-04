#include <bits/stdc++.h>
using namespace std;

// in this approach we maintain a temp interval and compare the other intervals if it lies then change the right interval and continue if it doesn’t then store it and change the tempInterval to current interval

vector<vector<int>> merge(vector<vector<int>> &intervals) {
    vector<vector<int>> mergedIntervals;
    if (intervals.size() == 0) {
        return mergedIntervals;
    }
    sort(intervals.begin(), intervals.end());
    vector<int> tempInterval = intervals[0];
    for (auto it : intervals) {
        if (it[0] <= tempInterval[1]) { // {{1,3},{2,4}} if the 1st element is less than the right index oftemp then it lies in the interval range tempInterval[0],tempInterval[1] and the right interval must be the max of two intervals.
            tempInterval[1] = max(it[1], tempInterval[1]);
        } else {
            mergedIntervals.push_back(tempInterval);
            tempInterval = it;
        }
    }
    mergedIntervals.push_back(tempInterval);
    return mergedIntervals;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> intervals;
    for (int i = 0; i < n; i++) {
        vector<int> subIntervals;
        for (int j = 0; j < m; j++) {
            int k;
            cin >> k;
            subIntervals.push_back(k);
        }
        intervals.push_back(subIntervals);
    }
    vector<vector<int>> ans = merge(intervals);
    cout << "[";
    for (int i = 0; i < ans.size(); i++) {
        cout << "[";
        for (int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << ",";
        }
        cout << "]";
    }
    cout << "]";
    return 0;
}
