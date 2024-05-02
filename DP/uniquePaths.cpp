#include <bits/stdc++.h>
using namespace std;


// TC : O(2^(row*column))
// SC : O(Path_length) (recursive stack space)
int findPathsR(int row, int column)
{
    if(row == 0 && column == 0) return 1;
    if(row < 0 || column < 0) return 0;

    int up = findPathsR(row - 1, column);
    int left = findPathsR(row, column - 1);

    return up + left;
}
int recursion(int row, int column)
{
    return findPathsR(row - 1, column - 1);
}


// TC : O(row * column)
// SC : O(row * column) + O(N) (recursive stack space)
int findPathsM(int row, int column, vector<vector<int>>& dp)
{
    if(row == 0 && column == 0) return 1;
    if(row < 0 || column < 0) return 0;

    if(dp[row][column] != -1) return dp[row][column];

    int up = findPathsR(row - 1, column);
    int left = findPathsR(row, column - 1);

    return dp[row][column] = up + left;
}
int memoization(int row, int column)
{
    vector<vector<int>> dp(row, vector<int>(column, -1));
    return findPathsM(row - 1, column - 1, dp);
}

// TC : O(row * column)
// SC : O(row * column)
int tabulation(int row, int column)
{
    int dp[row][column];
    dp[0][0] = 1;

    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < column; j++)
        {
            if(i == 0 && j == 0) continue;
            else
            {
                int up = 0, left = 0;
                
                if(i > 0) up = dp[i-1][j];
                if(j > 0) left = dp[i][j-1];

                dp[i][j] = up + left;
            }
        }
    }

    return dp[row - 1][column - 1];
}

// TC : O(row * column)
// SC : O(column)
int spaceOptimization(int row, int column)
{
    vector<int> prev(column, 0);

    for(int i = 0; i < row; i++)
    {
        vector<int> current(column, 0);
        for(int j = 0; j < column; j++)
        {
            if(i == 0 && j == 0) current[j] = 1;
            else
            {
                int up = 0, left = 0;
                
                if(i > 0) up = prev[j];
                if(j > 0) left = current[j-1];

                current[j] = up + left;
            }
        }
        prev = current;
    }
    return prev[column - 1];
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int row = 3, column = 3;

    cout << "Total rows : " << row;
    cout << "\nTotal columns : " << column;

    cout << "\n\nTotal Unique Paths via recursion : " << recursion(row, column);
    cout << "\nTotal Unique Paths via memoization : " << memoization(row, column);
    cout << "\nTotal Unique Paths via tabulation: " << tabulation(row, column);
    cout << "\nTotal Unique Paths via space optimization : " << spaceOptimization(row, column);

    return 0;
}