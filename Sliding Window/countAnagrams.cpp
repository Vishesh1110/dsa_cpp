#include <bits/stdc++.h>
using namespace std;

int countAnagrams(string txt, string pat)
{
    unordered_map<char, int> ump;
    int ans = 0;

    for(auto it : pat)
    {
        ump[it]++;
    }

    // Count of distinct characters 
    int count = ump.size();
    // Size of window
    int k = pat.size();
    int start = 0, end = 0;

    while(end < txt.length())
    {
        if(ump.find(txt[end]) != ump.end())
        {
            ump[txt[end]]--;
            if(ump[txt[end]] == 0)
            {
                count--;
            }
        }

        if(end-start+1 < k)
        {
            end++;
        }
        else if(end-start+1 == k)
        {
            if(count == 0)
            {
                ans++;
            }

            if(ump.find(txt[start]) != ump.end())
            {
                ump[txt[start]]++;
                if(ump[txt[start]] == 1)
                {
                    count++;
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

    // aabaabaa
    // aaba
    string txt = "forxxorfxdofr";
    string pat = "for";

    cout << "\nTotal Anagrams : " << countAnagrams(txt, pat);
    return 0;
}