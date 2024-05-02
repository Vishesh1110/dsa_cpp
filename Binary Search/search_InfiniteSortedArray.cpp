// Infinitely Sorted Array:
// It is an array whose size can't be determined.
// In any coding platform, infinite array is given but can be asked in face to face interview


#include <bits/stdc++.h>
using namespace std;

int binarySearch(int arr[], int low, int high, int key)
{
    while(low <= high)
    {
        int mid = low + (high - low)/2;

        if(key == arr[mid])
            return mid;
        else if(key < arr[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
    int key = 7;

    int low = 0, high = 1;
    while(key > arr[high])
    {
        low = high;
        high *= 2;
    }

    int pos = binarySearch(arr, low, high, key);

    if(pos == -1)
        cout << "Element Not Found.";
    else
        cout << "ELement Found at " << pos;
    return 0;
}