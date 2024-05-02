#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector<string> grayCodes;
    grayCodes.push_back("0");
    grayCodes.push_back("1");

    for(int i = 2; i <= n; i++) {
        int size = grayCodes.size();
        for(int i = size - 1; i >= 0; i--) 
            grayCodes.push_back(grayCodes[i]);
        for(int i = 0; i < size; i++) {
            grayCodes[i] = "0" + grayCodes[i];
            grayCodes[i + size] = "1" + grayCodes[i + size];
        }
    }

    for(auto it : grayCodes)
        cout << it << " ";

    return 0;
}