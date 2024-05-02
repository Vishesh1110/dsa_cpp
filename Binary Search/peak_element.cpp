// Peak element:
// An element is said to be Peak element if its greater than its neighbour(s)

// For example:
// arr[] = {5, 10, 20, 15}

// answer:
// 3 (index of 20 ,i.e., Peak element)

// OR
// arr[] = {10, 20, 30, 40, 50}

// answer:
// 4 (index of 50 ,i.e., Peak element)

#include <bits/stdc++.h>
using namespace std;

int binarySearch(int arr[], int n)
{
    int low = 0, high = n-1;
    
    while(low <= high)
    {
        int mid = low + (high - low)/2;
        if(mid > 0 && mid < n-1)
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
    int arr[] = {0, 2, 1, 0};
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