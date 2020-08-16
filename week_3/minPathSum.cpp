#include <iostream>
#include <queue>
#include <vector>
#include <limits>


class Solution {
public:
    int minPathSum(std::vector<std::vector<int>>& grid) {
        int x_size = grid.size();
        if (x_size == 0)
            return 0;

        int y_size = grid[0].size();
        std::vector<std::vector<int> > cost(x_size, std::vector<int>(y_size, 0));

        // 1st row
        cost[0][0] = grid[0][0];
        for (int i = 1; i < y_size; ++i)
        {
            cost[0][i] = cost[0][i - 1] + grid[0][i];
        }

        // 1st column
        for (int i = 1; i < x_size; ++i)
        {
            cost[i][0] = cost[i - 1][0] + grid[i][0];
        }

        for (int i = 1; i < x_size; ++i)
        {
            for (int j = 1; j < y_size; ++j)
            {
                cost[i][j] = grid[i][j] + std::min(cost[i - 1][j], cost[i][j - 1]);
            }
        }
        return cost[x_size - 1][y_size - 1];
    }
};
