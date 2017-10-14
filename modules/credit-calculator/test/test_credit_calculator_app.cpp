// Copyright 2017 Yashkov Vladislav

#include <gtest/gtest.h>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <iterator>

#include "include/credit_calculator_app.h"

using ::testing::internal::RE;
using std::vector;
using std::string;

class CreditCalculatorAppTest : public ::testing::Test {
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
    Application app_;
    string output_;
};

TEST_F(CreditCalculatorAppTest, Do_Print_Help_Without_Arguments) {
    // Arrange
    vector<string> args = {};
    // Act
    Act(args);
    // Assert
    Assert("This is a credit calculator application*");
}

TEST_F(CreditCalculatorAppTest, Is_Checking_Number_Of_Arguments) {
    // Arrange
    vector<string> args = { "10000", "10"};
    // Act
    Act(args);
    // Assert
    Assert("ERROR: Incorrect arguments num.*");
}

TEST_F(CreditCalculatorAppTest, Can_Detect_Wrong_Number_Format) {
    // Arrange
    vector<string> args = { "10000", "12", "five", "5"};
    // Act
    Act(args);
    // Assert
    Assert("Wrong number format!*");
}

TEST_F(CreditCalculatorAppTest, Can_Calculate_Correct) {
    // Arrange
    vector<string> args = { "10000", "12", "5", "5"};
    // Act
    Act(args);
    // Assert
    Assert("Monthly Payment: 856.075*");
}
