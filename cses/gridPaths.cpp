#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;

long long totalPaths(int row, int column, vector<vector<char>>& grid, int n, vector<vector<int>>& dp) {
    if(row == n-1 && column == n-1)
        return 1;
    if(row < 0 || row >= n || column < 0 || column >= n)
        return 0;
    
    if(dp[row][column] != -1)
        return dp[row][column];

    long long right = 0, down = 0;
    if(column + 1 >= 0 && column + 1 < n && grid[row][column + 1] != '*')
        right = totalPaths(row, column + 1, grid, n, dp) % mod;
    if(row + 1 >= 0 && row + 1 < n && grid[row + 1][column] != '*')
        down = totalPaths(row + 1, column, grid, n, dp) % mod;

    return dp[row][column] = (down + right) % mod;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector<vector<char>> grid(n, vector<char>(n));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> grid[i][j];


    if(n == 1) {
        if(grid[0][0] == '.')
            cout << "1";
        else if(grid[0][0] == '*')
            cout << "0";
        exit(0);
    }
    if(grid[0][0] == '*') {
        cout << "0";
        exit(0);
    }
    
    vector<vector<int>> dp(n, vector<int>(n, -1));
    cout << totalPaths(0, 0, grid, n, dp) % mod;

    return 0;
}