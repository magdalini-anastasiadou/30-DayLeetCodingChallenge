#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

struct Sum
{
    Sum(): sum{0} { }
    void operator()(int n) { sum += n; }
    int sum;
};

class Solution {
public:
    bool isHappy(int n) {
        std::vector<int> nums;
        nums.push_back(n);
        std::vector<int> digits;

        while (n != 1)
        {
            digits = get_digits(nums.back());
            std::for_each(digits.begin(), digits.end(), [](int &n) { n = std::pow(n, 2); });
            Sum s = std::for_each(digits.begin(), digits.end(), Sum());
            if (std::find(nums.begin(), nums.end(), s.sum) == nums.end())
            {
                n = s.sum;
                nums.push_back(n);
            }
            else
                return false;
        }
        return true;
    }

    std::vector<int> get_digits(int dividend) {
        int divisor = 10;
        int quotient = dividend / divisor;
        int remainder = dividend % divisor;
        std::vector<int> digits;
        digits.insert(digits.begin(), remainder);

        while (quotient)
        {
            dividend = quotient;
            quotient = dividend / divisor;
            remainder = dividend % divisor;
            digits.insert(digits.begin(), remainder);
        }
        return digits;
    }
};
