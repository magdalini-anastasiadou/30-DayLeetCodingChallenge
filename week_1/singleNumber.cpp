#include <iostream>
#include <vector>

class Solution {
public:
    int singleNumber(std::vector<int>& nums) {
        int single_num =  1;
        for (const int& i : nums)
            single_num ^= i;
        return single_num ^ 1;
    }
};
