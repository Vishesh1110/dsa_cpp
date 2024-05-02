// A child goes to a toy shop to purchase toys. His mother keeps 2 conditions that  
// he will purchase only 2 types of toys(represented by alphabets in a string) and 
// will buy toys continously. Return the maximum number of toys that can be purchased.

// toys = "abaccab"
// maxToys = 4

#include <bits/stdc++.h>
using namespace std;

int maxToysPurchased(string toys)
{
    int windowStart = 0, windowEnd = 0, maxToys = 0;

    unordered_map<int, int> ump;

    while(windowEnd < toys.length())
    {
        ump[toys[windowEnd]]++;

        if(ump.size() <= 2)
        {
            maxToys = max(maxToys, windowEnd - windowStart + 1);
        }
        else if(ump.size() > 2)
        {
            while(ump.size() > 2)
            {
                ump[toys[windowStart]]--;
                if(ump[toys[windowStart]] == 0)
                {
                    ump.erase(toys[windowStart]);
                }
                windowStart++;
            }
        }
        windowEnd++;
    }
    return maxToys;
}

int main()
{
    string toys = "abaccab";
    cout << "Types of toys : " << toys;

    int maxToys = maxToysPurchased(toys);
    cout << "\nMaximum toys purchased : " << maxToys;

    return 0;
}