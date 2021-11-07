//
// Created by Emanuel on 07.11.2021.
//

#include <bits/stdc++.h>
// Add any extra import statements you may need here

using namespace std;

// Add any helper functions you may need here

struct Node {
    int data;
    Node* left ;
    Node* right;
    Node() {
        data = 0;
        left = NULL;
        right = NULL;
    }
    Node(int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

// Add any helper functions you may need here


int visibleNodes(Node* root) {
    queue<Node*> queue;
    queue.push(root);
    int cnt = 0;

    while (!queue.empty()) {
        int level_size = queue.size();

        for (int i = 0; i < level_size; ++i) {
            Node* elem = queue.front();
            queue.pop();
            if (i == 0)
                cnt++;

            if (elem->left != NULL)
                queue.push(elem->left);
            if (elem->right != NULL)
                queue.push(elem->right);
        }
    }

    return cnt;
}