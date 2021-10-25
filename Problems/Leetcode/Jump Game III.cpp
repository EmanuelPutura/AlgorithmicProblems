//
// Created by Emanuel on 25.10.2021.
//

#include <vector>
using namespace std;

class Solution {
public:
    static bool canReach(vector<int>& arr, int start) {
        // DFS approach
        std::stack<int> stack;  // indices will be pushed to the stack
        int current = start;
        std::vector<bool> visited (arr.size(), false);

        while ((current >= 0 && current < arr.size()) || !stack.empty()) {
            while (current >= 0 && current < arr.size()) {
                if (!arr[current])
                    return true;

                if (!visited[current]) {
                    stack.push(current);
                    visited[current] = true;
                    current = current - arr[current];
                }
                else break;
            }

            if (stack.empty())
                break;
            current = stack.top();
            stack.pop();
            current = current + arr[current];
        }

        return false;
    }
};