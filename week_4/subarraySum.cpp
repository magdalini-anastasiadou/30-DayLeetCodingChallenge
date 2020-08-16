#include <vector>
#include <map>


class Solution {
public:
    int subarraySum(std::vector<int>& nums, int k) {
        std::map<int, int> freq = {{0, 1}};
        int cnt = 0, sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            cnt += freq[sum - k];
            freq[sum]++;
        }
        return cnt;
    }
};
