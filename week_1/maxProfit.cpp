#include <iostream>
#include <vector>

class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        size_t num_stocks = prices.size();
        int max_profit = 0;
        if (num_stocks == 0)
            return max_profit;

        int min_i = prices[0];
        int profit;
        for (size_t i = 1; i < num_stocks; ++i)
        {
            min_i = std::min(min_i, prices[i - 1]);
            profit = prices[i] - min_i;
            if (profit > 0)
            {
                max_profit += profit;
                min_i = prices[i];
            }
        }
        return max_profit;
    }
};
