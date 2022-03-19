//
// Created by Emanuel on 19.03.2022.
//

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        // if (k == 0)
        //     return head;

        if (head == nullptr) {
            return nullptr;
        }

        ListNode* current = head;
        ListNode* tail = nullptr;
        ListNode* previous = nullptr;

        int length = 0;
        int cnt = 0;

        // computer the number of nodes in the list
        while (true) {
            length += 1;

            // compute the tail of the list
            if (current->next == nullptr) {
                tail = current;
                break;
            }

            current = current->next;
        }

        int rotations = k % length;
        if (rotations == 0 || length == 1) {
            return head;
        }

        current = head;
        previous = head;

        while (cnt < length - rotations - 1) {
            cnt += 1;
            previous = previous->next;
        }

        ListNode* result = previous->next;
        previous->next = nullptr;
        tail->next = head;

        return result;
    }
};