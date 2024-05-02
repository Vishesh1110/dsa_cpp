#include <bits/stdc++.h>
using namespace std;


int recursion(int index, vector<int>& arr, int sum)
{
    if(sum == 0) return 1;
    if(index == 0) return arr[0] == sum;

    int notTake = recursion(index - 1, arr, sum);
    int take = 0;
    if(arr[index] <= sum) 
    {
        take = recursion(index - 1, arr, sum - arr[index]);
    }

    return take + notTake;
}


int memoizationHelper(int index, vector<int>& arr, int sum, vector<vector<int>>& dp)
{
    if(sum == 0) return 1;
    if(index == 0) return arr[0] == sum;

    if(dp[index][sum] != -1) return dp[index][sum];

    int notTake = recursion(index - 1, arr, sum);
    int take = 0;
    if(arr[index] <= sum) 
    {
        take = recursion(index - 1, arr, sum - arr[index]);
    }

    return dp[index][sum] = take + notTake;
}
int memoization(int index, vector<int>& arr, int sum)
{
    vector<vector<int>> dp(arr.size(), vector<int>(sum+1, -1));
    return memoizationHelper(index, arr, sum, dp);
}


int tabulation(vector<int>& arr, int sum)
{
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(sum + 1, 0));

    for(int i = 0; i < n; i++) dp[i][0] = 1;

    if(arr[0] <= sum) dp[0][arr[0]] = 1;

    for(int i = 1; i < n; i++)
    {
        for(int target = 0; target <= sum; target++)
        {
            int notTake = dp[i - 1][target];

            int take = 0;
            if(arr[i] <= target) take = dp[i - 1][target - arr[i]];

            dp[i][target] = take + notTake;
        }
    }

    return dp[n-1][sum];
}


int spaceOptimization(vector<int>& arr, int sum)
{
    int n = arr.size();
    vector<int> prev(sum + 1, 0), curr(sum + 1);

    prev[0] = curr[0] = 1;

    if(arr[0] <= sum) prev[arr[0]] = 1;

    for(int i = 1; i < n; i++)
    {
        for(int target = 0; target <= sum; target++)
        {
            int notTake = prev[target];

            int take = 0;
            if(arr[i] <= target) take = prev[target - arr[i]];

            curr[target] = take + notTake;
        }
        prev = curr;
    }

    return prev[sum];
}


int main()
{
    vector<int> arr = {1, 2, 3, 4};
    // Subsets with sum = 5 : {1, 4}, {2, 3}
    int n = arr.size();
    int sum = 5;

    cout << "Array:\n";
    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << "\nNumber of Subsets with sum " << sum << " is via recursion : " << recursion(n - 1, arr, sum);
    cout << "\nNumber of Subsets with sum " << sum << " is via memoization : " << memoization(n - 1, arr, sum);
    cout << "\nNumber of Subsets with sum " << sum << " is via tabulation : " << tabulation(arr, sum);
    cout << "\nNumber of Subsets with sum " << sum << " is via space optimization : " << spaceOptimization(arr, sum);

    return 0;
}