#include <utils.h>

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> str_nums;
        auto cvt_string = [&str_nums](const int& n) { str_nums.push_back(to_string(n)); };
        for_each(nums.begin(), nums.end(), cvt_string);
        sort(str_nums.begin(), str_nums.end(), [](const string &a, const string &b) {
            return (a + b) > (b + a);
        });
        ostringstream os;
        for (vector<string>::const_iterator iter = str_nums.begin(); iter != str_nums.end(); iter++) {
            os << *iter;
        }
        string result = os.str();
        if (result[0] == '0') {
            result = "0";
        }
        return result;
    }
};

TEST(_0179, LargestNumber) {
    Solution sln;

    vector<int> nums = {10,2};
    ASSERT_EQ(sln.largestNumber(nums), "210");

    nums = {3,30,34,5,9};
    ASSERT_EQ(sln.largestNumber(nums), "9534330");

    nums = {1};
    ASSERT_EQ(sln.largestNumber(nums), "1");

    nums = {10};
    ASSERT_EQ(sln.largestNumber(nums), "10");

    nums = {0, 0};
    ASSERT_EQ(sln.largestNumber(nums), "0");
}
