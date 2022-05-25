#include <utils.h>

class Solution {
public:
    int fib(int n) {
        if (n <= 0) {
            return 0;
        }
        if (n == 1 || n == 2) {
            return 1;
        }
        int prev = 1;
        int cur = 1;
        int sum = 0;
        for (int i = 3; i <= n; i++) {
            sum = prev + cur;
            prev = cur;
            cur = sum;
        }
        return cur;
    }
};

TEST(_0509, fib) {
    Solution s;
    ASSERT_EQ(s.fib(3), 2);
}
