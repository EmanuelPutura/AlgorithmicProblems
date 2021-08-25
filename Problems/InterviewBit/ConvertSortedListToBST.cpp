//
// Created by Emanuel on 25.08.2021.
//

#include "ConvertSortedListToBST.h"

#include <cassert>

TreeNode *sortedListToBST(ListNode *A) {
    std::vector<int> list;

    while (A) {
        list.push_back(A->val);
        A = A->next;
    }
    return constructBST(list, 0, list.size() - 1);
}

TreeNode* constructBST(const std::vector<int> &list, int begin, int end) {
    if (begin <= end) {
        int middle = (begin + end) / 2;
        TreeNode *root = new TreeNode(list[middle]);
        root->left = constructBST(list, begin, middle - 1);
        root->right = constructBST(list, middle + 1, end);
        return root;
    }
    else return nullptr;
}

TreeNode *sortedListToBSTAnotherSolution(ListNode *A) {
    int n = 0;
    ListNode *copy = A;
    while (A) {
        n++;
        A = A->next;
    }

    return constructBSTAnotherSolution(copy, 0, n - 1);
}

TreeNode *constructBSTAnotherSolution(ListNode* &current, int begin, int end) {
    if (!current)
        return nullptr;

    if (begin == end) {
        TreeNode *returned = new TreeNode(current->val);
        return returned;
    }
    else if (begin < end) {
        int middle = (begin + end) / 2;
        TreeNode *left = constructBSTAnotherSolution(current, begin, middle - 1);
        if (left)
            current = current->next;
        TreeNode *root = new TreeNode(current->val);
        TreeNode *right = constructBSTAnotherSolution(current->next, middle + 1, end);
        if (right)
            current = current->next;
        root->left = left;
        root->right = right;
        return root;
    }
    return nullptr;
}

void testConvertSortedListToBSTAnotherSolution() {
    ListNode *head = new ListNode(1), *copy = head;
    for (int i = 2; i <= 5; ++i) {
        copy->next = new ListNode(i);
        copy = copy->next;
    }

    std::vector<int> res;
    inorderTraversal(res, sortedListToBSTAnotherSolution(head));
    for (int i = 1; i <= 5; ++i)
        assert(res[i - 1] == i);
}

void inorderTraversal(std::vector<int> &traversal, TreeNode *root) {
    if (root) {
        inorderTraversal(traversal, root->left);
        traversal.push_back(root->val);
        inorderTraversal(traversal, root->right);
    }
}
