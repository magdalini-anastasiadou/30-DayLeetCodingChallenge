#include <iostream>
#include <vector>
#include <string>
#include <map>

class Solution {
public:
    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
        std::map<std::map<int, int>, std::vector<std::string>> counter;
        std::vector<std::vector<std::string>> group_anagrams;
        for (const std::string& str : strs)
        {
            std::map<int, int> str_counter;
            for (const int& c : str)
                ++str_counter[c - 'a'];
            counter[str_counter].push_back(str);
        }

        for (const std::pair<std::map<int, int>, std::vector<std::string>>& elem : counter)
            group_anagrams.push_back(elem.second);
        return group_anagrams;
    }
};
