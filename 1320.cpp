#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

class Solution {
    int getDist(int a, int b) {
        if (a == 26) return 0; // Unused finger cost is 0
        return abs(a / 6 - b / 6) + abs(a % 6 - b % 6);
    }

public:
    int minimumDistance(string word) {
        // dp[other] stores the min distance where the other finger is at position 'other' (26 = unused)
        vector<int> dp(27, 0);

        for (int i = 0; i < word.length() - 1; ++i) {
            int prev = word[i] - 'A';
            int curr = word[i + 1] - 'A';
            
            vector<int> next_dp(27, 1e9);

            for (int other = 0; other <= 26; ++other) {
                if (dp[other] == 1e9) continue;

                // Option 1: Move finger from 'prev' to 'curr'
                next_dp[other] = min(next_dp[other], dp[other] + getDist(prev, curr));

                // Option 2: Move finger from 'other' to 'curr' (prev becomes the new 'other')
                next_dp[prev] = min(next_dp[prev], dp[other] + getDist(other, curr));
            }

            dp = next_dp;
        }

        return *min_element(dp.begin(), dp.end());
    }
};