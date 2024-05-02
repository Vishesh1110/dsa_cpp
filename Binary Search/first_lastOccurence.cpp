#include <bits/stdc++.h>
using namespace std;

// Only Works for data sorted in Ascending order
// 6  12
// 8, 9, 10, 12, 12, 12
int firstOccurence(int arr[], int n, int key)
{
    int low = 0, high = n-1, res = -1;

    while(low <= high)
    {
        int mid = low + (high - low)/2;
        if(key < arr[mid])
        {
            high = mid - 1;
        }
        else if(key > arr[mid])
        {
            low = mid + 1;
        }
        else
        {
            res = mid;
            high = mid - 1;
        }
    }
    return res;
}

int lastOccurence(int arr[], int n, int key)
{
    int low = 0, high = n-1, res = -1;

    while(low <= high)
    {
        int mid = low + (high - low)/2;
        if(key < arr[mid])
        {
            high = mid - 1;
        }
        else if(key > arr[mid])
        {
            low = mid + 1;
        }
        else
        {
            res = mid;
            low = mid + 1;
        }
    }
    return res;
}

int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);
    
    int n;
    cout << "Enter the size of the array = ";
    cin >> n;

    int arr[n], i, key;
    cout << "\nEnter the Ascending Sorted data :\n";
    for(i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "Enter the key to be searched = ";
    cin >> key;

    int first = firstOccurence(arr, n, key);
    if(first == -1)
    {
        cout << "\nElement Not Found.";
    }
    else
    {
        cout << "\nFirst Occurence found at index = " << first;
    }

    int last = lastOccurence(arr, n, key);
    if(last == -1)
    {
        cout << "\nElement Not Found.";
    }
    else
    {
        cout << "\nLast Occurence found at index = " << last;
        cout << "\nCount of " << key << " in the array = " << (last - first + 1);
    }
    // int lb = lower_bound(arr, arr+n, key)- arr;
    // cout << lb << "\n";
    return 0;
}