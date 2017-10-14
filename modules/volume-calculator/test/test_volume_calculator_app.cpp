// Copyright 2017 Kochin Ivan

#include <gtest/gtest.h>

#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <iterator>

#include "include/volume_calculator_app.h"

using ::testing::internal::RE;
using std::vector;
using std::string;

class VolumeCalculatorTest : public ::testing::Test {
 protected:
    // virtual void SetUp() {}

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
    VolumeCalculator app_;
    string output_;
};

TEST_F(VolumeCalculatorTest, Do_Print_Help_Without_Arguments) {
    vector<string> args = {};

    Act(args);

    Assert("This is a volume 3d figure calculator application\\..*");
}

TEST_F(VolumeCalculatorTest, Can_Detect_Wrong_Type_Format) {
    vector<string> args = { "3.22", "3.22"};

    Act(args);

    Assert("Type must be integer");
}

TEST_F(VolumeCalculatorTest, Can_Detect_Wrong_Argument_Format) {
    vector<string> args = { "1", "e" };

    Act(args);

    Assert("Wrong number format!");
}

TEST_F(VolumeCalculatorTest, Can_Detect_Negative_Argument_Format) {
    vector<string> args = { "1", "-1" };

    Act(args);

    Assert("Wrong number format!");
}

TEST_F(VolumeCalculatorTest, Is_Checking_Number_Of_Arguments_Of_Type_1) {
    vector<string> args = { "1", "1", "1", "1", "1", "1", "1", "1", "1" };

    Act(args);

    Assert("ERROR: Should be 1 arguments\\..*");
}

TEST_F(VolumeCalculatorTest, Is_Checking_Number_Of_Arguments_Of_Type_2) {
    vector<string> args = { "2", "1", "1", "1", "1", "1", "1", "1", "1" };

    Act(args);

    Assert("ERROR: Should be 1 arguments\\..*");
}

TEST_F(VolumeCalculatorTest, Is_Checking_Number_Of_Arguments_Of_Type_3) {
    vector<string> args = { "3", "1", "1", "1", "1", "1", "1", "1", "1" };

    Act(args);

    Assert("ERROR: Should be 2 arguments\\..*");
}

TEST_F(VolumeCalculatorTest, Is_Checking_Number_Of_Arguments_Of_Type_4) {
    vector<string> args = { "4", "1", "1", "1", "1", "1", "1", "1", "1" };

    Act(args);

    Assert("ERROR: Should be 2 arguments\\..*");
}

TEST_F(VolumeCalculatorTest, Is_Checking_Number_Of_Arguments_Of_Type_5) {
    vector<string> args = { "5", "1", "1", "1", "1", "1", "1", "1", "1" };

    Act(args);

    Assert("ERROR: Should be 3 arguments\\..*");
}

TEST_F(VolumeCalculatorTest, Is_Checking_Number_Of_Arguments_Of_Type_6) {
    vector<string> args = { "6", "1", "1", "1", "1", "1", "1", "1", "1" };

    Act(args);

    Assert("ERROR: Should be 4 arguments\\..*");
}

TEST_F(VolumeCalculatorTest, Is_Checking_Number_Of_Arguments_Of_Type_7) {
    vector<string> args = { "7", "1", "1", "1", "1", "1", "1", "1", "1" };

    Act(args);

    Assert("ERROR: Should be 2 arguments\\..*");
}

TEST_F(VolumeCalculatorTest, Is_Checking_Number_Of_Arguments_Of_Type_8) {
    vector<string> args = { "8", "1", "1", "1", "1", "1", "1", "1", "1" };

    Act(args);

    Assert("ERROR: Should be 3 arguments\\..*");
}

TEST_F(VolumeCalculatorTest, Is_Checking_Number_Of_Arguments_Of_Type_9) {
    vector<string> args = { "9", "1", "1", "1", "1", "1", "1", "1", "1" };

    Act(args);

    Assert("ERROR: Should be 2 arguments\\..*");
}

TEST_F(VolumeCalculatorTest, Is_Checking_Number_Of_Arguments_Of_Type_10) {
    vector<string> args = { "10", "1", "1", "1", "1", "1", "1", "1", "1" };

    Act(args);

    Assert("ERROR: Should be 1 arguments\\..*");
}

TEST_F(VolumeCalculatorTest, Is_Checking_Number_Of_Arguments_Of_Type_11) {
    vector<string> args = { "11", "1", "1", "1", "1", "1", "1", "1", "1" };

    Act(args);

    Assert("ERROR: Should be 3 arguments\\..*");
}

TEST_F(VolumeCalculatorTest, Is_Checking_Number_Of_Arguments_Of_Type_12) {
    vector<string> args = { "12", "1", "1", "1", "1", "1", "1", "1", "1" };

    Act(args);

    Assert("ERROR: Should be 2 arguments\\..*");
}

TEST_F(VolumeCalculatorTest, Is_Checking_Number_Of_Arguments_Of_Type_13) {
    vector<string> args = { "13", "1", "1", "1", "1", "1", "1", "1", "1" };

    Act(args);

    Assert("ERROR: Should be 3 arguments\\..*");
}

TEST_F(VolumeCalculatorTest, Is_Checking_Number_Of_Arguments_Of_Type_14) {
    vector<string> args = { "14", "1", "1", "1", "1", "1", "1", "1", "1" };

    Act(args);

    Assert("ERROR: Should be 3 arguments\\..*");
}

TEST_F(VolumeCalculatorTest, Is_Checking_Number_Of_Arguments_Of_Invalid_type) {
    vector<string> args = { "18", "1", "1", "1", "1", "1", "1", "1", "1" };

    Act(args);

    Assert("Incorrect type\\..*");
}

TEST_F(VolumeCalculatorTest, Can_Calculate_Volume_Of_Type_1) {
    vector<string> args = { "1", "3" };

    Act(args);

    Assert("Volume = 27");
}

TEST_F(VolumeCalculatorTest, Can_Calculate_Volume_Of_Type_2) {
    vector<string> args = { "2", "3" };

    Act(args);

    Assert("Volume = 206.904");
}

TEST_F(VolumeCalculatorTest, Can_Calculate_Volume_Of_Type_3) {
    vector<string> args = { "3", "3", "3" };

    Act(args);

    Assert("Volume = 84.823");
}

TEST_F(VolumeCalculatorTest, Can_Calculate_Volume_Of_Type_4) {
    vector<string> args = { "4", "3", "3" };

    Act(args);

    Assert("Volume = 9");
}

TEST_F(VolumeCalculatorTest, Can_Calculate_Volume_Of_Type_5) {
    vector<string> args = { "5", "3", "3", "2" };

    Act(args);

    Assert("Volume = 18");
}

TEST_F(VolumeCalculatorTest, Can_Calculate_Volume_Of_Type_6) {
    vector<string> args = { "6", "3", "5", "2", "3" };

    Act(args);

    Assert("Volume = 4.2336");
}

TEST_F(VolumeCalculatorTest, Can_Calculate_Volume_Of_Type_7) {
    vector<string> args = { "7", "3", "2" };

    Act(args);

    Assert("Volume = 2");
}

TEST_F(VolumeCalculatorTest, Can_Calculate_Volume_Of_Type_8) {
    vector<string> args = { "8", "3", "2", "3" };

    Act(args);

    Assert("Volume = 3");
}

TEST_F(VolumeCalculatorTest, Can_Calculate_Volume_Of_Type_9) {
    vector<string> args = { "9", "3", "2" };

    Act(args);

    Assert("Volume = 12.5664");
}

TEST_F(VolumeCalculatorTest, Can_Calculate_Volume_Of_Type_10) {
    vector<string> args = { "10", "3" };

    Act(args);

    Assert("Volume = 84.823");
}

TEST_F(VolumeCalculatorTest, Can_Calculate_Volume_Of_Type_11) {
    vector<string> args = { "11", "3", "2", "5" };

    Act(args);

    Assert("Volume = 94.2478");
}

TEST_F(VolumeCalculatorTest, Can_Calculate_Volume_Of_Type_12) {
    vector<string> args = { "12", "3", "2" };

    Act(args);

    Assert("Volume = 18.8496");
}

TEST_F(VolumeCalculatorTest, Can_Calculate_Volume_Of_Type_13) {
    vector<string> args = { "13", "3", "2", "5" };

    Act(args);

    Assert("Volume = 30");
}

TEST_F(VolumeCalculatorTest, Can_Calculate_Volume_Of_Type_14) {
    vector<string> args = { "14", "3", "2", "5" };

    Act(args);

    Assert("Volume = 99.4838");
}
