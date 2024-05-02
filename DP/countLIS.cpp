// Given an integer array nums, return the number of longest increasing subsequences.

// Notice that the sequence has to be strictly increasing.

 

// Example 1:

// Input: nums = [1,3,5,4,7]
// Output: 2
// Explanation: The two longest increasing subsequences are [1, 3, 4, 7] and [1, 3, 5, 7].
// Example 2:

// Input: nums = [2,2,2,2,2]
// Output: 5
// Explanation: The length of the longest increasing subsequence is 1, and there are 5 increasing subsequences of length 1, so output 5.


#include <bits/stdc++.h>
using namespace std;

int findNumberOfLIS(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n, 1), count(n, 1);
    int maxLen = 1;
    for(int index = 0; index < n; index++) {
        for(int prevIndex = 0; prevIndex < index; prevIndex++) {
            if(nums[prevIndex] < nums[index]) {
                if(dp[prevIndex] + 1 > dp[index]) {
                    dp[index] = 1 + dp[prevIndex];
                    count[index] = count[prevIndex];
                }
                else if(dp[prevIndex] + 1 == dp[index]) {
                    count[index] += count[prevIndex];
                }
            }
        }
        maxLen = max(maxLen, dp[index]);
    }
    int maxLIS = 0;
    for(int i = 0; i < n; i++)
        if(dp[i] == maxLen)
            maxLIS += count[i];
    
    return maxLIS;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> nums = {1, 3, 5, 4, 7};
    cout << "\nArray:\n";
    for(int i = 0; i < nums.size(); i++)
        cout << nums[i] << " ";

    cout << "\n\nCount of Longest Increasing Subsequence : " << findNumberOfLIS(nums) << "\n";

    return 0;
}