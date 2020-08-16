#include <vector>
#include <algorithm>


class Solution {
public:
    int maximalSquare(std::vector<std::vector<char>>& matrix) {
        int m = matrix.size();

        if (!m)
            return 0;

        int n = matrix[0].size();

        int** arr = new int*[m + 1];
        for(int i = 0; i < m + 1; ++i) {
            arr[i] = new int[n + 1];
            for (int j = 0; j < n +1; ++j)
                arr[i][j] = 0;
        }

        int a = 0;

        for(int i = 1; i < m + 1; ++i) {
            for(int j = 1; j < n + 1; ++j) {
                if (matrix[i - 1][j - 1] == '1') {
                    arr[i][j] = std::min(arr[i - 1][j], arr[i - 1][j - 1]);
                    arr[i][j] = std::min(arr[i][j], arr[i][j - 1]) + 1;
                    a = std::max(a, arr[i][j]);
                }

            }
        }


        for(int i = 0; i < m + 1; ++i) {
            delete[] arr[i];
        }
        delete[] arr;

        return a * a;

    }
};
