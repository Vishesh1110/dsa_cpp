// Partition a set into subset two subsets such that differnece of two subsets is minimum 

#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> arr = {1, 2, 3, 4};
    int n = arr.size();
    // {1, 4} - {2, 3} = 0

    cout << "Array:\n";
    for(int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }

    int totalSum = 0;
    for(int i = 0; i < n; i++) totalSum += arr[i];

    int k = totalSum;
    vector<vector<bool>> dp(n, vector<bool>(k+1, -1));
    for(int i = 0; i < n; i++)
    {
        dp[i][0] = true;
    }

    if(arr[0] <= k) dp[0][arr[0]] = true;

    for(int ind = 1; ind < n; ind++)
    {
        for(int target = 1; target <= k; target++)
        {
            bool notTake = dp[ind - 1][target];
            bool take = false;
            if(arr[ind] <= target) take = dp[ind - 1][target - arr[ind]]; 

            dp[ind][target] = take | notTake;
        }
    }

    int mini = 1e9;
    for(int s1 = 0; s1 <= totalSum/2; s1++)
    {
        if(dp[n-1][s1]) mini = min(mini, abs(totalSum - s1 - s1));
    }

    cout << "\n" << mini;
    return 0;
}