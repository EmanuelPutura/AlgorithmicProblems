//
// Created by Emanuel on 23.10.2021.
//

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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode *current = root, *previous = nullptr;

        while (current != nullptr) {
            previous = current;

            if (val < current->val)
                current = current->left;
            else
                current = current->right;
        }

        current = new TreeNode(val);
        if (previous == nullptr)
            return current;

        if (val < previous->val)
            previous->left = current;
        else
            previous->right = current;

        return root;
    }
};