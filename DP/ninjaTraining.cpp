#include <bits/stdc++.h>
using namespace std;

int recursion(int day, int lastTask, vector<vector<int>>& points)
{
    if(day == 0)
    {
        int maxi = 0;
        for(int task = 0; task < 3; task++)
        {
            if(task != lastTask)
            {
                maxi = max(maxi, points[0][task]);
            }
        }
        return maxi;
    }

    int maxi = 0;

    for(int task = 0; task < 3; task++)
    {
        if(task != lastTask)
        {
            int point = points[day][task] + recursion(day - 1, task, points);
            maxi = max(maxi, point);
        }
    }
    return maxi;
}


// TC : O(Nx4)x3
// SC : O(N) + O(Nx4)
int memoizationHelper(int day, int lastTask, vector<vector<int>>& points, vector<vector<int>>& dp)
{
    if(day == 0)
    {
        int maxi = 0;
        for(int task = 0; task < 3; task++)
        {
            if(task != lastTask)
            {
                maxi = max(maxi, points[0][task]);
            }
        }
        return maxi;
    }

    if(dp[day][lastTask] != -1) return dp[day][lastTask];

    int maxi = 0;

    for(int task = 0; task < 3; task++)
    {
        if(task != lastTask)
        {
            int point = points[day][task] + memoizationHelper(day - 1, task, points, dp);
            maxi = max(maxi, point);
        }
    }
    return dp[day][lastTask] = maxi;
}
int memoization(int n, vector<vector<int>>& points)
{
    vector<vector<int>> dp(n, vector<int>(4, -1));
    return memoizationHelper(n-1, 3, points, dp);
}


// TC : O(Nx4x3)
// SC : O(Nx4)
int tabulation(int n, vector<vector<int>>& points)
{
    vector<vector<int>> dp(n, vector<int>(4, 0));

    dp[0][0] = max(points[0][1], points[0][2]);
    dp[0][1] = max(points[0][0], points[0][2]);
    dp[0][2] = max(points[0][0], points[0][1]);
    dp[0][3] = max(points[0][1], points[0][2]);

    for(int day = 1; day < n; day++)
    {
        for(int last = 0; last < 4;  last++)
        {
            dp[day][last] = 0;

            for(int task = 0; task < 3; task++)
            {
                if(task != last)
                {
                    int point = points[day][task] + dp[day-1][task];
                    dp[day][last] = max(dp[day][last], point);
                }
            }
        }
    }

    return dp[n-1][3];
}


// TC : O(Nx4x3)
// SC : O(4)
int spaceOptimization(int n, vector<vector<int>>& points)
{
    vector<int> dp(4, 0);

    dp[0] = max(points[0][1], points[0][2]);
    dp[1] = max(points[0][0], points[0][2]);
    dp[2] = max(points[0][0], points[0][1]);
    dp[3] = max(points[0][1], points[0][2]);

    for(int day = 1; day < n; day++)
    {
        vector<int> temp(4, 0);
        for(int last = 0; last < 4;  last++)
        {
            temp[last] = 0;

            for(int task = 0; task < 3; task++)
            {
                if(task != last)
                {
                    temp[last] = max(temp[last], points[day][task] + dp[task]);
                }
            }
        }
        dp = temp;
    }
    return dp[3];    
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<vector<int>> points = {{18, 11, 19},
                                 {4, 13, 7},
                                 {1, 8, 13}};

    int n = points.size();

    cout << "\nTasks points:\n";
    for(int i = 0; i < points.size(); i++)
    {
        for(int j = 0; j < 3; j++)
        {
            cout << points[i][j] << " ";
        }
        cout << "\n";
    }

    cout << "\nMaximum points using recursion : " << recursion(n-1, 3, points);
    cout << "\nMaximum points using memoization : " << memoization(n, points);
    cout << "\nMaximum points using tabulation : " << tabulation(n, points);
    cout << "\nMaximum points using Space Optimization : " << spaceOptimization(n, points);

    return 0;
}