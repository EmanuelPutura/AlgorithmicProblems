//
// Created by Emanuel on 16.10.2021.
//

#include <vector>
#include <string>

std::vector<int> minOperations(std::string boxes) {
    std::vector<int> ans (boxes.size());

    // current = operations needed to move all the balls from the left/right to the current position
    int current = 0;

    // cnt = number of balls that are at the left/right of the current position => current = current + cnt
    int cnt = 0;

    // starting from the left
    for (int i = 0; i < boxes.size(); ++i) {
        current = current + cnt;
        ans[i] = current;

        if (boxes[i] == '1')
            cnt++;
    }

    current = 0;
    cnt = 0;

    // starting from the right
    for (int i = boxes.size() - 1; i >= 0; --i) {
        current = current + cnt;
        ans[i] += current;

        if (boxes[i] == '1')
            cnt++;
    }

    return ans;
}