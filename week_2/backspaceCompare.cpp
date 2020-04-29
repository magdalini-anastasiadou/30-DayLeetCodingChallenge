#include <iostream>
#include <string>

class Solution {
public:
    bool backspaceCompare(std::string str_1, std::string str_2) {
        int len_str_1 = 0;
        int len_str_2 = 0;
        for (int i = 0; i < str_1.size(); ++i)
        {
            if (str_1[i] == '#')
            {
                --len_str_1;
                len_str_1 = std::max(len_str_1, 0);
            }
            else
            {
                str_1[len_str_1] = str_1[i];
                ++len_str_1;
            }
        }
        for (int i = 0; i < str_2.size(); ++i)
        {
            if (str_2[i] == '#')
            {
                --len_str_2;
                len_str_2 = std::max(len_str_2, 0);
            }
            else
            {
                str_2[len_str_2] = str_2[i];
                ++len_str_2;
            }
        }
        if (len_str_1 != len_str_2)
            return false;

        for (int i = 0; i < len_str_2; ++i)
        {
            if (str_1[i] != str_2[i])
                return false;
        }
        return true;
    }
};
