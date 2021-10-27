//
// Created by Emanuel on 27.10.2021.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int X, Y;
string str;
vector<int> wc;
vector<int> wj;

void readTest();
int solveTest();

int main() {
    int T;
    cin >> T;

    for (int i = 1; i <= T; ++i) {
        readTest();
        cout << "Case #" << i << ": " << solveTest() << '\n';
    }

    return 0;
}

void readTest() {
    cin >> X >> Y >> str;
}

int solveTest() {
    const int INF = 0x3f3f3f3f;
    wc = vector<int> (str.length(), INF);
    wj = vector<int> (str.length(), INF);

    wc[0] = str[0] == 'J' ? INF : 0;
    wj[0] = str[0] == 'C' ? INF : 0;

    for (int i = 1; i < str.length(); ++i) {
        if (str[i] != 'J')
            wc[i] = min(wc[i - 1], wj[i - 1] + Y);
        if (str[i] != 'C')
            wj[i] = min(wc[i - 1] + X, wj[i - 1]);
    }

    return std::min(wc[str.length() - 1], wj[str.length() - 1]);
}