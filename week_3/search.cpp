#include <vector>


class Solution {
public:
    int search(std::vector<int>& nums, int target) {
        int n = nums.size();
        if (!n)
            return -1;

        int first = nums[0];
        int right = 0, left = n - 1;
        while (right <= left)
        {
            int mid = right + (left - right) / 2;
            if (nums[mid] == target)
                return mid;

            if (first <= nums[mid])
            {
                if (target < nums[mid] && target >= first)
                    left = mid - 1;
                else
                    right = mid + 1;
            }
            else
            {
                if (target > nums[mid] && target <= nums[left])
                    right = mid + 1;
                else
                    left = mid - 1;
            }
        }
        return -1;
    }
};
