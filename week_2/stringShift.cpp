#include <string>
#include <vector>
#include <iostream>

class Solution {
public:
    std::string stringShift(std::string str, std::vector<std::vector<int>>& shift) {
        int total_shift = 0;
        int len_str = str.size();
        std::string str_final(len_str, ' ');

        for (const std::vector<int>& vec : shift)
        {
            int direction = vec[0] == 0 ? -1 : 1;
            int amount = vec[1];
            total_shift = total_shift + direction * amount;
        }

        for (int i = 0; i < str.size(); ++i)
        {
            str_final[ (total_shift % len_str + len_str) % len_str] = str[i];
        }
        return str_final;
    }
};
