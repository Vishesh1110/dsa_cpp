// Given an array of positive integers. Find the maximum length of Bitonic subsequence. 
// A subsequence of array is called Bitonic if it is first strictly increasing, then strictly decreasing.
 

// Example 1:

// Input: nums = [1, 2, 5, 3, 2]
// Output: 5
// Explanation: The sequence {1, 2, 5} is
// increasing and the sequence {3, 2} is 
// decreasing so merging both we will get 
// length 5.
// Example 2:

// Input: nums = [1, 11, 2, 10, 4, 5, 2, 1]
// Output: 6
// Explanation: The bitonic sequence 
// {1, 2, 10, 4, 2, 1} has length 6.


#include <bits/stdc++.h>
using namespace std;


int LongestBitonicSequence(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp1(n, 1), dp2(n, 1);
    
    for(int index = 0; index < n; index++) 
        for(int prevIndex = 0; prevIndex < index; prevIndex++) 
            if(nums[prevIndex] < nums[index] && dp1[index] < 1 + dp1[prevIndex])
                dp1[index] = 1 + dp1[prevIndex];
                
    int len = 0;
    for(int index = n-1; index >= 0; index--) {
        for(int prevIndex = n-1; prevIndex > index; prevIndex--) {
            if(nums[prevIndex] < nums[index] && dp2[index] < 1 + dp2[prevIndex]) {
                dp2[index] = 1 + dp2[prevIndex];
            }
        }
        len  = max(len, dp1[index] + dp2[index] - 1);
    }
    
    return len; 
}


int main() {
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> nums = {1, 2, 5, 3, 2};
    cout << "\nArray :\n";
    for(int i = 0; i < nums.size(); i++)
        cout << nums[i] << " ";

    cout << "\nLongest Bitonic Subsequences : " << LongestBitonicSequence(nums) << "\n";

    return 0;
}