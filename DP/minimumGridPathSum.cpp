#include <bits/stdc++.h>
using namespace std;

// TC : O(2^(row * column))
// SC : O(Path_Length) (recursive stack space)
int findPathSumR(int row, int column, vector<vector<int>>& grid)
{
    if(row < 0 || column < 0) return INT_MAX-2000;
    if(row == 0 && column == 0) return grid[row][column];

    int up = grid[row][column] + findPathSumR(row - 1, column, grid);
    int left = grid[row][column] + findPathSumR(row, column - 1, grid);

    return min(up, left);
}
int recursion(vector<vector<int>>& grid)
{
    return findPathSumR(grid.size() - 1, grid[0].size() - 1, grid);
}


// TC : O(row * column)
// SC : O(row * column) + O(Path_Length) 
int findPathSumM(int row, int column, vector<vector<int>>& grid, vector<vector<int>>& dp)
{
    if(row < 0 || column < 0) return INT_MAX-2000;
    if(row == 0 && column == 0) return grid[row][column];

    if(dp[row][column] != -1) return dp[row][column];

    int up = grid[row][column] + findPathSumM(row - 1, column, grid, dp);
    int left = grid[row][column] + findPathSumM(row, column - 1, grid, dp);

    return dp[row][column] = min(up, left);
}
int memoization(vector<vector<int>>& grid)
{
    vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(), -1));
    return findPathSumM(grid.size() - 1, grid[0].size() - 1, grid, dp);
}


// TC : O(row * column)
// SC : O(row * column)
int tabulation(vector<vector<int>>& grid)
{
    int row = grid.size();
    int column = grid[0].size();

    int dp[row][column];

    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < column; j++)
        {
            if(i == 0 && j == 0) dp[i][j] = grid[i][j];
            else
            {
                int up = grid[i][j];
                if(i > 0) 
                    up += dp[i-1][j];
                else
                    up += 1e9;


                int left = grid[i][j];
                if(j > 0) 
                    left += dp[i][j-1];
                else
                    left += 1e9;

                dp[i][j] = min(up, left);
            }
        }
    }

    return dp[row - 1][column - 1];
} 


// TC : O(row * column)
// SC : O(column)
int spaceOptimization(vector<vector<int>>& grid)
{
    int row = grid.size();
    int column = grid[0].size();

    vector<int> prev(column, 0);

    for(int i = 0; i < row; i++)
    {
        vector<int> current(column, 0);
        for(int j = 0; j < column; j++)
        {
            if(i == 0 && j == 0) current[j] = grid[i][j];
            else
            {
                int up = grid[i][j];
                if(i > 0) 
                    up += prev[j];
                else
                    up += 1e9;


                int left = grid[i][j];
                if(j > 0) 
                    left += current[j-1];
                else
                    left += 1e9;

                current[j] = min(up, left);
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

    vector<vector<int>> grid = {{1, 3, 1}, 
                                {1, 5, 1}, 
                                {4, 2, 1}};

    cout << "Grid :\n";
    for(int i = 0; i < grid.size(); i++)
    {
        for(int j = 0; j < grid[i].size(); j++)
        {
            cout << grid[i][j] << " ";
        }
        cout << "\n";
    }

    cout << "\nMinimum Cost Path via recursion : " << recursion(grid);
    cout << "\nMinimum Cost Path via memoization : " << memoization(grid);
    cout << "\nMinimum Cost Path via tabulation : " << tabulation(grid);
    cout << "\nMinimum Cost Path via Space Optimization : " << spaceOptimization(grid);

    return 0;
}