// Copyright 2017 Fedorov Igor

#ifndef MODULES_SAPPER_INCLUDE_SAPER_H_
#define MODULES_SAPPER_INCLUDE_SAPER_H_

#include <string>
#include<iostream>
#include"../include/field.h"

class Saper {
 public:
    explicit Saper(int wth = 10, int hght = 10, int countbomb = 10);
    bool TouchResult(int x_, int y_);
    std::string operator()(int argc, const char** argv);
 private:
    bool validateNumberOfArguments(int argc, const char** argv);
    void PrintHelp(const char *appname);
    std::string message_;
    Field *field_;
    typedef struct {
        int x;
        int y;
        int choose;
    } Arguments;
    Arguments args_;
};

#endif  // MODULES_SAPPER_INCLUDE_SAPER_H_
