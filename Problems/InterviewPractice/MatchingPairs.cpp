//
// Created by Emanuel on 07.11.2021.
//

#include <bits/stdc++.h>
// Add any extra import statements you may need here

using namespace std;

// Add any helper functions you may need here

int matchingPairs(string s, string t) {
    int cnt_not_ok = 0, n = s.length();
    std::vector<std::vector<bool>> chars_pairs (26);
    for (int i = 0; i < 26; ++i)
        chars_pairs[i] = std::vector<bool> (26, false);

    bool found_eq = false, found_not_ok_match = false;
    int not_ok = -1;

    std::vector<bool> chars (26, false);
    for (int i = 0; i < n; ++i) {
        if (chars[s[i] - 'a']) {
            found_eq = true;
        }

        chars[s[i] - 'a'] = true;
        if (s[i] != t[i]) {
            not_ok = i;
            cnt_not_ok++;

            if (chars_pairs[t[i] - 'a'][s[i] - 'a']) {
                found_not_ok_match = true;
            }
            chars_pairs[s[i] - 'a'][t[i] - 'a'] = true;
        }
    }

    if (cnt_not_ok == 0) {
        if (found_eq) return n;
        else return std::max(n - 2, 0);
    }

    if (cnt_not_ok == 1) {
        for (int i = 0; i < n; ++i) {
            if (i != not_ok && (s[i] == s[not_ok] || s[i] == t[not_ok]))
                return std::max(n - 1, 0);
        }

        return std::max(n - 2, 0);
    }

    if (found_not_ok_match)
        return std::max(0, n - cnt_not_ok + 2);

    std::vector<bool> ok_chars (26, false);
    for (int i = 0; i < n; ++i) {
        if (s[i] == t[i]) {
            ok_chars[s[i] - 'a'] = true;
        }
    }

    for (int i = 0; i < n; ++i) {
        if (s[i] != t[i] && (ok_chars[s[i] - 'a'] || ok_chars[t[i] - 'a']))
            return std::max(0, n - cnt_not_ok + 1);
    }

    return std::max(0, n - cnt_not_ok);
}

// These are the tests we use to determine if the solution is correct.
// You can add your own at the bottom.

void printInteger(int n) {
    cout << "[" << n << "]";
}

int test_case_number = 1;

void check(int expected, int output) {
    bool result = (expected == output);
    const char* rightTick = u8"\u2713";
    const char* wrongTick = u8"\u2717";
    if (result) {
        cout << rightTick << "Test #" << test_case_number << "\n";
    }
    else {
        cout << wrongTick << "Test #" << test_case_number << ": Expected ";
        printInteger(expected);
        cout << " Your output: ";
        printInteger(output);
        cout << endl;
    }
    test_case_number++;
}

int main() {
    string s_1 = "abcde";
    string t_1 = "adcbe";
    int expected_1 = 5;
    int output_1 = matchingPairs(s_1, t_1);
    check(expected_1, output_1);

    string s_2 = "abcd";
    string t_2 = "abcd";
    int expected_2 = 2;
    int output_2 = matchingPairs(s_2, t_2);
    check(expected_2, output_2);

    // Add your own test cases here

}