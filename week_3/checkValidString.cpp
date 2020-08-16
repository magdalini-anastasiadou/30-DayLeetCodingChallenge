#include <iostream>
#include <string>
#include <stack>

class Solution {
public:
    bool checkValidString(std::string str) {
        std::stack<char> stack_1;
        std::stack<char> stack_2;
        char top_1, top_2;
        for (int i = 0; i < str.size(); ++i)
        {
            if (str[i] == '(')
            {
                stack_1.push(i);
            }
            else if (str[i] == '*')
            {
                stack_2.push(i);
            }
            else if (str[i] == ')' && !stack_1.empty())
            {
                stack_1.pop();
            }
            else if (str[i] == ')' && !stack_2.empty())
            {
                stack_2.pop();
            }
            else
            {
                return false;
            }
        }

        while(!stack_2.empty() && !stack_1.empty())
        {
            if (stack_1.top() > stack_2.top())
                return false;
            stack_1.pop();
            stack_2.pop();
        }

        return stack_1.empty();
    }
};
