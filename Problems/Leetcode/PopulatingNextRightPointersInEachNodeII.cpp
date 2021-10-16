//
// Created by Emanuel on 16.10.2021.
//

#include <unordered_map>

// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
private:
    std::unordered_map<int, Node*> prevAtHeight;
public:
    void postorderTraversal(Node* node, int height) {
        if (node == NULL)
            return;
        postorderTraversal(node->left, height + 1);
        postorderTraversal(node->right, height + 1);

        if (prevAtHeight.find(height) != prevAtHeight.end())
            prevAtHeight[height]->next = node;
        prevAtHeight[height] = node;
    }

    Node* connect(Node* root) {
        postorderTraversal(root, 0);
        return root;
    }
};