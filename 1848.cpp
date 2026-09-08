#include <vector>
#include <cmath>
#include <algorithm>

class Solution {
public:
    int getMinDistance(std::vector<int>& nums, int target, int start) {
        int min_dist = nums.size();
        
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == target) {
                min_dist = std::min(min_dist, std::abs(i - start));
            }
        }
        
        return min_dist;
    }
};