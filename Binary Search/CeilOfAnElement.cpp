// Ceil of an element:
// If an element is present in an array and it is an integer then it will be the ceil 
// but if the element is not present in the array then the ceil is equal to the smallest element 
// greater than the number. 

// For ex:
// arr[] = {1, 2, 3, 4, 8, 10, 10, 12, 14}
// key = 5
// Since 5 is absent then its Ceil will be 8.

#include <bits/stdc++.h>
using namespace std;

int binarySearch1(int arr[], int key, int n)
{
    int low = 0, high = n-1, res;

    while(low <= high)
    {
        int mid = low + (high - low)/2;

        if(key < arr[mid])  //Before moving to the left subarray, we have to store the result as ceil
        {
            res = arr[mid];
            high = mid - 1;
        }
        else if(key > arr[mid])
        {
            low = mid + 1;
        }
        else
        {
            return arr[mid];
        }
    }
    return res;
}

// OR Soln2

int binarySearch2(int arr[], int key, int n)
{
    int low = 0, high = n-1;

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
            return arr[mid];
        }
    }
    return arr[low];
}

int main()
{
    int arr[] = {1, 2, 3, 4, 8, 10, 10, 12, 14};
    int n = sizeof(arr)/sizeof(arr[0]);
    int key = 5;

    cout << "1. Ceil of " << key << " is = " << binarySearch1(arr, key, n); 
    cout << "\n2. Ceil of " << key << " is = " << binarySearch2(arr, key, n); 

    return 0;
}