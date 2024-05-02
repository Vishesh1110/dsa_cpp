#include <bits/stdc++.h>
using namespace std;

int longestSubarr(int arr[], int n, int sum)
{
    int windowStart = 0, windowEnd = 0, currentSum = 0, maxLength = 0;

    while(windowEnd < n)
    {
        currentSum += arr[windowEnd];

        if(currentSum < sum)
        {
            windowEnd++;
        }
        else if(currentSum == sum)
        {
            maxLength = max(maxLength, windowEnd - windowStart + 1);
            windowEnd++;
        }
        else if(currentSum > sum)
        {
            while(currentSum > sum)
            {
                currentSum -= arr[windowStart++];
                if(currentSum == sum)
                {
                    maxLength = max(maxLength, windowEnd - windowStart + 1);
                }
            }
            windowEnd++;
        }
    }
    return maxLength;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int arr[] = {4, 1, 1, 1, 2, 3, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    int sum = 5;

    cout << "\nArray :\n";
    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    int longestSubarray = longestSubarr(arr, n, sum);
    cout << "\nLongest Subarray with sum " << sum << " is : " << longestSubarray;

    return 0;
}