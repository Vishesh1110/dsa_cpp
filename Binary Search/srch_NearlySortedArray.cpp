#include <bits/stdc++.h>
using namespace std;

// Nearly Sorted Array

//     A[i]
//     / | \
//    /  |  \
//  i-1  i  i+1

// Ex: arr[] = {5, 10, 20, 30, 40} --> Sorted Array
// arr[] = {5, 10, 30, 20, 40}  --> Nearly Sorted Array

// We should apply MODIFIED BINARY SEARCH

int binarySearch(int arr[], int k, int n)
{
    int low = 0, high = n-1;

    while(low <= high)
    {
        int mid = low + (high - low)/2;

        if(k == arr[mid])
        {
            return mid;
        }
        else if(mid - 1 >= low && k == arr[mid-1])
        {
            return mid-1;
        }
        else if(mid + 1 <= high && k == arr[mid+1])
        {
            return mid+1;
        }
        else if(k < arr[mid])
        {
            high = mid - 2;
        }
        else if(k > arr[mid])
        {
            low = mid + 2;
        }
    }
    return -1;
}

int main()
{
    int arr[] = {5, 10, 30, 20, 40};
    int n = sizeof(arr)/sizeof(arr[0]);

    int pos = binarySearch(arr, 20, n);

    if(pos == -1)
        cout << "ELement Not Found.";
    else
        cout << "Element Found at " << pos;

    return 0;
}