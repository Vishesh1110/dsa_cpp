#include <bits/stdc++.h>
using namespace std;

// TC : O(3^(row*column*column))
// SC: recursive stack space
int recursionHelper(int i, int j1, int j2, int row, int column, vector<vector<int>>& grid)
{
    if(j1 < 0 || j2 < 0 || j1 >= column || j2 >= column) 
        return -1e6;

    // when the players are at the last row
    if(i == row-1)
    {
        if(j1 == j2) 
            return grid[i][j1];
        return grid[i][j1] + grid[i][j2];
    }

    // explore all paths of Alice and Bob simultaneously
    int maxi = -1e6;
    for(int dj1 = -1; dj1 <= 1; dj1++)
    {
        for(int dj2 = -1; dj2 <= 1; dj2++)
        {
            int value = 0;
            if(j1 == j2) value = grid[i][j1];
            else value = grid[i][j1] + grid[i][j2];
            value += recursionHelper(i + 1, j1 + dj1, j2 + dj2, row, column, grid);
            maxi = max(maxi, value);
        }
    }
    return maxi;
}
int recursion(int row, int column, vector<vector<int>>& grid)
{
    return recursionHelper(0, 0, column-1, row, column, grid);
}


// TC : O(row*column*column)
// SC: O(row*column*column) + recursive stack space
int memoizationHelper(int i, int j1, int j2, int row, int column, vector<vector<int>>& grid, vector<vector<vector<int>>>& dp)
{
    if(j1 < 0 || j2 < 0 || j1 >= column || j2 >= column) return -1e6;

    if(i == row-1)
    {
        if(j1 == j2) return grid[i][j1];
        else return grid[i][j1] + grid[i][j2];
    }

    if(dp[i][j1][j2] != -1) return dp[i][j1][j2];

    // explore all paths of Alice and Bob simultaneously
    int maxi = -1e6;
    for(int dj1 = -1; dj1 <= 1; dj1++)
    {
        for(int dj2 = -1; dj2 <= 1; dj2++)
        {
            int value = 0;
            if(j1 == j2) value = grid[i][j1];
            else value = grid[i][j1] + grid[i][j2];
            value += memoizationHelper(i + 1, j1 + dj1, j2 + dj2, row, column, grid, dp);
            maxi = max(maxi, value);
        }
    }
    return dp[i][j1][j2] = maxi;
}
int memoization(int row, int column, vector<vector<int>>& grid)
{
    vector<vector<vector<int>>> dp(row, vector<vector<int>>(column, vector<int>(column, -1)));
    return memoizationHelper(0, 0, column-1, row, column, grid, dp);
}

// TC : O(row*column*column)
// SC: O(row*column*column)
int tabulation(int row, int column, vector<vector<int>>& grid)
{
    vector<vector<vector<int>>> dp(row, vector<vector<int>>(column, vector<int>(column, 0)));
    for(int j1 = 0; j1 < column; j1++)
    {
        for(int j2 = 0; j2 < column; j2++)
        {
            if(j1 == j2)
            {
                dp[row - 1][j1][j2] = grid[row - 1][j1];
            }
            else
            {
                dp[row - 1][j1][j2] = grid[row - 1][j1] + grid[row - 1][j2];
            }
        }
    }


    for(int i = row - 2; i >= 0; i--)
    {
        for(int j1 = 0; j1 < column; j1++)
        {
            for(int j2 = 0; j2 < column; j2++)
            {
                int maxi = -1e8;
                for(int dj1 = -1; dj1 <= 1; dj1++)
                {
                    for(int dj2 = -1; dj2 <= 1; dj2++)
                    {
                        int value = 0;
                        if(j1 == j2) value = grid[i][j1];
                        else value = grid[i][j1] + grid[i][j2];

                        if(j1 + dj1 >= 0 && j1 + dj1 < column && j2 + dj2 >= 0 && j2 + dj2 < column)
                            value += dp[i + 1][j1 + dj1][j2 + dj2];
                        else
                            value += -1e8;

                        maxi = max(maxi, value);
                    }
                }
                dp[i][j1][j2] = maxi;
            }
        }
    }

    return dp[0][0][column - 1];
}


// TC : O(row*column*column)
// SC: O(column*column)
int spaceOptimization(int row, int column, vector<vector<int>>& grid)
{
    vector<vector<int>> front(column, vector<int>(column, 0));
    vector<vector<int>> current(column, vector<int>(column, 0));

    for(int j1 = 0; j1 < column; j1++)
    {
        for(int j2 = 0; j2 < column; j2++)
        {
            if(j1 == j2)
            {
                front[j1][j2] = grid[row - 1][j1];
            }
            else
            {
                front[j1][j2] = grid[row - 1][j1] + grid[row - 1][j2];
            }
        }
    }


    for(int i = row - 2; i >= 0; i--)
    {
        for(int j1 = 0; j1 < column; j1++)
        {
            for(int j2 = 0; j2 < column; j2++)
            {
                int maxi = -1e8;
                for(int dj1 = -1; dj1 <= 1; dj1++)
                {
                    for(int dj2 = -1; dj2 <= 1; dj2++)
                    {
                        int value = 0;
                        if(j1 == j2) value = grid[i][j1];
                        else value = grid[i][j1] + grid[i][j2];

                        if(j1 + dj1 >= 0 && j1 + dj1 < column && j2 + dj2 >= 0 && j2 + dj2 < column)
                            value += front[j1 + dj1][j2 + dj2];
                        else
                            value += -1e8;

                        maxi = max(maxi, value);
                    }
                }
                current[j1][j2] = maxi;
            }
        }
        front = current;
    }

    return front[0][column - 1];
}


int main()
{
    vector<vector<int>> grid = {{2, 3, 1, 2},
                                {3, 4, 2, 2},
                                {5, 6, 3, 5}};

    cout << "Grid :\n";
    for(int i = 0; i < grid.size(); i++)
    {
        for(int j = 0; j < grid[i].size(); j++)
        {
            cout << grid[i][j] << " ";
        }
        cout << "\n";
    }

    cout << "\nMaximum Chocolates grabbed by Alice and Bob together via recursion: " << recursion(grid.size(), grid[0].size(), grid);
    cout << "\nMaximum Chocolates grabbed by Alice and Bob together via memoization: " << memoization(grid.size(), grid[0].size(), grid);
    cout << "\nMaximum Chocolates grabbed by Alice and Bob together via tabulation: " << tabulation(grid.size(), grid[0].size(), grid);
    cout << "\nMaximum Chocolates grabbed by Alice and Bob together via space optimization: " << spaceOptimization(grid.size(), grid[0].size(), grid);
    
    return 0;
}