//
// Created by Emanuel on 27.08.2021.
//

#include "PalindromePartitioningII.h"

#include <vector>
#include <cassert>
#include <iostream>

int minCut(std::string A) {
    int n = A.length();
    std::vector<std::vector<bool>> is_palindrome(n);  // is_palindrome[i][j] = true <=> A[i..j] is a palindrome

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < i; ++j)
            is_palindrome[i].push_back(false);

    for (int js = 0; js < n; ++js) {
        int i = 0, j = js;
        while (i < n && j < n) {
            if ((j - i) == 1)
                is_palindrome[i].push_back(A[i] == A[j]);
            else
                is_palindrome[i].push_back(i == j || (is_palindrome[i + 1][j - 1] && A[i] == A[j]));
            i++;
            j++;
        }
    }

    std::vector<int> min_cuts(n, 0);  // min_cuts[i] = min cuts for substring A[0..i]
    for (int p = 1; p < n; ++p) {
        min_cuts[p] = min_cuts[p - 1] + 1;
        if (is_palindrome[0][p]) {
            min_cuts[p] = 0;
            continue;
        }

        for (int k = 1; k < p; ++k)
            if (is_palindrome[k][p] && min_cuts[k - 1] + 1 < min_cuts[p])
                min_cuts[p] = min_cuts[k - 1] + 1;
    }

    return min_cuts[n - 1];
}

void testPalindromePartitioningII() {
    assert(minCut("aba") == 0);
    assert(minCut("aab") == 1);
    assert(minCut("bbab") == 1);
}
