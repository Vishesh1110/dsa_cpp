// Given an integer array nums, return the length of the longest strictly increasing subsequence.
 

// Example 1:

// Input: nums = [10,9,2,5,3,7,101,18]
// Output: 4
// Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.


// Example 2:

// Input: nums = [0,1,0,3,2,3]
// Output: 4


// Example 3:

// Input: nums = [7,7,7,7,7,7,7]
// Output: 1


#include <bits/stdc++.h>
using namespace std;


// TC : O(2 ^ n)
// SC : O(n)
int recursionUtil(int index, int prevIndex, int n, vector<int>& nums) {
    if(index == n)
        return 0;

    int len = recursionUtil(index + 1, prevIndex, n, nums);
    if(prevIndex == -1 || nums[index] > nums[prevIndex])
        len = max(len, 1 + recursionUtil(index + 1, index, n, nums));

    return len;
}
int recursion(vector<int>& nums) {
    return recursionUtil(0, -1, nums.size(), nums);
}


// TC : O(n * n)
// SC : O(n * n) + O(n)
int memoizationUtil(int index, int prevIndex, int n, vector<int>& nums, vector<vector<int>>& dp) {
    if(index == n)
        return 0;

    if(dp[index][prevIndex + 1] != -1)
        return dp[index][prevIndex + 1];

    int len = memoizationUtil(index + 1, prevIndex, n, nums, dp);
    if(prevIndex == -1 || nums[index] > nums[prevIndex])
        len = max(len, 1 + memoizationUtil(index + 1, index, n, nums, dp));

    return dp[index][prevIndex + 1] = len;
}
int memoization(vector<int>& nums) {
    vector<vector<int>> dp(nums.size(), vector<int>(nums.size()+1, -1));
    return memoizationUtil(0, -1, nums.size(), nums, dp);
}


// TC : O(n * n)
// SC : O(n * n) 
int tabulation(vector<int>& nums) {
    int n = nums.size();
    vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

    for(int index = n - 1; index >= 0; index--) {
        for(int prevIndex = index - 1; prevIndex >= -1; prevIndex--) {
            int len = dp[index + 1][prevIndex + 1];
            if(prevIndex == -1 || nums[index] > nums[prevIndex])
                len = max(len, 1 + dp[index + 1][index + 1]);

            dp[index][prevIndex + 1] = len;
        }
    }
    return dp[0][-1+1];
}


// TC : O(n * n)
// SC : O(2 * n) 
int spaceOptimization1(vector<int>& nums) {
    int n = nums.size();
    vector<int> curr(n+1, 0), next(n+1, 0);

    for(int index = n - 1; index >= 0; index--) {
        for(int prevIndex = index - 1; prevIndex >= -1; prevIndex--) {
            int len = next[prevIndex + 1];
            if(prevIndex == -1 || nums[index] > nums[prevIndex])
                len = max(len, 1 + next[index + 1]);

            curr[prevIndex + 1] = len;
        }
        next = curr;
    }
    return next[-1+1];
}


// TC : O(n * n)
// SC : O(n) 
int spaceOptimization2(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n, 1);

    for(int index = 0; index < n; index++) 
        for(int prevIndex = 0; prevIndex <= index; prevIndex++) 
            if(nums[prevIndex] < nums[index])
                dp[index] = max(dp[index], 1 + dp[prevIndex]);

    return *max_element(dp.begin(), dp.end());
}



// TC : O(n * n)
// SC : O(n) 
vector<int> printLIS(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n, 1), hash(n);

    int maxi = 1, lastIndex = 0;
    for(int index = 0; index < n; index++) {
        hash[index] = index;
        for(int prevIndex = 0; prevIndex <= index; prevIndex++) {
            if(nums[prevIndex] < nums[index] && 1 + dp[prevIndex] > dp[index]) {
                dp[index] = 1 + dp[prevIndex];
                hash[index] = prevIndex;
            }
        }
        if(dp[index] > maxi) {
            maxi = dp[index];
            lastIndex = index;
        }
    }

    vector<int> lis;
    lis.push_back(nums[lastIndex]);
    while(hash[lastIndex] != lastIndex) {
        lastIndex = hash[lastIndex];
        lis.push_back(nums[lastIndex]);
    }
    reverse(lis.begin(), lis.end());
    return lis;
}


// TC : O(nlogn)
// SC : O(len(LIS))
int binarySearch(vector<int>& nums) {
    vector<int> temp;
    temp.push_back(nums[0]);
    int len = 1;

    for(int i = 1; i < nums.size(); i++) {
        if(nums[i] > temp.back()) {
            temp.push_back(nums[i]);
            len++;
        }
        else {
            int index = lower_bound(temp.begin(), temp.end(), nums[i]) - temp.begin();
            temp[index] = nums[i];
        }
    }
    return len;
}


int main() {
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    cout << "\nArray :\n";
    for(int i = 0; i < nums.size(); i++)
        cout << nums[i] << " ";

    cout << "\nLongest Increasing Subsequence : ";
    vector<int> lis = printLIS(nums);
    for(auto it : lis) 
        cout << it << " ";
    cout << "\n";

    cout << "\n\nLength of LIS via recursion : " << recursion(nums) << "\n";
    cout << "Length of LIS via memoization : " << memoization(nums) << "\n";
    cout << "Length of LIS via tabulation : " << tabulation(nums) << "\n";
    cout << "Length of LIS via spaceOptimization1 : " << spaceOptimization1(nums) << "\n";
    cout << "Length of LIS via spaceOptimization2 : " << spaceOptimization2(nums) << "\n";
    cout << "Length of LIS via binarySearch : " << binarySearch(nums) << "\n";

    return 0;
}