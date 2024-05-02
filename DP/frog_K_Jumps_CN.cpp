// A Frog can jump to stairs whose heights are given in an array. Frog is placed at the 
// initial step and can make at max K jumps at an instant only and for each jump the frog
// loses its energy by |heights[currentStep] - heights[nextStep]|. Find the minimum energy 
// required for reaching the frog to the end step.



#include <bits./stdc++.h>
using namespace std;


int helper1(int index, int k, vector<int>& heights)
{
    if(index == 0) return 0;

    int minSteps = INT_MAX;
    for(int j = 1; j <= k; j++)
    {
        if(index-j >= 0)
        {
            int jump = helper1(index-j, k, heights) + abs(heights[index] - heights[index-j]);
            minSteps = min(minSteps, jump);
        }
        else 
        {
            break;
        }
    }

    return minSteps;
}
int recursion(int n, int k, vector<int>& heights)
{
    return helper1(n-1, k, heights);
}



int helper2(int index, int k, vector<int>& heights, vector<int>& dp)
{
    if(index == 0) return 0;

    if(dp[index] != -1) return dp[index];

    int minSteps = INT_MAX;
    for(int j = 1; j <= k; j++)
    {
        if(index-j >= 0)
        {
            int jump = helper1(index-j, k, heights) + abs(heights[index] - heights[index-j]);
            minSteps = min(minSteps, jump);
        }
        else 
        {
            break;
        }
    }
    
    return dp[index] = minSteps;
}
int memoization(int n, int k, vector<int>& heights)
{
    vector<int> dp(n+1, -1);
    return helper2(n-1, k, heights, dp);
}


int main()
{
    vector<int> heights = {10, 20, 30, 10};
    int n = heights.size();
    int k = 3;

    cout << "Minimum Energy used (recursion) = " << recursion(n, k, heights) << "\n";
    cout << "Minimum Energy used (memoization) = " << memoization(n, k, heights) << "\n";
    // cout << "Minimum Energy used (tabulation) = " << tabulation(n, k, heights) << "\n";

    return 0;
}