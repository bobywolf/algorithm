//
// Created by wangxiaobo on 2020/6/27.
//
#include <utils.h>
#include <check_internal.h>

// sliding window
class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> medians;
        unordered_map<int, int> hash_table;
        priority_queue<int> lo;                                 // max heap
        priority_queue<int, vector<int>, greater<int> > hi;     // min heap

        int i = 0;      // index of current incoming element being processed

        // initialize the heaps
        while (i < k)
            lo.push(nums[i++]);
        for (int j = 0; j < k / 2; j++) {
            hi.push(lo.top());
            lo.pop();
        }

        while (true) {
            // get median of current window
            medians.push_back(k & 1 ? lo.top() : ((double)lo.top() + (double)hi.top()) * 0.5);

            if (i >= nums.size())
                break;                          // break if all elements processed

            int out_num = nums[i - k],          // outgoing element
            in_num = nums[i++],             // incoming element
            balance = 0;                    // balance factor

            // number `out_num` exits window
            balance += (out_num <= lo.top() ? -1 : 1);
            hash_table[out_num]++;

            // number `in_num` enters window
            if (!lo.empty() && in_num <= lo.top()) {
                balance++;
                lo.push(in_num);
            }
            else {
                balance--;
                hi.push(in_num);
            }

            // re-balance heaps
            if (balance < 0) {                  // `lo` needs more valid elements
                lo.push(hi.top());
                hi.pop();
                balance++;
            }
            if (balance > 0) {                  // `hi` needs more valid elements
                hi.push(lo.top());
                lo.pop();
                balance--;
            }

            // remove invalid numbers that should be discarded from heap tops
            while (hash_table[lo.top()]) {
                hash_table[lo.top()]--;
                lo.pop();
            }
            while (!hi.empty() && hash_table[hi.top()]) {
                hash_table[hi.top()]--;
                hi.pop();
            }
        }

        return medians;
    }
};

TEST(_0480, MedianSlidingWindow) {
    Solution sln;

    vector<int> case1 = {1,3,-1,-3,5,3,6,7};
    vector<double> res1 = {1,-1,-1,3,5,6};

    ASSERT_TRUE(Check::equal(sln.medianSlidingWindow(case1, 3), res1));
//    ASSERT_EQ(sln.medianSlidingWindow(case1, 3), "BANC");
}