#include <bits/stdc++.h>
using namespace std;

vector<int> firstNegative(int arr[], int n, int k)
{
    vector<int> ans;
    deque<int> dq;

    int start = 0, end = 0;
    
    while(end < n)
    {
        if(arr[end] < 0)
        {
            dq.push_back(arr[end]);
        }

        if(end-start+1 < k)
        {
            end++;
        }
        else if(end-start+1 == k)
        {
            if(dq.empty())
            {
                ans.push_back(0);
            }
            else
            {
                ans.push_back(dq.front());
                if(arr[start] < 0)
                {
                    dq.pop_front();
                }
            }
            start++;
            end++;
        }
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int arr[] = {12, -1, -7, 8, -15, 30, 16, 28};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 3;

    vector<int> ans = firstNegative(arr, n, k);
    cout << "\nList of 1st Negative numbers in size of window of " << k << ":\n";

    for(auto it : ans)
    {
        cout << it << " ";
    }

    return 0;
}