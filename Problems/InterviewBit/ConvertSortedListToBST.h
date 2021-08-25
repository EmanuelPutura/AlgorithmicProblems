//
// Created by Emanuel on 25.08.2021.
//

#ifndef PROBLEMS_CONVERTSORTEDLISTTOBST_H
#define PROBLEMS_CONVERTSORTEDLISTTOBST_H

#include <vector>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

/*
 * Idea: the sorted list represents the inorder traversal of the BST. We have to construct a BST such that it is balanced and it contains those elements.
 * Hence, from a list of nodes always consider the node from [n / 2] + 1 to be the root of the (sub)tree and continue recursively
 */

/*
 * Extra Space complexity: Theta(n)
 */
TreeNode* sortedListToBST(ListNode* A);
TreeNode* constructBST(const std::vector<int>& list, int begin, int end);

/*
 * Extra Space complexity: Theta(1)
 */
TreeNode* sortedListToBSTAnotherSolution(ListNode* A);
TreeNode* constructBSTAnotherSolution(ListNode* &current, int begin, int end);

void inorderTraversal(std::vector<int>& traversal, TreeNode *root);
void testConvertSortedListToBSTAnotherSolution();

#endif //PROBLEMS_CONVERTSORTEDLISTTOBST_H
