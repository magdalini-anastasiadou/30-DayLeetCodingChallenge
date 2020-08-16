#include <vector>
#include <stack>

/**
 * Definition for a binary tree node.
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution {
public:
    TreeNode* bstFromPreorder(std::vector<int>& preorder) {
        int n = preorder.size();
        if (!n)
            return NULL;

        TreeNode* root = new TreeNode(preorder[0]);
        int i = 1;

        TreeNode* cursor = root;

        std::stack<TreeNode*> unvisited;
        unvisited.push(root);

        while (!unvisited.empty() && i < n)
        {
            while (i < n && preorder[i] < cursor->val)
            {
                cursor->left = new TreeNode(preorder[i]);
                cursor = cursor->left;
                unvisited.push(cursor);
                ++i;
            }

            if (i >= n)
                return root;

            cursor = unvisited.top();
            unvisited.pop();

            while(!unvisited.empty() && unvisited.top()->val < preorder[i] ) {
                cursor = unvisited.top();
                unvisited.pop();
            }

            cursor->right = new TreeNode(preorder[i]);
            cursor = cursor->right;
            unvisited.push(cursor);
            ++i;
        }

        return root;
    }
};
