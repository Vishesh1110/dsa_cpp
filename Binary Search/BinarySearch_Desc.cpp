#include <bits/stdc++.h>
using namespace std;

// Only Works for data sorted in Descending order
int firstOccurence(int arr[], int n, int key)
{
    int low = 0, high = n-1;

    while(low <= high)
    {
        int mid = low + (high - low)/2;
        if(key < arr[mid])
        {
            low = mid + 1;
        }
        else if(key > arr[mid])
        {
            high = mid - 1;
        }
        else
        {
            return mid;
        }
    }
    return -1;
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
    cout << "\nEnter the Descending Sorted data :\n";
    for(i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "Enter the key to be searched = ";
    cin >> key;

    if(firstOccurence(arr, n, key) == -1)
    {
        cout << "\nElement Not Found.";
    }
    else
    {
        cout << "\nElement found at index = " << firstOccurence(arr, n, key);
    }
    return 0;
}