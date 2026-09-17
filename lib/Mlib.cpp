#include "mlib.h"
#include <iostream>
#include <iomanip>
#include <string>

void MathTest::cleanup() {
    delete[] tasks;
    delete[] user_answers;
}

MathTest::MathTest() : MathTest(5, 1, 10) {}

MathTest::MathTest(int test_size) : MathTest(test_size, 1, 10) {}

MathTest::MathTest(int test_size, int min_val, int max_val) : MathTest(test_size, min_val, max_val, '\0') {}

MathTest::MathTest(int test_size, int min_val, int max_val, char op) {
    count = (test_size > 0) ? test_size : 5;
    correct_count = 0;
    tasks = new Task[count];
    user_answers = new int[count]();

    for (int i = 0; i < count; ++i) {
        tasks[i] = Task(min_val, max_val, op);
        user_answers[i] = 0;
    }
}

MathTest::~MathTest() {
    cleanup();
}

Task MathTest::get_task(int index) const {
    if (index >= 0 && index < count) return tasks[index];
    return Task();
}

int MathTest::get_user_answer(int index) const {
    if (index >= 0 && index < count) return user_answers[index];
    return 0;
}

bool MathTest::submit_answer(int index, int user_ans) {
    if (index < 0 || index >= count) return false;

    user_answers[index] = user_ans;
    if (user_ans == tasks[index].answer) {
        correct_count++;
        return true;
    }
    return false;
}

char MathTest::get_grade() const {
    double percentage = (double)correct_count / count * 100.0;
    if (percentage >= 90) return 'A';
    if (percentage >= 80) return 'B';
    if (percentage >= 70) return 'C';
    if (percentage >= 60) return 'D';
    return 'F';
}

void MathTest::run() {
    std::cout << "=== Math Test Started ===" << std::endl;
    for (int i = 0; i < count; ++i) {
        std::cout << "Question " << (i + 1) << ": "
            << tasks[i].num_1 << " " << tasks[i].operation << " " << tasks[i].num_2 << " = ";
        int ans;
        std::cin >> ans;
        submit_answer(i, ans);
    }
    std::cout << "\nTest Finished!\n" << std::endl;
    show_statistics();
}

void MathTest::show_statistics() const {
    std::cout << "| " << std::setw(12) << "No" << " |";
    for (int i = 0; i < count; ++i) std::cout << std::setw(8) << (i + 1) << " |";
    std::cout << "\n+---------------------------------------------------------------+\n";

    std::cout << "| " << std::setw(12) << "Question" << " |";
    for (int i = 0; i < count; ++i) {
        std::string q = std::to_string(tasks[i].num_1) + " " + tasks[i].operation + " " + std::to_string(tasks[i].num_2);
        std::cout << std::setw(8) << q << " |";
    }
    std::cout << "\n";

    std::cout << "| " << std::setw(12) << "True Answer" << " |";
    for (int i = 0; i < count; ++i) std::cout << std::setw(8) << tasks[i].answer << " |";
    std::cout << "\n";

    std::cout << "| " << std::setw(12) << "Your Answer" << " |";
    for (int i = 0; i < count; ++i) std::cout << std::setw(8) << user_answers[i] << " |";
    std::cout << "\n";

    std::cout << "| " << std::setw(12) << "Result" << " |";
    for (int i = 0; i < count; ++i) {
        char res = (user_answers[i] == tasks[i].answer) ? '+' : '-';
        std::cout << std::setw(8) << res << " |";
    }
    std::cout << "\n\n";

    std::cout << "Total Result: " << correct_count << " / " << count
        << " (mark: " << get_grade() << ")" << std::endl;
}