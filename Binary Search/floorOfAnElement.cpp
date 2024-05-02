// Floor of an element:
// If an element is present in an array and it is an integer then it will be the floor 
// but if the element is not present in the array then the floor is equal to the greatest element 
// smaller than the number.

// For ex:
// arr[] = {1, 2, 3, 4, 8, 10, 10, 12, 14}
// key = 5
// Since 5 is absent then its floor will be 4.

#include <bits/stdc++.h>
using namespace std;

int binarySearch(int arr[], int key, int n)
{
    int low = 0, high = n-1, res;

    while(low <= high)
    {
        int mid = low + (high - low)/2;

        if(key < arr[mid])
        {
            high = mid - 1;
        }
        else if(key > arr[mid])     //Before moving to the right subarray, we have to store the result as floor
        {
            res = arr[mid];
            low = mid + 1;
        }
        else
        {
            return arr[mid];
        }
    }
    return res;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 8, 10, 10, 12, 14};
    int n = sizeof(arr)/sizeof(arr[0]);
    int key = 5;

    cout << "Floor of " << key << " is = " << binarySearch(arr, key, n); 

    return 0;
}