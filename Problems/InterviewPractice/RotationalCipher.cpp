//
// Created by Emanuel on 17.10.2021.
//

#include <bits/stdc++.h>
// Add any extra import statements you may need here

using namespace std;

// Add any helper functions you may need here


string rotationalCipher(string input, int rotationFactor) {
    for (int i = 0; i < input.length(); ++i) {
        if (isalnum(input[i])) {
            if (isdigit(input[i]))
                input[i] = (input[i] + rotationFactor - '0') % 10 + '0';
            else if (islower(input[i]))
                input[i] = (input[i] + rotationFactor - 'a') % ('z' - 'a' + 1) + 'a';
            else {
                input[i] = (input[i] + rotationFactor - 'A') % ('Z' - 'A' + 1) + 'A';
            }
        }
    }

    return input;
}


// These are the tests we use to determine if the solution is correct.
// You can add your own at the bottom.

void printString(string& str) {
    cout << "[\"" << str << "\"]";
}

int test_case_number = 1;

void check(string& expected, string& output) {
    bool result = (expected == output);
    const char* rightTick = u8"\u2713";
    const char* wrongTick = u8"\u2717";
    if (result) {
        cout << rightTick << "Test #" << test_case_number << "\n";
    }
    else {
        cout << wrongTick << "Test #" << test_case_number << ": Expected ";
        printString(expected);
        cout << " Your output: ";
        printString(output);
        cout << endl;
    }
    test_case_number++;
}

/*
int main() {

    string input_1 = "All-convoYs-9-be:Alert1.";
    int rotationFactor_1 = 4;
    string expected_1 = "Epp-gsrzsCw-3-fi:Epivx5.";
    string output_1 = rotationalCipher(input_1, rotationFactor_1);
    check(expected_1, output_1);

    string input_2 = "abcdZXYzxy-999.@";
    int rotationFactor_2 = 200;
    string expected_2 = "stuvRPQrpq-999.@";
    string output_2 = rotationalCipher(input_2, rotationFactor_2);
    check(expected_2, output_2);

    // Add your own test cases here

}
 */