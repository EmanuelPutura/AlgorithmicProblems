//
// Created by Emanuel on 29.09.2021.
//

#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    bool isOpen(char p) {
        return p == '(' || p == '[' || p == '{';
    }

    bool isClosed(char p) {
        return p == ')' || p == ']' || p == '}';
    }

    char openComplement(char p) {
        if (p == ')') return '(';
        else if (p == ']') return '[';
        else if (p == '}') return '{';
        return ' ';
    }

    bool isValid(string s) {
        std::stack<char> pars;
        for (int i = 0; i < s.length(); ++i) {
            if (isOpen(s[i])) {
                pars.push(s[i]);
            }
            else if (isClosed(s[i])) {
                if (pars.empty() || pars.top() != openComplement(s[i]))
                    return false;
                pars.pop();
            }
            else return false;
        }
        return pars.empty();
    }
};