#include<bits/stdc++.h>
using namespace std;

// This approach will have time complexity O(row+col)
bool search1(vector<vector<int>>& matrix, int row, int col, int target)
{
    int rowCount = 0, colCount = col-1;
    while(rowCount >= 0 && rowCount < row && colCount >= 0 && colCount < col)
    {
        if(matrix[rowCount][colCount] == target)
        {
            return true;
        }
        else if(matrix[rowCount][colCount] > target)
        {
            colCount--;
        }
        else if(matrix[rowCount][colCount] < target)
        {
            rowCount++;
        }
    }
    return false;
}

// This approach will have time complexity O(log(row+col))
bool search2(vector<vector<int>>& matrix, int row, int col, int target)
{
    int low = 0, high = row*col - 1;
    while(low <= high)
    {
        int mid = low + (high - low)/2;
        if(matrix[mid/col][mid%col] == target)
        {
            return true;
        }
        else if(matrix[mid/col][mid%col] < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return false;
}

int main()
{
    int row, col;
    cout << "Enter the row and column size of the matrix :\n";
    cin >> row >> col;
    vector<vector<int>> matrix;
    vector<int> rowEl;

    cout << "Enter the matrix elements :\n";
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            int ele;
            cin >> ele;
            rowEl.push_back(ele);
        }
        matrix.push_back(rowEl);
        rowEl.clear();
    }

    cout << "\nMatrix Elements\n";
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << "\n";
    }

    int target;
    cout << "\nEnter the target to be searched : ";
    cin >> target;

    if(search1(matrix, row, col, target))
    {
        cout << "\nElement Found.";
    }
    else
    {
        cout << "\nNot Found.";
    }

    if(search2(matrix, row, col, target))
    {
        cout << "\nElement Found.";
    }
    else
    {
        cout << "\nNot Found.";
    }

    return 0;
}