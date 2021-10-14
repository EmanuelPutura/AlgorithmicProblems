//
// Created by Emanuel on 09.10.2021.
//

#include <iostream>
#include <vector>

int n, x;
std::vector<int> heights;

int main() {
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        std::cin >> x;
        heights.push_back(x);
    }

    int len = 0, last = -1, bf_last = -1;
    for (int i = n - 1; i >= 0; --i) {
        if (i == n - 1) {
            len = 1;
            last = n - 1;
        }
        else {
            if (heights[i] < last) {
                len++;
                bf_last = last;
                last = heights[i];
            }
            else {
                if (bf_last != -1) {
                    if (heights[i] <= bf_last) {
                        last = heights[i];
                    }
                }
                else {
                    last = heights[i];
                }
            }
        }
    }

    std::cout << len;
    return 0;
}