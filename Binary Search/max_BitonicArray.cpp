// Bitonic Array: 
// An array which is monotonically increasing to some extent and then monotonically decreasing

// For ex:
// arr[] = {1, 3, 8, 12, 4, 2}
// Values in arr[] is increasing till 2nd index and after that decreasing monotonically
// Monotonically means the array will never contain duplicate values

#include <bits/stdc++.h>
using namespace std;

int binarySearch(int arr[], int n)
{
    int low = 0, high = n-1;

    while(low <= high)
    {
        int mid = low + (high - low)/2;
        if(mid > 0 && mid < n)
        {
            if(arr[mid] > arr[mid-1] && arr[mid] > arr[mid+1])
            {
                return mid;
            }
            else if(arr[mid-1] > arr[mid])
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        else if(mid == 0)
        {
            if(arr[mid] > arr[mid+1])
            {
                return 0;
            }
            else
            {
                return 1;
            }
        }
        else if(mid == n-1)
        {
            if(arr[mid] > arr[mid-1])
            {
                return n-1;
            }
            else
            {
                return n-2;
            }
        }
    }
    return -1;
}

int main()
{
    int arr[] = {1, 3, 8, 12, 4, 2};
    int n = sizeof(arr)/sizeof(arr[0]);

    int pos = binarySearch(arr, n);

    if(pos == -1)
    {
        cout << "No Peak Element Exist.";
    }
    else
    {
        cout << "Peak Element = " << arr[pos];
    }
    
    return 0;
}