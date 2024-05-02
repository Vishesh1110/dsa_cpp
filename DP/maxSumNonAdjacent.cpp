// Find the maximum sum of non-adjacent array elements.
#include <bits/stdc++.h>
using namespace std;


// Time Complexity : O(2^n) approx
// Space Complexity : O(n)
int recursion(int arr[], int index)
{
    if(index == 0) return arr[index];

    if(index < 0) return 0;

    int pick = arr[index] + recursion(arr, index - 2);
    int notPick = recursion(arr, index-1);

    return max(pick, notPick);
}


// Time Complexity : O(n)
// Space Complexity : O(n) + O(n)
int memoizationHelper(vector<int>& dp, int arr[], int index)
{
    if(index == 0) return arr[index];

    if(index < 0) return 0;

    if(dp[index] != -1) return dp[index];

    int pick = arr[index] + memoizationHelper(dp, arr, index-2);
    int notPick = memoizationHelper(dp, arr, index-1);

    return dp[index] = max(pick, notPick);
}
int memoization(int arr[], int n)
{
    vector<int> dp(n, -1);
    return memoizationHelper(dp, arr, n-1);
}


// Time Complexity : O(n)
// Space Complexity : O(n)
int tabulation(int arr[], int n)
{
    vector<int> dp(n, 0);
    dp[0] = arr[0];

    for(int i = 1; i < n; i++)
    {
        int pick = arr[i];
        if(i > 1)
        {
            pick += dp[i-2];
        }
        int notPick = dp[i-1];
        dp[i] = max(pick, notPick);
    }
    return dp[n-1];
}


// Time Complexity : O(n)
// Space Complexity : O(1)
int spaceOptimization(int arr[], int n)
{
    int prev1 = arr[0], prev2 = 0;
    for(int i = 1; i < n; i++)
    {
        int pick = arr[i];
        if(i > 1)
        {
            pick += prev2;
        }
        int notPick = prev1;
        int current = max(pick, notPick);
        prev2 = prev1;
        prev1 = current;
    }
    return prev1;
}



int main()
{
    int arr[] = {2, 1, 4, 9};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << "\nMaximum Sum of Non-adjacent Elements = " << recursion(arr, n-1);
    cout << "\nMaximum Sum of Non-adjacent Elements = " << memoization(arr, n);
    cout << "\nMaximum Sum of Non-adjacent Elements = " << tabulation(arr, n);
    cout << "\nMaximum Sum of Non-adjacent Elements = " << spaceOptimization(arr, n);

    return 0;
}