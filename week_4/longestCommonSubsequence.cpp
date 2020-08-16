#include <string>
#include <algorithm>


class Solution {
public:
    int longestCommonSubsequence(std::string text1, std::string text2) {

        if (text1.empty() || text2.empty())
            return 0;

        int m = text1.size() + 1;
        int n = text2.size() + 1;

        int** arr = new int*[m];
        for(int i = 0; i < m; ++i) {
            arr[i] = new int[n];
            arr[i][0] = 0;
        }

        for(int i = 0; i < n; ++i) {
            arr[0][i] = 0;
        }

        int cnt = 0;
        for(int i = 1; i < m; ++i) {
            for(int j = 1; j < n; ++j) {
                if (text1[i - 1] == text2[j - 1])
                    arr[i][j] = 1 + arr[i - 1][j - 1];
                else
                    arr[i][j] = std::max(arr[i - 1][j], arr[i][j - 1]);
            }
        }

        int res = arr[m - 1][n - 1];

        for(int i = 0; i < m; ++i) {
            delete[] arr[i];
        }
        delete[] arr;

        return res;
    }
};
