#include <bits/stdc++.h>
using namespace std;

// Time Complexity : O(2^n), This is because the recursive function calls itself twice, 
//                           once for each of the previous two Fibonacci numbers. So, 
//                           the number of recursive calls grows exponentially with the input size.
// Space Complexity : O(n), This is because the recursive function uses a stack to store the function calls
int fiboRecurrence(int n)
{
    if(n <= 1) return n;

    return fiboRecurrence(n-1) + fiboRecurrence(n-2);
}


// Time Complexity : O(n), This is because the recursive function only makes 
//                          one recursive call per Fibonacci number. 
// Space Complexity : O(n), This is because the function uses a dp array to store the
//                          Fibonacci numbers that have already been calculated.
int fiboMemoization(int n, vector<int>& dp)
{
    if(n <= 1) return n;

    if(dp[n] != -1) return dp[n];

    return dp[n] = fiboMemoization(n-1, dp) + fiboMemoization(n-2, dp);
}


// Time Complexity : O(n), This is because the function only makes a single pass 
//                         through the array, and each iteration takes a constant amount of time.
// Space Complexity : O(n), This is because the function needs to store the array of Fibonacci numbers, 
//                          which will have a size of n.
int fibonacciTabulation(int n)
{
    if(n <= 1) return n;

    int fib[n];
    fib[0] = 0;
    fib[1] = 1;

    for(int i = 2; i <= n; i++)
    {
        fib[i] = fib[i-1] + fib[i-2];
    }

    return fib[n];
}


// Time Complexity : O(n)
// Space Complexity : O(1)
int fiboOptimal(int n)
{
    if(n <= 1) return n;

    int prev2 = 0, prev1 = 1, currTerm;
    for(int i = 2; i <= n; i++)
    {
        currTerm = prev1 + prev2;
        prev2 = prev1;
        prev1 = currTerm;
    }
    return prev1;
}

int main()
{
    int n;
    cout << "Enter the term : ";
    cin >> n;

    vector<int> dp(n+1, -1);

    cout << "\n" << n << "th Fibonacci term via recurrence: " << fiboRecurrence(n);
    cout << "\n" << n << "th Fibonacci term via Memoization: " << fiboMemoization(n, dp);
    cout << "\n" << n << "th Fibonacci term via tabulation: " << fibonacciTabulation(n);
    cout << "\n" << n << "th Fibonacci term via Optimal: " << fiboOptimal(n);

    return 0;
}