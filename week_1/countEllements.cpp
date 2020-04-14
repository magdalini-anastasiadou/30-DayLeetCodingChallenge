#include <iostream>
#include <vector>
#include <map>

class Solution {
public:
    int countElements(std::vector<int>& arr) {
        int cnt = 0;
        std::map<int, int> counter;
        for (const int& i : arr)
            counter[i]++;

        for (const std::pair<int, int>& elem : counter)
        {
            std::map<int, int>::iterator itr = counter.find(elem.first + 1);
            if (itr != counter.end())
                cnt += elem.second;
        }
        return cnt;
    }
};

