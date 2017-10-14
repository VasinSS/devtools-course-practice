// Copyright 2017 Yashkov Vladislav

#ifndef MODULES_CREDIT_CALCULATOR_INCLUDE_CREDIT_CALCULATOR_APP_H_
#define MODULES_CREDIT_CALCULATOR_INCLUDE_CREDIT_CALCULATOR_APP_H_

#include "include/credit_calculator.h"
#include <string>

class Application {
 public:
    Application();
    std::string operator()(int argc, const char** argv);

 private:
    void Help(const char* appname, const char* message = "");
    bool ValidateNumberOfArguments(int argc, const char** argv);
    struct Arguments{
        int amount;
        int period;
        double interest;
        int month_pas;
    };
    std::string message_;
};

#endif  // MODULES_CREDIT_CALCULATOR_INCLUDE_CREDIT_CALCULATOR_APP_H_
