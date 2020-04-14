#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    int maxSubArray(std::vector<int>& nums) {
        int max_n = 0;
        int max_temp = 0;

        for (const int& n : nums)
        {
            max_temp += n;
            if (max_temp > max_n)
                max_n = max_temp;
            else if (max_temp < 0)
                max_temp = 0;
        }

        if (max_n == 0)
            return *std::max_element(nums.begin(), nums.end());
        return max_n;
    }
};
