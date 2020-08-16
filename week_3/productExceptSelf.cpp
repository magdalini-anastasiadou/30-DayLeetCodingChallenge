#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<int> productExceptSelf(std::vector<int>& nums) {
        int nums_size = nums.size();
        std::vector<int> res(nums_size);
        int prev = 1;
        res[0] = 1;

        for (int i = 0; i < nums_size - 1; ++i)
        {
            res[i + 1] = prev * res[i];
            prev = nums[i];
        }

        prev = 1;
        for (int i = nums_size - 1; i > 0; --i)
        {
            res[i] *= prev;
            prev *= nums[i - 1];
        }

        return res;
    }
};
