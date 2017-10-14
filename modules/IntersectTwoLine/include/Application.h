// Copyright 2017 Gorozhanin Mihail

#ifndef MODULES_INTERSECTTWOLINE_INCLUDE_APPLICATION_H_
#define MODULES_INTERSECTTWOLINE_INCLUDE_APPLICATION_H_

#include <string>
#include "include/line_segment.h"

class Application {
 public:
  Application();
  std::string operator()(int argc, const char** argv);

 private:
  void help(const char* appname, const char* message = "");
  bool ValidateNumberOfArguments(int argc, const char** argv);
  std::string message_;

  struct Segment_User {
    double X1U;
    double X2U;
    double Y1U;
    double Y2U;
  };

  struct Segment_True {
    double X1T;
    double X2T;
    double Y1T;
    double Y2T;
  };
};

#endif  // MODULES_INTERSECTTWOLINE_INCLUDE_APPLICATION_H_
