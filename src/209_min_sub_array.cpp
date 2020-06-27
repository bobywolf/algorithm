//
// Created by wangxiaobo on 2020/6/27.
//
#include <utils.h>

// sliding window
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if (0 == s || nums.empty()) {
            return 0;
        }
        int windowBegin = 0, windowEnd = 0;
        int sum = 0, minLen = INT_MAX;
        for (; windowEnd < nums.size(); windowEnd++) {
            sum += nums[windowEnd];
            while (sum >= s) {
                minLen = min(minLen, windowEnd - windowBegin + 1);
                sum -= nums[windowBegin++];
            }
        }
        return (minLen == INT_MAX) ? 0 : minLen;
    }
};

TEST(_0209, MinSubArrayLen) {
    Solution sln;

    vector<int> case1 = {2, 3, 1, 2, 4, 3};
    ASSERT_EQ(sln.minSubArrayLen(7, case1), 2);
}