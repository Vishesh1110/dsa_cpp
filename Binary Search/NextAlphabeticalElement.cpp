// Application of the Ceil problem with slight variation
// If the eleemnt is found then also the next alphabet has to be returned as Ceil value

// For Ex:
// char arr[] = {'a', 'c', 'f', 'h'}
// key = 'f'
// Next Alphabetical Element = 'h'

#include <bits/stdc++.h>
using namespace std;

char binarySearch(char arr[], char key, int n)
{
    int low = 0, high = n-1;
    char res = '#';

    while(low <= high)
    {
        int mid = low + (high - low);

        if(key < arr[mid])  //Before moving to the left subarray, we have to store the result as ceil
        {
            res = arr[mid];
            high = mid - 1;
        }
        else                //If the key is found or the key is greater than arr[mid] 
        {
            low = mid + 1;
        }
    }
    return res;
}

int main()
{
    char arr[] = {'a', 'c', 'f', 'h'};
    int n = sizeof(arr)/sizeof(arr[0]);
    char key = 'f';

    cout << "Ceil of " << key << " is = " << binarySearch(arr, key, n);

    return 0;
}