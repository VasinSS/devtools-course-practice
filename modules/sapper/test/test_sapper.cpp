// Copyright 2017 Fedorov Igor

#include <gtest/gtest.h>

#include<vector>
#include <string>

#include"include/saper.h"


TEST(Saper, Can_creat_obj_by_defult) {
    ASSERT_NO_THROW(Saper app);
}

TEST(Saper, Can_creat_obj_width_less_height) {
    ASSERT_NO_THROW(Saper app(10, 20, 10));
}

TEST(Saper, Can_creat_obj_height_less_width) {
    ASSERT_NO_THROW(Saper app(20, 10, 10));
}

TEST(Saper, Can_creat_obj_with_equal_size) {
    ASSERT_NO_THROW(Saper app(20, 20, 10));
}

TEST(Saper, throw_when_negative_width) {
    ASSERT_ANY_THROW(Saper app(-10, 20, 10));
}

TEST(Saper, throw_when_negative_hight) {
    ASSERT_ANY_THROW(Saper app(20, -20, 10));
}

TEST(Saper, throw_when_negative_size) {
    ASSERT_ANY_THROW(Saper app(-10, -20, 10));
}

TEST(Saper, throw_when_a_lot_bomb) {
    ASSERT_ANY_THROW(Saper app(20, 20, 1000));
}

TEST(Saper, Can_recognize_all_bomb) {
    Saper app;
    int count = 0;

    for (int i = 0; i < 10; i++)
        for (int k = 0; k < 10; k++)
            if (!app.TouchResult(i, k))
                count++;

    ASSERT_EQ(count, 10);
}


TEST(Saper, Can_help) {
    std::string output_;
    Saper app_;
    std::vector<const char*> args_ = { "appname", "0", "0", "0", "0", "0" };
    const char** argv = &args_.front();
    int argc = static_cast<int>(args_.size());

    std::string message_;
    message_ += "Wrong arguments!\n";
    message_ += "This is a simple saper application. Usage:\n";
    message_ += "\n    ";
    message_ += "appname";
    message_ += " <x> <y> <option>";
    message_ += "\n   <option> = 0 - touch cell. 1 - mark cell. 3 - exit. ";
    message_ += "2 - print the result";
    message_ += "\n    ";
    message_ += "appname";
    message_ += " <somth>";
    message_ += "\n        -- exit";
    message_ += "\n           a formal parameter is int ";
    message_ += "\n";

    ASSERT_EQ(message_, output_ = app_(argc, argv));
}

TEST(Saper, Can_touch_and_lose) {
    std::string output_;
    Saper app_(3, 3, 9);
    std::vector<const char*> args_ = {"appname", "1", "1", "1" };
    const char** argv = &args_.front();
    int argc = static_cast<int>(args_.size());

    output_ = app_(argc, argv);

    ASSERT_EQ("You lose\n", output_);
}

TEST(Saper, Can_touch_no_throw) {
    std::string output_;
    Saper app_(3, 3, 9);
    std::vector<const char*> args_ = { "appname", "1", "1", "1" };
    const char** argv = &args_.front();
    int argc = static_cast<int>(args_.size());

    output_ = app_(argc, argv);

    ASSERT_NO_THROW(output_ = app_(argc, argv));
}

TEST(Saper, Can_touch_and_win) {
    std::string output_;
    Saper app_(3, 3, 0);
    std::vector<const char*> args_ = { "appname", "1", "1", "1" };
    const char** argv = &args_.front();
    int argc = static_cast<int>(args_.size());

    output_ = app_(argc, argv);

    ASSERT_EQ("You win!\n", output_);
}

TEST(Saper, Can_touch_and_not_lose) {
    std::string output_;
    Saper app_(9, 9, 4);
    std::vector<const char*> args_ = { "appname", "0", "0", "1" };
    const char** argv = &args_.front();
    int argc = static_cast<int>(args_.size());

    output_ = app_(argc, argv);

    ASSERT_EQ("Good move!\n", output_);
}

TEST(Saper, Can_touch_nothing) {
    Saper app_;

    ASSERT_TRUE(app_.TouchResult(-1, 23));
}

TEST(Saper, Can_touch) {
    Saper app_(4, 4, 0);

    ASSERT_TRUE(app_.TouchResult(0, 0));
}

TEST(Saper, Can_touch_bomb) {
    Saper app_;
    int x = 0, y = 0;

    for (int k = 0; k < 10; k++) {
        for (int i = 0; i < 10; i++) {
            if (!app_.TouchResult(k, i)) {
                x = k;
                y = i;
                break;
            }
        }
        if (x != 0 && y != 0)
            break;
    }

    ASSERT_FALSE(app_.TouchResult(x, y));
}

TEST(Saper, Can_make_flag) {
    std::string output_;
    Saper app_;
    std::vector<const char*> args_ = {"appname", "0", "0", "0" };

    const char** argv = &args_.front();

    int argc = static_cast<int>(args_.size());

    output_ = app_(argc, argv);

    ASSERT_EQ("You make a flag!\n", output_);
}


TEST(Saper, Can_print) {
    std::string output_;
    Saper app_;
    std::vector<const char*> args_ = { "appname", "0", "0", "2" };
    const char** argv = &args_.front();
    int argc = static_cast<int>(args_.size());

    ASSERT_NO_THROW(output_ = app_(argc, argv));
}

TEST(Saper, Can_exit) {
    std::string output_;
    Saper app_(10, 10, 11);
    std::vector<const char*> args_ = { "appname", "0", "0", "3" };
    const char** argv = &args_.front();
    int argc = static_cast<int>(args_.size());
    output_ = app_(argc, argv);

    ASSERT_EQ("exit\n", output_);
}


TEST(Saper, Can_exit_by_1_args_) {
    std::string output_;
    Saper app_(10, 10, 11);
    std::vector<const char*> args_ = { "appname"};
    const char** argv = &args_.front();
    int argc = static_cast<int>(args_.size());
    output_ = app_(argc, argv);
    std::string message_;

    message_ += "exit\n";
    message_ += "This is a simple saper application. Usage:\n";
    message_ += "\n    ";
    message_ += "appname";
    message_ += " <x> <y> <option>";
    message_ += "\n   <option> = 0 - touch cell. 1 - mark cell. 3 - exit. ";
    message_ += "2 - print the result";
    message_ += "\n    ";
    message_ += "appname";
    message_ += " <somth>";
    message_ += "\n        -- exit";
    message_ += "\n           a formal parameter is int ";
    message_ += "\n";

    ASSERT_EQ(message_, output_);
}
