//
// Created by Emanuel on 16.10.2021.
//

#include <stack>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int previous = -1;
bool is_defined = false;

bool isValidBST(TreeNode* root) {
    // make an inorder traversal
    std::stack<TreeNode*> nodes;
    bool done = false;

    TreeNode* current = root;
    while (!done) {
        if (current != nullptr) {
            nodes.push(current);
            current = current->left;
        }
        else {
            if (!nodes.empty()) {
                current = nodes.top();
                nodes.pop();

                if (is_defined && previous >= current->val)
                    return false;

                previous = current->val;
                is_defined = true;
                current = current->right;
            }
            else done = true;
        }
    }
    return true;
}