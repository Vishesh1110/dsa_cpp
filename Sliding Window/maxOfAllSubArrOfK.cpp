// Maximum of all subarrays of size k
// {1, 3, -1, -3, 5, 3, 6, 7}, k = 3(window size)
// ans = {3, 3, 5, 5, 6, 7}

#include <bits/stdc++.h>
using namespace std;

vector<int> maxOfSubArr(int arr[], int n, int k)
{
    int windowStart = 0, windowEnd = 0;
    deque<int> dq;

    vector<int> ans;
    
    while(windowEnd < n)
    {
        while(!dq.empty() && dq.back() < arr[windowEnd])
        {
            dq.pop_back();
        }
        dq.push_back(arr[windowEnd]);

        if(windowEnd - windowStart + 1 < k)
        {
            windowEnd++;
        }
        else if(windowEnd - windowStart + 1 == k)
        {
            ans.push_back(dq.front());
            if(dq.front() == arr[windowStart])
            {
                dq.pop_front();
            }
            windowStart++;
            windowEnd++;
        }
    }

    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int arr[] = {1, 3, -1, -3, 5, 3, 6, 7};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 3;

    cout << "\nArray : \n";
    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    vector<int> ans = maxOfSubArr(arr, n, k);

    cout << "\nRequired Array : \n";
    for(auto it : ans)
    {
        cout << it << " ";
    }

    return 0;
}