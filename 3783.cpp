#include <cmath>
#include <cstdlib>

class Solution {
public:
    int mirrorDistance(int n) {
        int original = n;
        int reversed = 0;

        while (n > 0) {
            reversed = reversed * 10 + (n % 10);
            n /= 10;
        }

        return std::abs(original - reversed);
    }
};