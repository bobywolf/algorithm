//
// Created by wangxiaobo on 2020/6/27.
//
#include <utils.h>

// sliding window
class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> map;
        for (auto c : t) map[c]++;
        int left = 0, cnt = 0, maxlen = s.size() + 1, start = left;
        for (int i = 0; i < s.size(); ++i) {
            if (--map[s[i]] >= 0) ++cnt;
            while(cnt == t.size()) {
                if (maxlen > i - left + 1) {
                    maxlen = i - left + 1;
                    start = left;
                }
                if (++map[s[left]] > 0) cnt--;
                left++;
            }
        }
        return maxlen == s.size() + 1 ? "" : s.substr(start, maxlen);
    }

    string minWindow2(string s, string t) {
        unordered_map<char, int> map;
        for (auto c : t) map[c]++;
        int left = 0, cnt = 0, maxlen = s.size() + 1, start = left;
        for (int i = 0; i < s.size(); ++i) {
            if (--map[s[i]] >= 0) ++cnt;
            while (cnt == t.size()) {
                if (++map[s[left]] > 0) {
                    if (maxlen > i - left + 1) {
                        maxlen = i - left + 1;
                        start = left;
                    }
                    cnt--;
                }
                left++;
            }
        }
        return maxlen == s.size() + 1 ? "" : s.substr(start, maxlen);
    }
};

TEST(_0076, minWindow) {
    Solution sln;

    ASSERT_EQ(sln.minWindow2("ADOBECODEBANC", "ABC"), "BANC");
}