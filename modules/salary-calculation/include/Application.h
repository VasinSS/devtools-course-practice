// Copyright 2017 Kiselev Ivan

#ifndef MODULES_SALARY_CALCULATION_INCLUDE_APPLICATION_H_
#define MODULES_SALARY_CALCULATION_INCLUDE_APPLICATION_H_

#include <string>
#include "include/salary_calculation.h"

class Application {
 public:
    Application();
    int operator()(int argv, const char** argc);

 private:
     Salary* worker_salary_;
};

#endif  // MODULES_SALARY_CALCULATION_INCLUDE_APPLICATION_H_
