#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if (!root)
            return 0;
        int height_left = height(root->left);
        int height_right = height(root->right);

        int diameter_left = diameterOfBinaryTree(root->left);
        int diameter_right = diameterOfBinaryTree(root->right);
        return std::max(height_left + height_right, std::max(diameter_left, diameter_right));
    }
    int height(TreeNode* cursor) {
        if (!cursor)
            return 0;
        return std::max(height(cursor->right), height(cursor->left)) + 1;
    }

};
