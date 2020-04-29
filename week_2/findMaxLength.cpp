#include <iostream>
#include <vector>
#include <map>

class Solution {
public:
    int findMaxLength(std::vector<int>& nums) {
        std::map<int, int> idx_counter;
        int max_length = 0, count = 0;

        for (int i = 0; i < nums.size(); ++i) {
            count += nums[i] == 0 ? -1 : 1;
            if (count == 0) {
                max_length = i + 1;
            } else if (idx_counter.find(count) != idx_counter.end()) {
                max_length = std::max(max_length, i - idx_counter[count]);
            } else {
                idx_counter[count] = i;
            }
        }

        return max_length;
    }
};
