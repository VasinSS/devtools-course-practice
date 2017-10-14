// Copyright 2017 Vinogradova Ekaterina

#ifndef MODULES_ROM_ARABIC_NUMBERS_CONVERTER_INCLUDE_NUMBERS_CONVERTER_APP_H_
#define MODULES_ROM_ARABIC_NUMBERS_CONVERTER_INCLUDE_NUMBERS_CONVERTER_APP_H_

#include <string>

enum NumberType { Arabic, Roman };

class Application {
 public:
    Application();
    std::string operator()(int argc, const char** argv);

 private:
    void help(const char* appname, const char* message = "");
    bool validateNumberOfArguments(int argc, const char** argv);
    std::string message_;
    typedef struct {
        int arabic_number;
        std::string roman_number;
        NumberType flag;
    } Arguments;
};

#endif  // MODULES_ROM_ARABIC_NUMBERS_CONVERTER_INCLUDE_NUMBERS_CONVERTER_APP_H_
