// Infinite Binary Sorted Array:
// arr[] = {0, 0, 0, 0, 0, 0, 0, 1, 1, 1}
// Index of first 1 = 7

#include <bits/stdc++.h>
using namespace std;

int firstOccurence(int arr[], int low, int high, int key)
{
    int res = 0;    //Using res variable to store the index of first variable

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

int main()
{
    int arr[] = {0, 0, 0, 0, 0, 0, 0, 1, 1, 1};
    int key = 1;

    int low = 0, high = 1;
    while(key > arr[high])
    {
        low = high;
        high *= 2;
    }

    int pos = firstOccurence(arr, low, high, key);

    cout << "First Occurence of 1 = " << pos;

    return 0;
}