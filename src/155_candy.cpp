#include <utils.h>

class Solution {
public:
    int candy(vector<int>& ratings) {
        int size = ratings.size();
        if (size < 2) {
            return size;
        }
        vector<int> num(size, 1);
        for (int i = 1; i < size; ++i) {
            if (ratings[i] > ratings[i-1]) {
                num[i] = num[i-1] + 1;
            }
        }
        for (int i = size - 1; i > 0; --i) {
            if (ratings[i] < ratings[i-1]) {
                num[i-1] = max(num[i-1], num[i] + 1);
            }
        }
        int sum = 0;
        for (int i = 0; i < num.size(); i++) {
            sum += num[i];
        }
        return sum;
    }
};

TEST(_0155, Candy) {
    Solution sln;

    vector<int> ratings = {1,0,2};
    ASSERT_EQ(sln.candy(ratings), 5);

    ratings = {1,2,2};
    ASSERT_EQ(sln.candy(ratings), 4);

    ratings = {1,3,2,2,1};
    ASSERT_EQ(sln.candy(ratings), 7);
}