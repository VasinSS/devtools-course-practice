// Copyright 2017 Gorozhanin Mihail

#include <gtest/gtest.h>

#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <iterator>

#include "include/Application.h"

using ::testing::internal::RE;
using std::vector;
using std::string;

class ApplicationTest : public ::testing::Test {
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

TEST_F(ApplicationTest, Do_Print_Help) {
  // Arrange
  vector<string> args = {};
  // Act
  Act(args);
  // Assert
  Assert(
    "This application is to determine whether the segments that intersect*");
}

TEST_F(ApplicationTest, Can_Detect_Wrong_Number_Format) {
  // Arrange
  vector<string> args = { "3", "8" };
  // Act
  Act(args);
  // Assert
  Assert("ERROR: Should be 8 arguments.");
}

TEST_F(ApplicationTest, Can_Detect_Wrong_Initial_Value) {
  // Arrange
  vector<string> args = { "22", "f", "o", "u", "r", "ele", "ven", "KK" };
  // Act
  Act(args);
  // Assert
  Assert("ERROR: Incorrect coordinate!*");
}

TEST_F(ApplicationTest, Can_Find_Out_The_Parallelism) {
  // Arrange
  vector<string> args = { "0", "0", "2", "2", "0", "1", "2", "3"};
  // Act
  Act(args);
  // Assert
  Assert("Segments are parallel*");
}
/*
TEST_F(ApplicationTest, Can_Find_The_Absence_Of_Crossings) {
  // Arrange
  vector<string> args = { "-2", "-2", "2", "2", "1", "4", "2", "3" };
  // Act
  Act(args);
  // Assert
  Assert("Intersection point: (2.5;2.5)*");
}
*/
TEST_F(ApplicationTest, Can_Check_Segments_For_Coincide) {
  // Arrange
  vector<string> args = { "-4", "-2", "-2", "0", "-1", "1", "2", "4" };
  // Act
  Act(args);
  // Assert
  Assert("The segments are on the same line*");
}
