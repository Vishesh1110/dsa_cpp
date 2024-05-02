#include <bits/stdc++.h>
using namespace std;

// TC : O(2^(sum*N))
// SC : recursive stack space
bool recursionHelper(vector<int>& arr, int sum, int index)
{
    if(sum == 0) return true;
    if(index == 0) return arr[0] == sum;
    
    bool notTake = recursionHelper(arr, sum, index-1);
    bool take = false;
    if(sum >= arr[index])
    {
        take = recursionHelper(arr, sum - arr[index], index-1);
    }
    
    return take | notTake;
}
bool recursion(vector<int>arr, int sum)
{    
    return recursionHelper(arr, sum, arr.size()-1);
}


// TC : O(sum*N)
// SC : O(sum*N) + recursive stack space
bool memoizationHelper(vector<int>& arr, int sum, int index, vector<vector<int>>& dp)
{
    if(sum == 0) return true;
    if(index == 0) return arr[0] == sum;
    
    if(dp[index][sum] != -1) return dp[index][sum];
    
    bool notTake = memoizationHelper(arr, sum, index-1, dp);
    bool take = false;
    if(sum >= arr[index])
    {
        take = memoizationHelper(arr, sum - arr[index], index-1, dp);
    }
    
    return dp[index][sum] = take | notTake;
}
bool memoization(vector<int>arr, int sum)
{
    vector<vector<int>> dp(arr.size(), vector<int>(sum+1, -1));
    return memoizationHelper(arr, sum, arr.size()-1, dp);
}


// TC : O(sum*N)
// SC : O(sum*N) 
bool tabulation(vector<int>arr, int sum)
{
    vector<vector<bool>> dp(arr.size(), vector<bool>(sum+1, 0));

    for(int i = 0; i < arr.size(); i++)
    {
        dp[i][0] = true;
    }

    dp[0][arr[0]] = true;

    for(int i = 1; i < arr.size(); i++)
    {
        for(int target = 1; target <= sum; target++)
        {
            bool notTake = dp[i-1][target];
            bool take = false;
            if(sum >= arr[i])
            {
                take = dp[i-1][sum-arr[i]];
            }

            dp[i][target] = take | notTake;
        }
    }
    return dp[arr.size()-1][sum];
}


// TC : O(sum*N)
// SC : O(sum) 
bool spaceOptimization(vector<int>arr, int sum)
{
    vector<bool> prev(sum+1, 0), curr(sum+1, 0);

    prev[0] = curr[0] = true;

    if(arr[0] <= sum) prev[arr[0]] = true;

    for(int i = 1; i < arr.size(); i++)
    {
        for(int target = 1; target <= sum; target++)
        {
            bool notTake = prev[target];
            bool take = false;
            if(sum >= arr[i])
            {
                take = prev[sum-arr[i]];
            }

            curr[target] = take | notTake;
        }
        prev = curr;
    }
    return prev[sum];
}


int main()
{
    vector<int> arr = {1, 2, 3, 4};
    int sum = 4;

    cout << "Array:\n";
    for(int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }

    cout << "\nTarget sum found via recursion : " << recursion(arr, sum);
    cout << "\nTarget sum found via memoization : " << memoization(arr, sum);
    cout << "\nTarget sum found via tabulation : " << tabulation(arr, sum);
    cout << "\nTarget sum found via space optimization : " << spaceOptimization(arr, sum);

    return 0;
}