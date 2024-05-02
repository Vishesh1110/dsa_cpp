// Find the length of longest substring having K unique characters
// str = "aabacbebebe", k = 3 (number of unique characters)
// maxLength = 7 (substring = "cbebebe")

#include <bits/stdc++.h>
using namespace std;

int longestSubstring(string str, int k)
{
    int windowStart = 0, windowEnd = 0, maxLength = 0;
    unordered_map<char, int> ump;

    while(windowEnd < str.length())
    {
        ump[str[windowEnd]]++;

        if(ump.size() < k)
        {
            windowEnd++;
        }
        else if(ump.size() == k)
        {
            maxLength = max(maxLength, windowEnd - windowStart + 1);
            windowEnd++;
        }
        else if(ump.size() > k)
        {
            while(ump.size() > k)
            {
                ump[str[windowStart]]--;
                if(ump[str[windowStart]] == 0)
                {
                    ump.erase(str[windowStart]);
                }
                windowStart++;
            }
            windowEnd++;
        }
    }
    return maxLength;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str = "aabacbebebe";
    int k = 3;

    cout << "String = " << str;

    int maxLength = longestSubstring(str, k);

    cout << "\nLength of longest substring with " << k << " unique characters : " << maxLength;

    return 0;
}