// Copyright 2017 Vasin Stanislav

#include <gtest/gtest.h>
#include "../include/minesweeperApp.h"
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <iterator>

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
