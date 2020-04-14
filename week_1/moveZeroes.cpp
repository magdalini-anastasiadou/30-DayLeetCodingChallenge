#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    void moveZeroes(std::vector<int>& nums) {
        std::size_t cnt = 0;
        for (std::size_t i = 0; i < nums.size(); ++i)
        {
            if (nums[i] != 0)
            {
                std::swap(nums[cnt], nums[i]);
                ++cnt;
            }
        }
    }
};
