//
// Created by Emanuel on 30.09.2021.
//

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


bool isPalindrome(ListNode* head) {
    int n = 0;
    ListNode *current = head, *previous = nullptr;
    while (current) {
        previous = current;
        current = current->next;
        n++;
    }

    ListNode *end = previous;
    current = head;
    previous = nullptr;

    int index = 0;
    while (current) {
        if (index > (n + 1) / 2) {
            ListNode *copy = current->next;
            current->next = previous;
            if (index == ((n + 1) / 2 + 1))
                previous->next = nullptr;
            previous = current;
            current = copy;
        }
        else {
            previous = current;
            current = current->next;
        }
        index++;
    }

    index = 0;
    previous = head;
    current = end;

    while (index < n / 2) {
        if (previous->val != current->val)
            return false;
        previous = previous->next;
        current = current->next;
        index++;
    }

    return true;
}