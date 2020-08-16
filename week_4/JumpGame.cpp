#include <vector>


class Solution {
public:
    bool canJump(std::vector<int>& nums) {
        int n = nums.size();

        if (!n)
            return false;

        if (n == 1)
            return true;

        std::vector<int> pos;
        for (int i = 0; i < n; ++i)
        {
            pos.push_back(i + nums[i]);
        }

        int end = pos[0];

        for  (int i = 1; i < n; ++i)
        {
            if (end >= n - 1)
                return true;

            if (i > end)
                return false;

            end = std::max(end, pos[i]);
        }

        return false;
    }
};

