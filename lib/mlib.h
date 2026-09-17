#pragma once
#pragma once
#include "lib.h"

class MathTest {
private:
    Task* tasks;
    int count;
    int* user_answers;
    int correct_count;

    void cleanup();

public:
    MathTest();
    MathTest(int test_size);
    MathTest(int test_size, int min_val, int max_val);
    MathTest(int test_size, int min_val, int max_val, char op);

    ~MathTest();

    MathTest(const MathTest&) = delete;
    MathTest& operator=(const MathTest&) = delete;

    int get_count() const { return count; }
    int get_correct_count() const { return correct_count; }
    Task get_task(int index) const;
    int get_user_answer(int index) const;

    bool submit_answer(int index, int user_ans);

    void run();
    void show_statistics() const;
    char get_grade() const;
};