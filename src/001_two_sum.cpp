/*
* @Author: wangxiaobo
* @Date:   2015-01-03 11:35:18
* @Last Modified by:   wangxiaobo
* @Last Modified time: 2015-01-03 12:08:21
*/
#include <utils.h>

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int> indices;
        unordered_map<int, size_t> indices_map(numbers.size() / 2);
        for (size_t i = 0; i < numbers.size(); i++) {
            indices_map[numbers[i]] = i;
        }
        for (size_t i = 0; i < numbers.size(); i++) {
            int another = target - numbers[i];
            if (indices_map.count(another) > 0) {
                size_t j = indices_map[another];
                if (i != j) {
                    if (i < j) {
                        indices.push_back(i);
                        indices.push_back(j);
                    } else if (i > j) {
                        indices.push_back(j);
                        indices.push_back(i);
                    }
                    break;
                }
            }
        }
        return indices;
    }
};

TEST(_0001, TwoSum) {
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    Solution s;

    vector<int> res = s.twoSum(nums, target);
//    if (!res.empty()) {
//        cout << "index1=" << res[0] << ", index2=" << res[1] << endl;
//    } else {
//        cout << "not found" << endl;
//    }
    ASSERT_TRUE(res.size() == 2 && (res[0] == 0) && (res[1] == 1));

    target = 6;
    vector<int> case2 = {3, 2, 4};
    res = s.twoSum(case2, target);
    ASSERT_TRUE(res.size() == 2 && (res[0] == 1) && (res[1] == 2));
}
