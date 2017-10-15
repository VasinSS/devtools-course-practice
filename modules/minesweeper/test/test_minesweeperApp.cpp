// Copyright 2017 Vasin Stanislav

#include <gtest/gtest.h>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <iterator>

#include "../include/minesweeperApp.h"

using ::testing::internal::RE;
using std::vector;
using std::string;

class minesweeperAppTest : public ::testing::Test {
 protected:
    void Act(vector<string> args_) {
        vector<const char*> options;

        options.push_back("appname");
        for (size_t i = 0; i < args_.size(); ++i) {
            options.push_back(args_[i].c_str());
        }

        const char** argv = &options.front();
        int argc = static_cast<int>(args_.size()) + 1;

        output_ = app_(argc, argv);
    }

    void Assert(std::string expected) {
        EXPECT_TRUE(RE::PartialMatch(output_, RE(expected)));
    }

 private:
    minesweeperApp app_;
    string output_;
};

TEST_F(minesweeperAppTest, Do_Print_Help_Without_Arguments) {
    vector<string> args = {};

    Act(args);

    Assert("This is a method of minesweeper application\\..*");
}

TEST_F(minesweeperAppTest, Input_with_miss_some_args) {
    vector<string> args = {"10", "10", "5"};

    Act(args);

    Assert("Error: Should be 5 arguments\\..*");
}

TEST_F(minesweeperAppTest, Input_with_incorrect_args) {
    vector<string> args = {"x", "x", "x", "x", "x"};

    Act(args);

    Assert("Wrong input args format!\n");
}

TEST_F(minesweeperAppTest, Can_clic_on_area_without_mine) {
    vector<string> args = {"10", "10", "5", "9", "0"};

    Act(args);

    Assert("result: 0\n");
}

TEST_F(minesweeperAppTest, Can_clic_on_area_with_mine) {
    vector<string> args = {"10", "10", "5", "2", "0"};

    Act(args);

    Assert("result: 1\n");
}

TEST_F(minesweeperAppTest, Can_clic_on_cell_with_mine) {
    vector<string> args = {"10", "10", "5", "0", "0"};

    Act(args);

    Assert("result: 9\n");
}
