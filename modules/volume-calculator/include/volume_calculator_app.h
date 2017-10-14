// Copyright 2017 Kochin Ivan

#ifndef MODULES_VOLUME_CALCULATOR_INCLUDE_VOLUME_CALCULATOR_APP_H_
#define MODULES_VOLUME_CALCULATOR_INCLUDE_VOLUME_CALCULATOR_APP_H_

#include <string>

class VolumeCalculator {
 public:
    VolumeCalculator();
    std::string operator()(int argc, const char** argv);

 private:
    void help(const char* appname, const char* message = "");
    bool validateNumberOfArguments(int argc, const char** argv);
    std::string message_;
};

#endif  // MODULES_VOLUME_CALCULATOR_INCLUDE_VOLUME_CALCULATOR_APP_H_
