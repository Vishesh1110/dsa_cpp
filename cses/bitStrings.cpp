#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007

int main() {
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);

    long long n;
    cin >> n;

    long long bitStrings = pow(2, n);
    cout << bitStrings % mod;

    return 0;
}