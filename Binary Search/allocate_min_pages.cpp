#include <bits/stdc++.h>
using namespace std;

bool isValid(int arr[], int books, int students, int mid)
{
    int student = 1, sum = 0;
    for(int  i = 0; i < books; i++)
    {
        sum += arr[i];
        if(sum > mid)
        {
            student++;
            sum = arr[i];
        }
        if(student > students)
        {
            return false;
        }
    }
    return true;
}

int findMinPages(int arr[], int books, int students)
{
    if(books < students)
    {
        return -1;
    }

    int low = *max_element(arr, arr+books), high = 0, res = -1;
    for(int i = 0; i < books; i++)
    {
        high += arr[i];
    }
    while(low <= high)
    {
        int mid = low + (high - low)/2;
        if(isValid(arr, books, students, mid))
        {
            res = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return res;
}

int main()
{
    int books, i, students;
    cout << "Enter the number of books : ";
    cin >> books;

    int arr[books];
    cout << "Enter the pages in each book :\n";
    for(i = 0; i < books; i++)
    {
        cin >> arr[i];
    }
    cout << "\nEnter the number of students : ";
    cin >> students;

    cout << "\nMinimum number of maximum pages : " << findMinPages(arr, books, students);
    
    return 0;
}