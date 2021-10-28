//
// Created by Emanuel on 27.10.2021.
//

#include <bits/stdc++.h>
using namespace std;

int N, C;
vector<int> a;

void readTest();
bool solveTest();

int main() {
    int T;
    cin >> T;
    for (int i = 1; i <= T; ++i) {
        readTest();
        if (!solveTest())
            cout << "Case #" << i << ": IMPOSSIBLE\n";
        else {
            std::cout << "Case #" << i << ": ";
            for (const auto& el : a)
                std::cout << el << ' ';
            std::cout << '\n';
        }
    }

    return 0;
}

void readTest() {
    cin >> N;
    cin >> C;
}

bool solveTest() {
    if (C < N - 1 || C > N * (N + 1) / 2 - 1)
        return false;

    a = vector<int> (N);

    int l = 0, r = N - 1, check = 1;
    for (int i = 1; i <= N; ++i) {
        if (C - (N - i + 1) >= N - i - 1) {
            if (check)
                a[r--] = i;
            else
                a[l++] = i;
            check = 1 - check;
            C -= (N - i + 1);
        }
        else {
            if (check)
                a[l++] = i;
            else
                a[r--] = i;

            C--;
        }
    }

    return true;
}
