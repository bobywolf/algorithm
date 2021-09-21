#include <utils.h>

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        size_t i = 0;
        size_t j = 0;
        int cnt = 0;
        while (i < g.size() && j < s.size()) {
            if (g[i] <= s[j]) {
                i++; j++; cnt++;
            } else {
                j++;
            }
        }
        return cnt;
    }
};

TEST(_0455, AssignCookies) {
    vector<int> g = {1,2,3};
    vector<int> s = {1,1};
    Solution sln;
    ASSERT_EQ(sln.findContentChildren(g, s), 1);

    g = {1, 2};
    s = {1, 2, 3};
    ASSERT_EQ(sln.findContentChildren(g, s), 2);
}
