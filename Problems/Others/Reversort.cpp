//
// Created by Emanuel on 27.10.2021.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int t;

int findMin(const std::vector<int>& v, int st) {
    int min = v[st], pos = st;
    for (int i = st; i < v.size(); ++i)
        if (v[i] < min) {
            pos = i;
            min = v[i];
        }
    return pos;
}

int main() {
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        int n;
        cin >> n;

        vector<int> nos (n);
        for (int j = 0; j < n; ++j)
            cin >> nos[j];

        int cnt = 0;
        for (int j = 0; j < nos.size(); ++j) {
            int k = findMin(nos, j);
            std::reverse(nos.begin() + j, nos.begin() + k + 1);
            cnt += k - j + 1;
        }

        std::cout << "Case #" << i << ": " << cnt - 1 << '\n';
    }

    return 0;
}
