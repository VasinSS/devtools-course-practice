// Copyright 2017 Fedorov Igor

#include <gtest/gtest.h>
#include"include/field.h"
// construct
TEST(Field, Can_creat_obj_by_defult) {
    ASSERT_NO_THROW(Field app);
}

TEST(Field, Can_creat_obj_width_less_height) {
    ASSERT_NO_THROW(Field app(10, 10, 30));
}

TEST(Field, Can_creat_obj_with_equal_size) {
    ASSERT_ANY_THROW(Field app(-20, -20, 10));
}

TEST(Field, throw_when_negative_hight) {
    ASSERT_ANY_THROW(Field app(-20, -20, -10));
}
// print
TEST(Field, can_print) {
    Field app(2, 2, 1);

    ASSERT_NO_THROW(app.PrintField());
}

TEST(Field, print_predict) {
    Field app(2, 2, 1);

    std::cout << app.PrintField() << std::endl;

    ASSERT_EQ(" |0 1 |\n-+----+\n0|* * |\n1|* * |\n-+----+\n",
        app.PrintField());
}

TEST(Field, Can_open_all) {
    Field app(2, 2, 0);

    for (int i = 0; i < 2; i++)
        for (int k = 0; k < 2; k++)
            ASSERT_NO_THROW(app.OpenCurrentCell(i, k));
}

TEST(Field, Cant_open_nothing) {
    Field app(2, 2, 0);

    for (int i = -3; i < 6; i++)
        for (int k = -10; k < 20; k++)
            if (i != 0 && i != 1 && k != 0 && k != 1)
                ASSERT_FALSE(app.OpenCurrentCell(i, k));
}

TEST(Field, Can_open_that_exist) {
    Field app(2, 2, 0);

    for (int i = -1; i < 4; i++)
        for (int k = -10; k < 20; k++)
            ASSERT_NO_THROW(app.OpenCurrentCell(i, k));
}

TEST(Field, Can_open_all_cell_with_true_) {
    Field app(2, 2, 0);

    for (int i = 0; i < 2; i++)
        for (int k = 0; k < 2; k++)
            ASSERT_TRUE(app.OpenCurrentCell(i, k));
}

TEST(Field, Can_open_all_and_eq_print_string) {
    Field app(2, 2, 0);

    for (int i = 0; i < 2; i++)
        for (int k = 0; k < 2; k++)
            app.OpenCurrentCell(i, k);

    ASSERT_EQ(" |0 1 |\n-+----+\n0|0 0 |\n1|0 0 |\n-+----+\n",
        app.PrintField());
}

TEST(Field, can_win) {
    Field app(10, 10, 9);

    for (int i = 0; i < 10; i++)
        for (int k = 0; k < 10; k++)
            if (!app[i][k].isBomb)
                app.OpenCurrentCell(i, k);

    ASSERT_NO_THROW(app.IsWin());
}

TEST(Field, Can_not_win) {
    Field app(10, 10, 9);

    ASSERT_NO_THROW(app.IsWin());
}

TEST(Field, Can_not_win_with_false) {
    Field app(10, 10, 9);

    ASSERT_FALSE(app.IsWin());
}

TEST(Field, Can_win_with_true) {
    Field app(10, 10, 9);

    for (int i = 0; i < 10; i++)
        for (int k = 0; k < 10; k++)
            if (!app[i][k].isBomb)
                app.OpenCurrentCell(i, k);

    ASSERT_TRUE(app.IsWin());
}

TEST(Field, Can_create_flag) {
    Field app(2, 2, 1);

    for (int i = -10; i < 10; i++)
        for (int k = -10; k < 10; k++)
            ASSERT_NO_THROW(app.MarkCell(k, i));
}

TEST(Field, Can_not_mark_nothing) {
    Field app(2, 2, 1);

    for (int i = -10; i < 10; i++)
        for (int k = -10; k < 10; k++)
            if (i != 0 && i != 1 && k != 0 && k != 1)
                ASSERT_FALSE(app.MarkCell(k, i));
}

TEST(Field, Can_create_flag_true) {
    Field app(2, 2, 1);

    ASSERT_TRUE(app.MarkCell(0, 0));
}

TEST(Field, Can_open_near_cell) {
    Field app(2, 2, 0);

    for (int i = 0; i < 2; i++)
        for (int k = 0; k < 2; k++)
            if (app[i][k].num == 0)
                ASSERT_NO_THROW(app.OpenNearCell(i, k));
}

TEST(Field, Can_open_all_near_to_zero) {
    Field app(10, 10, 1);

    for (int i = 0; i < 5; i++)
        for (int k = 0; k < 5; k++)
            if (app[i][k].num == 0)
                app.OpenNearCell(i, k);

    for (int i = 0; i < 5; i++)
        for (int k = 0; k < 5; k++)
            if (app[i][k].num == 0)
                ASSERT_NE(app[i][k].viewCell, '*');
}
