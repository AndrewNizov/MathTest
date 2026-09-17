#include "pch.h"
#include "mlib.h"
#include "lib.h"



TEST(TaskTest, ParameterizedConstructorRangeAndOperation) {
    Task t(10, 20, '+');
    EXPECT_GE(t.num_1, 10);
    EXPECT_LE(t.num_1, 20);
    EXPECT_GE(t.num_2, 10);
    EXPECT_LE(t.num_2, 20);
    EXPECT_EQ(t.operation, '+');
    EXPECT_EQ(t.answer, t.num_1 + t.num_2);
}


TEST(MathTestTest, InitializationSize) {
    MathTest test(10);
    EXPECT_EQ(test.get_count(), 10);
    EXPECT_EQ(test.get_correct_count(), 0);
}

TEST(MathTestTest, SubmitCorrectAnswer) {
    MathTest test(3, 5, 5, '+'); 
    Task t = test.get_task(0);

    bool is_correct = test.submit_answer(0, t.answer);

    EXPECT_TRUE(is_correct);
    EXPECT_EQ(test.get_correct_count(), 1);
    EXPECT_EQ(test.get_user_answer(0), t.answer);
}

TEST(MathTestTest, SubmitIncorrectAnswer) {
    MathTest test(3, 5, 5, '+');
    Task t = test.get_task(0);

    bool is_correct = test.submit_answer(0, t.answer + 999);

    EXPECT_FALSE(is_correct);
    EXPECT_EQ(test.get_correct_count(), 0);
}

TEST(MathTestTest, GradeCalculation) {
    MathTest test(5, 2, 2, '+'); 
    for (int i = 0; i < 5; ++i) {
        test.submit_answer(i, 4);
    }
    EXPECT_EQ(test.get_grade(), 'A');
}