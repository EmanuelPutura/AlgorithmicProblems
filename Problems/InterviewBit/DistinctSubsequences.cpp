//
// Created by Emanuel on 25.08.2021.
//

#include "DistinctSubsequences.h"

#include <vector>
#include <iostream>
#include <cassert>

int numDistinct(std::string A, std::string B) {
    int n = A.length(), m = B.length();
    std::vector<std::vector<int>> cnt;

    for (int i = 0; i < n; ++i)
        cnt.push_back(std::vector<int>(m));

    cnt[0][0] = A[0] == B[0];
    for (int i = 1; i < n; ++i)
        cnt[i][0] = cnt[i - 1][0] + (A[i] == B[0]);

    for (int i = 1; i < n; ++i)
        for (int j = 1; j < m; ++j)
            cnt[i][j] = cnt[i - 1][j] + cnt[i - 1][j - 1] * (A[i] == B[j]);

    return cnt[n - 1][m - 1];
}

void testDistinctSubsequences() {
    std::string s1 {"rabbbit"};
    std::string s2 {"rabbit"};
    assert(numDistinct(s1, s2) == 3);

    std::string s3 {"abc"};
    std::string s4 {"abc"};
    assert(numDistinct(s3, s4) == 1);

    std::string s5 {"rrabb"};
    std::string s6 {"rab"};
    assert(numDistinct(s5, s6) == 4);
}
