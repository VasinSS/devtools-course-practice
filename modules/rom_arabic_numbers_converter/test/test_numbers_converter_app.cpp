// Copyright 2017 Vinogradova Ekaterina

#include <gtest/gtest.h>

#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <iterator>

#include "include/numbers_converter_app.h"

using ::testing::internal::RE;
using std::vector;
using std::string;


class NumbersConverterTest : public ::testing::Test {
 protected:
    void Act(vector<string> args_) {
        vector<const char *> options;

        options.push_back("appname");
        for (size_t i = 0; i < args_.size(); ++i) {
            options.push_back(args_[i].c_str());
        }

        const char **argv = &options.front();
        int argc = static_cast<int>(args_.size()) + 1;

        output_ = app_(argc, argv);
    }

    void Assert(std::string expected) {
        EXPECT_TRUE(RE::PartialMatch(output_, RE(expected)));
    }

 private:
    Application app_;
    string output_;
};

TEST_F(NumbersConverterTest, Print_Help_Without_Arguments) {
    vector<string> args = {};

    Act(args);

    Assert("This is a converter of arabic and roman numbers application\\..*");
}

TEST_F(NumbersConverterTest, Checking_Number_Of_Arguments) {
    vector<string> args = { "120", "88" };

    Act(args);

    Assert("ERROR: Should be 1 argument\\..*");
}

TEST_F(NumbersConverterTest, Can_Convert_Arabic_Number) {
    vector<string> args = { "15" };

    Act(args);

    Assert("XV");
}

TEST_F(NumbersConverterTest, Can_Convert_Roman_Number) {
    vector<string> args = { "XV" };

    Act(args);

    Assert("15");
}

TEST_F(NumbersConverterTest, Can_Detect_Wrong_Roman_Number_Format) {
    vector<string> args = { "XAS" };

    Act(args);

    Assert("Wrong number format!");
}

TEST_F(NumbersConverterTest, Can_Detect_Wrong_Arabic_Number_Format) {
    vector<string> args = { "1oo" };

    Act(args);

    Assert("Wrong number format!");
}

TEST_F(NumbersConverterTest, Can_Detect_Negative_Arabic_Number) {
    vector<string> args = { "-13" };

    Act(args);

    Assert("Wrong number format!");
}

TEST_F(NumbersConverterTest, Can_Detect_Zero_Arabic_Number) {
    vector<string> args = { "0" };

    Act(args);

    Assert("The number can't be less than 1!");
}
