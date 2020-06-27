//
// Created by wangxiaobo on 2020/6/26.
//
#include <utils.h>

// sliding window
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() == 0) {
            return 0;
        }
        unordered_set<char> lookup;
        int maxStr = 0;
        int left = 0;
        for(int i = 0; i < s.size(); i++) {
            while (lookup.find(s[i]) != lookup.end()) {
                lookup.erase(s[left]);
                left ++;
            }
            maxStr = max(maxStr,i-left+1);
            lookup.insert(s[i]);
        }
        return maxStr;
    }

    int lengthOfLongestSubstring2(string s)
    {
        if(s.empty()) return 0;
        int map[128] = {0};
        const unsigned char* ptr_begin = (unsigned char*)s.c_str();
        const unsigned char* ptr = ptr_begin;
        const unsigned char* begin = ptr_begin;
        int max_length = 1;
        int begin_n = 1;
        map[*ptr++] = 1;

        while(*ptr){
            unsigned char c = *ptr;
            cout << "c=" << c << " begin_n=" << begin_n << endl;
            if(map[c] >= begin_n){
                max_length = max(max_length, (int)(ptr - begin));
                begin_n = map[c];
                begin = ptr_begin + begin_n;
                cout << "adjust windows" << endl;
                cout << "map[c]=" << map[c] << " begin_n=" << begin_n << " begin=" << begin << endl;
            }
            map[c] = ptr - ptr_begin + 1;
            ++ptr;
        }
        return max(max_length, (int)(ptr - begin));
    }
};

TEST(_0003, LongestSubstring) {
    Solution sln;
    ASSERT_EQ(sln.lengthOfLongestSubstring("abcabcbb"), 3);
    ASSERT_EQ(sln.lengthOfLongestSubstring("bbbbb"), 1);
    ASSERT_EQ(sln.lengthOfLongestSubstring("pwwkew"), 3);

    ASSERT_EQ(sln.lengthOfLongestSubstring2("abcabcbb"), 3);
}

