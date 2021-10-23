//
// Created by Emanuel on 23.10.2021.
//

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        bool running = true;
        int queue_front = 0, queue_rear = students.size() - 1, students_no = students.size();
        int stack_top = 0, cnt = 0;

        while (running && queue_front <= queue_rear) {
            running = false;
            int index = 0;
            int len = queue_rear - queue_front + 1;

            while (index < len) {
                int current_student = students[queue_front++];
                if (current_student == sandwiches[stack_top]) {
                    stack_top++;
                    running = true;
                }
                else {
                    if (students.size() < 2 * students_no) {
                        students.push_back(current_student);
                    }
                    else students[queue_rear + 1] = current_student;
                    queue_rear++;

                    if (queue_rear == 2 * students_no - 1) {
                        std::rotate(students.begin(), students.begin() + queue_front, students.end());
                        queue_rear = queue_rear - queue_front;
                        queue_front = 0;
                    }
                }
                index++;
            }
        }

        return queue_rear - queue_front + 1;
    }
};