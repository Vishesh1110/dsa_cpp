#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;

    while(t--) {
        int a, b;
        cin >> a >> b;

        if(max(a, b) > 2 * min(a, b))
            cout << "NO\n";
        else if((a + b) % 3 == 0)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}