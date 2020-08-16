#include <iostream>
#include <vector>

class Solution {
public:
    void mark_current(std::vector<std::vector<char>>& grid, int i, int j, int x_size, int y_size) {
        if (i >= x_size || i < 0 || j >= y_size || j < 0 || grid[i][j] != '1')
        {
            return;
        }
        grid[i][j] = '2';
        mark_current(grid, i - 1, j, x_size, y_size);
        mark_current(grid, i, j - 1, x_size, y_size);
        mark_current(grid, i, j + 1, x_size, y_size);
        mark_current(grid, i + 1, j, x_size, y_size);
    }

    int numIslands(std::vector<std::vector<char>>& grid) {
        int x_size = grid.size();
        if (x_size == 0)
            return 0;

        int num = 0;
        int y_size = grid[0].size();

        for (int i = 0; i < grid.size(); ++i)
        {
            for (int j = 0; j < grid[i].size(); ++j)
            {
                if (grid[i][j] == '1')
                {
                    mark_current(grid, i, j, x_size, y_size);
                    ++num;
                }
            }
        }
        return num;
    }

};
