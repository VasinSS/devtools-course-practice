// Copyright 2017 Fedorov Igor

#include <gtest/gtest.h>
#include"include/field.h"

TEST(Field, Can_print_in_console_open_map) {
    Field app(10, 10, 10);

    for (int i = 0; i < 10; i++)
        for (int k = 0; k < 10; k++)
            if (!app[i][k].isBomb)
                app.OpenCurrentCell(i, k);

    ASSERT_NO_THROW(app.PrintField());
}

TEST(Field, Print_not_change_obj) {
    Field app(10,10,0);

    app.PrintField();

    for (int i = 0; i < 10; i++)
        for (int k = 0; k < 10; k++)
            ASSERT_EQ(app[i][k].viewCell, '*');
}

TEST(Field, Can_print_in_console) {
    Field app(10, 10, 10);

    ASSERT_NO_THROW(app.PrintField());
}

TEST(Field, Cant_open_wrong_cur_cell) {
    Field app(10, 10, 10);

    ASSERT_FALSE(app.OpenCurrentCell(1000, 10000));
}

TEST(Field, Cant_open_wrong_cur_cell1) {
    Field app(10, 10, 10);

    ASSERT_FALSE(app.OpenCurrentCell(-1000, -10000));
}

TEST(Field, Can_open_cur_cell) {
    Field app(10, 10, 0);

    ASSERT_TRUE(app.OpenCurrentCell(1, 1));
}

TEST(Field, Can_win) {
    Field app;

    for (int i = 0; i < 10; i++)
        for (int k = 0; k < 10; k++)
            if (!app[i][k].isBomb)
                app.OpenCurrentCell(i, k);

    ASSERT_TRUE(app.IsWin());
}

TEST(Field, Can_not_win) {
    Field app;

    ASSERT_FALSE(app.IsWin());
}

TEST(Field, Win_no_throw) {
    Field app;

    for (int i = 0; i < 10; i++)
        for (int k = 0; k < 10; k++)
            if (!app[i][k].isBomb)
                app.OpenCurrentCell(i, k);

    ASSERT_NO_THROW(app.IsWin());
}

TEST(Field, no_win_no_throw) {
    Field app;

    ASSERT_NO_THROW(app.IsWin());
}

TEST(Field, Can_mark_all) {
    Field app;

    for (int i = 0; i < 10; i++)
        for (int k = 0; k < 10; k++)
            app.MarkCell(i, k);

    for (int i = 0; i < 10; i++)
        for (int k = 0; k < 10; k++)
            ASSERT_EQ(app[i][k].viewCell,'!');
}

TEST(Field, Can_mark) {
    Field app;

    ASSERT_TRUE(app.MarkCell(0, 0));
    ASSERT_EQ(app[0][0].viewCell, '!');
}

TEST(Field, Cannt_mark) {
    Field app;

    ASSERT_FALSE(app.MarkCell(-20, 200));
}

TEST(Field, Cannt_mark1) {
    Field app;

    ASSERT_FALSE(app.MarkCell(2013, -200));
}

TEST(Field, Can_open_near_cell) {
    Field app(10, 10, 10);
    for (int k = 0; k < 10; k++) {
        for (int i = 0; i < 10; i++) {
            if (app[i][k].num == 0) {
                ASSERT_NO_THROW(app.OpenNearCell(i, k));
            }
        }
    }
}

TEST(Field, Open_near_cell_print) {
    Field app(10, 10, 10);
    
    for (int k = 0; k < 10; k++)
        for (int i = 0; i < 10; i++)
            if (app[i][k].num == 0)
                app.OpenNearCell(i, k);
    app.PrintField();
    
    for (int k = 0; k < 10; k++)
        for (int i = 0; i < 10; i++)
            if (app[i][k].num == 0)
                ASSERT_EQ(app[i][k].viewCell, '0');
}


TEST(Field, Can_delet) {
    Field* app_ = new Field();

    ASSERT_NO_THROW(app_->~Field());
}

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

TEST(Field, braket_work) {
    Field app;

    for (int k = 0; k < 10; k++)
        for (int i = 0; i < 10; i++)
            ASSERT_NE(&app[i][k], nullptr);
}

TEST(Field, braket_work_well) {
    Field app;

    for (int k = 0; k < 10; k++)
        for (int i = 0; i < 10; i++)
            app[i][k].isBomb = true;

    for (int k = 0; k < 10; k++)
        for (int i = 0; i < 10; i++)
            ASSERT_EQ(app[i][k].isBomb, true);
}
