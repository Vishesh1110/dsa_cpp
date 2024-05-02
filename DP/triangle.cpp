#include <bits/stdc++.h>
using namespace std;


// TC : O(2 ^ (row*(row+1)))
// SC : O(Path_length) (recursive stack space)
int findTrianglePathSumR(int i, int j, int row, vector<vector<int>>& triangle)
{
    if(i == row) return triangle[i][j];

    int down = triangle[i][j] + findTrianglePathSumR(i + 1, j, row, triangle);
    int diag = triangle[i][j] + findTrianglePathSumR(i + 1, j + 1, row, triangle);

    return min(down, diag);
}
int recursion(vector<vector<int>>& triangle) {
    int row = triangle.size();
    // int column = triangle[row-1].size();
    return findTrianglePathSumR(0, 0, row - 1, triangle);
}


// TC : O(row*(row + 1))
// SC : O(row*(row + 1)) + O(Path_length)
int findTrianglePathSumM(int i, int j, int row, int column, vector<vector<int>>& triangle, vector<vector<int>>& dp)
{
    if(i == row) return triangle[i][j];

    if(dp[i][j] != -1) return dp[i][j];

    int down = triangle[i][j] + findTrianglePathSumM(i + 1, j, row, column, triangle, dp);
    int diag = triangle[i][j] + findTrianglePathSumM(i + 1, j + 1, row, column, triangle, dp);

    return dp[i][j] = min(down, diag);
}
int memoization(vector<vector<int>>& triangle) {
    int row = triangle.size();
    int column = triangle[row-1].size();
    vector<vector<int>> dp(row, vector<int>(column, -1));
    return findTrianglePathSumM(0, 0, row - 1, column - 1, triangle, dp);
}


// TC : O(row*(row + 1))
// SC : O(row*(row + 1))
int tabulation(vector<vector<int>>& triangle)
{
    int row = triangle.size();
    int column = triangle[row-1].size();
    vector<vector<int>> dp(row, vector<int>(column, 0));

    for(int i = 0; i < row; i++)
    {
        dp[row - 1][i] = triangle[row - 1][i];
    }

    for(int i = row - 2; i >= 0; i--)
    {
        for(int  j = i; j >= 0; j--)
        {
            int down = triangle[i][j] + dp[i+1][j];
            int diag = triangle[i][j] + dp[i+1][j+1];

            dp[i][j] = min(down, diag);
        }
    }

    return dp[0][0];
}

// TC : O(row*(row + 1))
// SC : O(column)
int spaceOptimization(vector<vector<int>>& triangle)
{
    int row = triangle.size();

    vector<int> front(row, 0), current(row, 0);
    for(int i = row-1; i >= 0; i--)
    {
        front[i] = triangle[row - 1][i];
    }

    for(int i = row - 2; i >= 0; i--)
    {
        for(int  j = i; j >= 0; j--)
        {
            int down = triangle[i][j] + front[j];
            int diag = triangle[i][j] + front[j+1];

            current[j] = min(down, diag);
        }
        front = current;
    }

    return front[0];
}

int main()
{
    vector<vector<int>> triangle = {{2},
                                    {3, 4},
                                    {6, 5, 7},
                                    {4, 1, 8, 3}};

    int row = triangle.size();
    int column = triangle[row - 1].size();

    cout << "Triangle :\n";
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < triangle[i].size(); j++)
        {
            cout << triangle[i][j] << " ";
        }
        cout << "\n";
    }

    cout << "\nMinimum Path Sum via recursion: " << recursion(triangle);
    cout << "\nMinimum Path Sum via memoization: " << memoization(triangle);
    cout << "\nMinimum Path Sum via tabulation: " << tabulation(triangle);
    cout << "\nMinimum Path Sum via Space Optimization: " << spaceOptimization(triangle);

    return 0;
}