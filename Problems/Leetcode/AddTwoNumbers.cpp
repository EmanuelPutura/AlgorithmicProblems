//
// Created by Emanuel on 16.10.2021.
//

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

int findLengthOfSLL(ListNode* head) {
    int len = 0;
    while (head != nullptr) {
        len++;
        head = head->next;
    }
    return len;
}

ListNode* secondHadLessDigits(ListNode* h1, ListNode* h2, int len1, int len2) {
    int rest = 0, v = 0;
    ListNode* current = h1;

    while (current != nullptr && h2 != nullptr) {
        v = current->val + h2->val + rest;
        rest = v / 10;
        current->val = v % 10;
        h2 = h2->next;

        if (current->next == nullptr && rest) {
            current->next = new ListNode(1);
            return h1;
        }
        current = current->next;
    }

    while (current != nullptr) {
        v = current->val + rest;
        rest = v / 10;
        current->val = v % 10;

        if (current->next == nullptr && rest) {
            current->next = new ListNode(1);
            break;
        }
        current = current->next;
    }

    return h1;
}

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    int len1 = findLengthOfSLL(l1);
    int len2 = findLengthOfSLL(l2);

    return len1 < len2 ? secondHadLessDigits(l2, l1, len2, len1) : secondHadLessDigits(l1, l2, len1, len2);
}