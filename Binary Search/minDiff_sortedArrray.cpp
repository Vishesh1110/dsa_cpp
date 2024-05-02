// Minimum Difference Array in a Sorted Array:
// arr[] = {1, 3, 8, 10, 15}
// key = 12

// Absolute diff = {11, 9, 4, 2, 3}
// min = 2
// answer = 10 

#include <bits/stdc++.h>
using namespace std;

int binarySearch(int arr[], int key, int n)
{
    int low = 0, high = n-1;

    while(low <= high)
    {
        int mid = low + (high - low)/2;

        if(key == arr[mid])
            return arr[mid];
        else if(key < arr[mid])
            high = mid -1;
        else
            low = mid + 1;
    }

    if(abs(arr[low] - key) < abs(arr[high] - key))
        return arr[low];
    else if(abs(arr[low] - key) > abs(arr[high] - key))
        return arr[high];
    else
        return arr[low];
}

int main()
{
    int arr[] = {1, 3, 8, 10, 15};
    int n = sizeof(arr)/sizeof(arr[0]);

    int key = 12;

    int minDiff = binarySearch(arr, key, n);

    cout << "Mininmum Absolute Difference = " << minDiff;

    return 0;
}