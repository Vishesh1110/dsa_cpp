#include <bits/stdc++.h>
using namespace std;

int lis(vector<int>& arr, int n) {
    vector<int> dp;
    dp.push_back(arr[0]);
    int lenLIS = 1;

    for(int i = 0; i < arr.size(); i++) {
        if(arr[i] > dp.back()) {
            dp.push_back(arr[i]);
            lenLIS++;
        }
        else {
            int index = lower_bound(dp.begin(), dp.end(), arr[i]) - dp.begin();
            dp[index] = arr[i];
        }
    }
    return lenLIS;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    cout << lis(arr, n);

    return 0;
}