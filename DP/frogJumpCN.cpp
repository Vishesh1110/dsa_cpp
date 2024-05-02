// A Frog can jump to stairs whose heights are given in an array. Frogis placed at the 
// initial step and can make 1 or 2 jumps only and for each jump the frog loses its 
// energy by |heights[currentStep] - heights[nextStep]|. Find the minimum energy required
// for reaching the frog to the end step.



#include <bits./stdc++.h>
using namespace std;


int helper1(int index, vector<int>& heights)
{
    if(index == 0) return 0;

    int left = helper1(index-1, heights) + abs(heights[index] - heights[index-1]);
    int right = INT_MAX;
    if(index > 1)
        right = helper1(index-2, heights) + abs(heights[index] - heights[index-2]);
    
    return min(left, right);
}
int recursion(int n, vector<int>& heights)
{
    return helper1(n-1, heights);
}



int helper2(int index, vector<int>& heights, vector<int>& dp)
{
    if(index == 0) return 0;

    if(dp[index] != -1) return dp[index];

    int left = helper2(index-1, heights, dp) + abs(heights[index] - heights[index-1]);
    int right = INT_MAX;
    if(index > 1)
        right = helper2(index-2, heights, dp) + abs(heights[index] - heights[index-2]);
    
    return dp[index] = min(left, right);
}
int memoization(int n, vector<int>& heights)
{
    vector<int> dp(n+1, -1);
    return helper2(n-1, heights, dp);
}



int tabulation(int n, vector<int>& heights)
{
    vector<int> dp(n, 0);
    dp[0] = 0;

    for(int i = 1; i < n; i++)
    {
        int step1 = dp[i-1] + abs(heights[i] - heights[i-1]);
        int step2 = INT_MAX;

        if(i > 1)
            step2 = dp[i-2] + abs(heights[i] - heights[i-2]);

        dp[i] = min(step1, step2);
    }

    return dp[n-1];
}



int spaceOptimized(int n, vector<int>& heights)
{
    int prev1 = 0, prev2 = 0;

    for(int i = 1; i < n; i++)
    {
        int step1 = prev1 + abs(heights[i] -  heights[i-1]);
        int step2 = INT_MAX;

        if(i > 1)
            step2 = prev2 + abs(heights[i] -  heights[i-2]);

        int curr = min(step1, step2);
        prev2 = prev1;
        prev1 = curr;
    }

    return prev1;
}



int main()
{
    vector<int> heights = {10, 20, 30, 10};
    int n = heights.size();

    cout << "Minimum Energy used (recursion) = " << recursion(n, heights) << "\n";
    cout << "Minimum Energy used (memoization) = " << memoization(n, heights) << "\n";
    cout << "Minimum Energy used (tabulation) = " << tabulation(n, heights) << "\n";

    return 0;
}