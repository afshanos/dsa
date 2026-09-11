#include <vector>
#include <unordered_map>
#include <algorithm>
#include <climits>

class Solution {
    int reverseNum(int x) {
        int rev = 0;
        while (x > 0) {
            rev = rev * 10 + (x % 10);
            x /= 10;
        }
        return rev;
    }

public:
    int minMirrorPairDistance(std::vector<int>& nums) {
        std::unordered_map<int, int> rev_map; // maps reverse(nums[i]) -> latest index i
        int min_dist = INT_MAX;

        for (int j = 0; j < nums.size(); ++j) {
            // Check if nums[j] matches any previous reverse(nums[i])
            if (rev_map.count(nums[j])) {
                min_dist = std::min(min_dist, j - rev_map[nums[j]]);
            }

            // Record/update reverse of current number for future elements
            int rev = reverseNum(nums[j]);
            rev_map[rev] = j;
        }

        return min_dist == INT_MAX ? -1 : min_dist;
    }
};