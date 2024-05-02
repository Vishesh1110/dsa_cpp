#include <bits/stdc++.h>
using namespace std;

long long minWeightDiff(long long index, long long currSum, long long totalSum, vector<long long>& arr, long long n) {
    if(index == n-1)
        return abs(totalSum - 2 * currSum);

    long long take = minWeightDiff(index + 1, currSum + arr[index], totalSum, arr, n);
    long long notTake = minWeightDiff(index + 1, currSum, totalSum, arr, n);

    return min(take, notTake);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long n, sum = 0; 
    cin >> n;

    vector<long long> arr(n);
    for(long long i = 0; i < n; i++) {
        cin >> arr[i];
        sum += arr[i];
    }

    cout << minWeightDiff(0, 0, sum, arr, n);

    return 0;
}