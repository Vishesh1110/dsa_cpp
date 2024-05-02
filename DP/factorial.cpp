#include <bits/stdc++.h>
using namespace std;

// We are using a 1D array to store the factorials of previous numbers
// in ordr to use them int further calculations to avoid calculating it again
long long factorial(int n)
{
    long long fact[n+1];
    fact[0] = 1;
    fact[1] = 1;

    for(int i = 2; i <= n; i++)
    {
        fact[i] = i*fact[i-1];
    }

    return fact[n];
}

int main()
{
    int n;
    cout << "Enter a number : ";
    cin >> n;

    cout << "\nFactorial of " << n << " : " << factorial(n);

    return 0;
}