#include <iostream>
#include <algorithm>
#include <vector>

class Solution {
public:
    int lastStoneWeight(std::vector<int>& stones) {
        while (stones.size() > 2)
        {
            std::sort(stones.begin(), stones.end());
            if (stones[0] == stones[1])
            {
                stones.erase(stones.begin());
                stones.erase(stones.begin());
            }
            else
            {
                stones[0] -= stones[1];
                stones.erase(stones.begin() + 1);
            }
        }
        return (stones.size() == 0) ? 0 : stones[1];

    }
};
