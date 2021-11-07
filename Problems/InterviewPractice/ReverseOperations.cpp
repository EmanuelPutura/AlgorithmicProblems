//
// Created by Emanuel on 07.11.2021.
//

#include <bits/stdc++.h>
// Add any extra import statements you may need here

using namespace std;

struct Node {
    int data;
    Node *next;
    Node(int x) : data(x), next(NULL) {}
};

Node* reverseSubpart(Node *start) {
    Node *prev = start, *current = start->next;
    while (current != NULL && current->data % 2 == 0) {
        auto tmp = current->next;
        current->next = prev;
        prev = current;
        current = tmp;
    }

    start->next = current;
    return prev;
}

Node* reverse(Node *head) {
    Node *current = head, *prev = NULL;
    while (current != NULL) {
        if (current->data % 2 == 0) {
            if (prev != NULL)
                prev->next = reverseSubpart(current);
            else head = reverseSubpart(current);
        }
        prev = current;
        current = current->next;
    }

    return head;
}
