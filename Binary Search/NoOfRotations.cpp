#include <bits/stdc++.h>
using namespace std;

// The number of rotations is calculated by the position of the minimum element in a Sorted array
int NoOfRotations(int arr[], int n)
{
    if(arr[0] > arr[n-1])
    {
        int low = 0, high = n-1;

        while(low <= high)
        {
            int mid = low + (high - low)/2;
            int prev = (mid + n - 1)%n;
            int next = (mid + 1)%n;

            if(arr[mid] <= arr[next] && arr[mid] <= arr[prev])
            {
                return mid;
            }
            else if(arr[0] <= arr[mid])
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
    }
    return 0;
}

int main()
{
    int n;
    cout << "Enter the size of the array = ";
    cin >> n;

    int arr[n], i, key;
    cout << "\nEnter the Sorted Rotated data :\n";
    // {11, 12, 15, 18, 2, 5, 6, 8}
    // Number of Rotations = 4 (which is also the position of minimum element in a sorted array)

    for(i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int rot = NoOfRotations(arr, n);
    cout << "\nNumber of Rotations done = " << rot;
    
    return 0;
}