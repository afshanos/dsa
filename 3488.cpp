#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cmath>

class Solution {
public:
    std::vector<int> solveQueries(std::vector<int>& nums, std::vector<int>& queries) {
        int n = nums.size();
        std::unordered_map<int, std::vector<int>> pos_map;

        // Group indices by value
        for (int i = 0; i < n; ++i) {
            pos_map[nums[i]].push_back(i);
        }

        std::vector<int> answer;
        answer.reserve(queries.size());

        auto getCircularDist = [n](int i, int j) {
            int d = std::abs(i - j);
            return std::min(d, n - d);
        };

        for (int q : queries) {
            const auto& vec = pos_map[nums[q]];
            int sz = vec.size();

            // No other index contains nums[q]
            if (sz <= 1) {
                answer.push_back(-1);
                continue;
            }

            // Find current index position using binary search
            auto it = std::lower_bound(vec.begin(), vec.end(), q);
            int idx = std::distance(vec.begin(), it);

            // Left and Right neighbors in circular fashion
            int left = vec[(idx - 1 + sz) % sz];
            int right = vec[(idx + 1) % sz];

            int minDist = std::min(getCircularDist(q, left), getCircularDist(q, right));
            answer.push_back(minDist);
        }

        return answer;
    }
};